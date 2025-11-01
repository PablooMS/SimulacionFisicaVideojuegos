#include "GScene.h"
#include "Wind.h"
#include "Torbellino.h"
#include "Explosive.h"

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
	/*_forces.push_back(new Torbellino(gPhysx, 2, 0.5, 0));
	Particle* f = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 0.95, gPhysx, 10, 5, 1, { 0.3, 0.3, 0.3, 1.0 });
	f->setRender(false);
	Initialization str = { {0,0,0}, {0,0,0}, 8 };
	Initialization vr = { {20,100,20}, {0,0,0}, 1 };
	_entMan->createGenerator(f, str, vr, 20, 0.15, false);*/

	//Torbellino localizado
	/*_forces.push_back(new Torbellino(gPhysx, 2, 0.5, 0, {80, 100, -80}, SPHERE, 100, 100, true));
	Particle* f = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 0.95, gPhysx, 10, 5, 1, { 0.3, 0.3, 0.3, 1.0 });
	f->setRender(false);
	Initialization str = { {80,100,-80}, {0,0,0}, 8 };
	Initialization vr = { {20,95,20}, {0,0,0}, 1 };
	_entMan->createGenerator(f, str, vr, 20, 0.15, false);*/

	//Explosion
	_forces.push_back(new Explosive(gPhysx, { 50, 0, -30 }, 200, 0.25, 100));
	Particle* f = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 0.95, gPhysx, 100, 5, 1, { 1, 0.3, 0.3, 1.0 });
	f->setRender(false);
	Initialization str = { {50,10,-30}, {0,-1,0}, 8 };
	Initialization vr = { {20,0,20}, {0,0,0}, 1 };
	_entMan->createGenerator(f, str, vr, 150, 1, true);
}
