#include "GScene.h"
#include "Wind.h"
#include "Torbellino.h"

void GScene::loadScene()
{
	physx::PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	// Grav Spheres
	/*
	_entMan->createProjectile({ 20, 5, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0.1, 10, 5, { 0.8, 0.3, 1.0, 1.0 });
	_entMan->createProjectile({ 50, 5, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0.2, 10, 5, { 0.8, 0.3, 1.0, 1.0 });
	_entMan->createProjectile({ 80, 5, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0.33, 10, 5, { 0.8, 0.3, 1.0, 1.0 });
	*/

	// Wind Spheres
	_entMan->createProjectile({ 40, 5, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 1, 15, 5, { 0.8, 0.3, 1.0, 1.0 });
	_entMan->createProjectile({ 40, 30, 0 }, { -30, 0, 0 }, { 0, 0, 0 }, 1, 15, 5, { 0.8, 0.3, 1.0, 1.0 });
	_entMan->createProjectile({ 40, 55, 0 }, { -80, 0, 0 }, { 0, 0, 0 }, 1, 15, 5, { 0.8, 0.3, 1.0, 1.0 });

	//Gravedad
	//_forces.push_back(new ForceGen({ 0, -100, 0 }));
	 
	// Viento Global
	//_forces.push_back(new Wind({ 20, 0, 0 }, gPhysx, 0.5, 0));

	//Viento en esferas
	//_forces.push_back(new Wind({ 50, 0, 0 }, gPhysx, 0.5, 0, {0, 30, 0}, SPHERE, 50, 100, true));
	//_forces.push_back(new Wind({ -50, 0, 0 }, gPhysx, 0.5, 0, {100, 30, 0}, SPHERE, 50, 100, true));

	//Torbellino global
	_forces.push_back(new Torbellino(gPhysx, 1, 0.5, 0));
	Particle* f = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 0.95, gPhysx, 10, 5, 1, { 0.3, 0.3, 0.3, 1.0 });
	Initialization str = { {0,0,0}, {0,0,0}, 10 };
	Initialization vr = { {20,150,20}, {0,0,0}, 1 };
	_entMan->createGenerator(f, str, vr, 10, 0.2, false);
}
