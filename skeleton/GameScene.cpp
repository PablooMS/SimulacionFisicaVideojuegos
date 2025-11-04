#include "GameScene.h"
#include <random>
#include "Constants.h"
#include "Torbellino.h"
#include "Explosive.h"

void GameScene::loadScene()
{
	physx::PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	physx::PxShape* suelo = gPhysx->createShape(physx::PxBoxGeometry(1000, 1, 1000), *gMaterial);
	Vector3D pos(0, 0, 0);
	floorT = new physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()));
	Vector4 color(0.5, 1.0, 0.0, 1.0);
	floor = new RenderItem(suelo, floorT, color);
	//RegisterRenderItem(rend);

	Vector4 buildGrey(0.5, 0.7, 0.6, 1.0);

	std::random_device rd{};
	std::normal_distribution<double> _u{ 0,1 };
	std::mt19937 _mtseed(rd());

	physx::PxShape* build = gPhysx->createShape(physx::PxBoxGeometry(40, 120, 40), *gMaterial);

	for (int i = 0; i < Constants::buildNum; i++)
	{
		buildT.push_back(new physx::PxTransform(physx::PxVec3(-200 + 10 * _u(_mtseed), 30 + 10 * _u(_mtseed), -i * 200 + 10 * _u(_mtseed))));
		buildings.push_back(new RenderItem(build, buildT[2 * i], buildGrey));

		buildT.push_back(new physx::PxTransform(physx::PxVec3(200 + 30 * _u(_mtseed), 30 + 10 * _u(_mtseed), -i * 200 + 20 * _u(_mtseed))));
		buildings.push_back(new RenderItem(build, buildT[2 * i + 1], buildGrey));
	}

	//Torbellino
	_forces.push_back(new Torbellino(gPhysx, -2, 0.02, 0, { 40, 80, -40 }, SPHERE, 100, 100, true));
	Particle* f = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 0.95, gPhysx, 1000, 5, 0.3, { 0.3, 0.3, 0.3, 1.0 });
	f->setRender(false);
	Initialization str = { {40,80,-40}, {0,0,0}, 8 };
	Initialization vr = { {20,80,20}, {0,0,0}, 1 };
	_entMan->createGenerator(f, str, vr, 20, 0.15, false);

	//Explosion
	_forces.push_back(new Explosive(gPhysx, { -100, 0, -250 }, 200, 0.25, 100));
	Particle* bomb = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,-9.8,0 }, 0.95, gPhysx, 100, 5, 1, { 1, 0.3, 0.3, 1.0 });
	bomb->setRender(false);
	Initialization str2 = { {-100,20,-250}, {0,0,0}, 8 };
	Initialization vr2 = { {2,2,2}, {5,1,5}, 1 };
	_entMan->createGenerator(bomb, str2, vr2, 50, 1, true);
}

void GameScene::unloadScene()
{
	_entMan->clearEnts();
	while (!_forces.empty())
	{
		delete _forces.front();
		_forces.pop_front();
	}

	DeregisterRenderItem(floor);
	delete floorT;
	floorT = nullptr;

	for (int i = 0; i < buildings.size(); i++)
	{
		delete buildT[i];
		DeregisterRenderItem(buildings[i]);
	}

	buildT.clear();
	buildings.clear();
}
