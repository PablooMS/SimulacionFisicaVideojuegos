#include "GScene.h"
#include "Wind.h"

void GScene::loadScene()
{
	physx::PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	// Grav Spheres
	/*
	_entMan->createProjectile({ 20, 5, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 10, 10, 5, { 0.8, 0.3, 1.0, 1.0 });
	_entMan->createProjectile({ 50, 5, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 5, 10, 5, { 0.8, 0.3, 1.0, 1.0 });
	_entMan->createProjectile({ 80, 5, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 3, 10, 5, { 0.8, 0.3, 1.0, 1.0 });
	*/

	// Wind Spheres
	_entMan->createProjectile({ 40, 5, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 1, 10, 5, { 0.8, 0.3, 1.0, 1.0 });
	_entMan->createProjectile({ 40, 30, 0 }, { -30, 0, 0 }, { 0, 0, 0 }, 1, 10, 5, { 0.8, 0.3, 1.0, 1.0 });
	_entMan->createProjectile({ 40, 55, 0 }, { -80, 0, 0 }, { 0, 0, 0 }, 1, 10, 5, { 0.8, 0.3, 1.0, 1.0 });

	//_forces.push_back(new ForceGen({ 0, -100, 0 }));
	_forces.push_back(new Wind({ 20, 0, 0 }, 0.5, 0));
}
