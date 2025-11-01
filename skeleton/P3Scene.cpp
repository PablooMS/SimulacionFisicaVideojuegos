#include "P3Scene.h"
#include <PxPhysics.h>
#include <PxPhysicsAPI.h>
#include "Torbellino.h"

void P3Scene::loadScene()
{
	physx::PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	//Suelo y mapa
	physx::PxShape* suelo = gPhysx->createShape(physx::PxBoxGeometry(50, 1, 150), *gMaterial);
	Vector3D pos(50, -5, -75);
	physx::PxTransform* floTrans = new physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()));
	Vector4 color(0.5, 1.0, 0.0, 1.0);
	RenderItem* rend = new RenderItem(suelo, floTrans, color);
	RegisterRenderItem(rend);

	Vector4 color2(0.8, 0.3, 1.0, 1.0);
	/*_entMan->createParticle({20, 3, -10}, {0, 0, 0}, {0, 0, 0}, -1, 5, color2);
	_entMan->createParticle({ 80, 5, -50 }, { 0, 0, 0 }, { 0, 0, 0 }, -1, 5, color2);
	_entMan->createParticle({ 50, 5, -120 }, { 0, 0, 0 }, { 0, 0, 0 }, -1, 5, color2);*/

	//Torbellino local
	/*_forces.push_back(new Torbellino(gPhysx, -2, 0.02, 0, {40, 80, -40}, SPHERE, 100, 100, true));
	Particle* f = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 0.95, gPhysx, 1000, 5, 0.3, { 0.3, 0.3, 0.3, 1.0 });
	f->setRender(false);
	Initialization str = { {40,80,-40}, {0,0,0}, 8 };
	Initialization vr = { {20,80,20}, {0,0,0}, 1 };
	_entMan->createGenerator(f, str, vr, 20, 0.15, false);*/

	//Torbellino global
	_forces.push_back(new Torbellino(gPhysx, 10, 0.01, 0));
	Particle* f = new Particle({0,0,0}, {0,0,0}, {0,0,0}, 0.95, gPhysx, 1000, 5, 0.3, {0.3, 0.3, 0.3, 1.0});
	f->setRender(false);
	Initialization str = { {0,0,0}, {0,0,0}, 8 };
	Initialization vr = { {20,100,20}, {0,0,0}, 1 };
	_entMan->createGenerator(f, str, vr, 20, 0.15, false);
}
