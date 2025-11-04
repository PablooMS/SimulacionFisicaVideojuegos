#include "LobbyScene.h"
#include "Constants.h"
#include <random>

void LobbyScene::loadScene()
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

	//Lluvia
	Particle* r = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 0.95, gPhysx, 1000, 10, 1, { 0.1, 0.1, 0.6, 1.0 });
	r->setRender(false);
	Initialization str = { {0,600,0}, {5,-100,0}, 10 };
	Initialization vr = { {1000,0,1000}, {1,0,1}, 0 };
	_entMan->createGenerator(r, str, vr, 100, 0.1, false);
}

void LobbyScene::unloadScene()
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
