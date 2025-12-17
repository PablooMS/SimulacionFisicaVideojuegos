#include "Level.h"
#include <iostream>

void Level::loadScene()
{
	cam->setLocked(true);

	gun = new Explosive(gPhysx, { 0, 0, 0 }, 3, 0.2, 7000);
	_forces.push_back(gun);

	mSho = new ShootingComponent(_entMan, gun, cam, 10, 9000, 0.7, 0.5);
}

void Level::update(double t)
{
	Scene::update(t);

	mSho->update(t);

	if (enem == 0)
		fireworks();
	else if (enem < 0)
		time -= t;

	if (time <= 0)
		change = true;
}

void Level::handleEvent(SceneEvents evt)
{
	Scene::handleEvent(evt);

	if (evt == Shoot)
		mSho->shoot();
}

void Level::fireworks()
{
	enem--;

	//Create and register ending fireworks

	Particle* model = new Particle(Vector3D(0, 0, 0), Vector3D(0, 0, 0), Vector3D(0, 0, 0), 0.9, gPhysx,
		100, 3, 0.2, { 1, 0.9, 0.5, 1 });
	model->setRender(false);
	Initialization stfw = { {0,0,0}, {0,0,0}, 0.5 };
	Initialization vfw = { {0,0,0}, {10,10,10}, 0.1 };
	Initialization ist = { {20,0,0}, {0,70,0}, 0.4 };
	Initialization iv = { {0,0,0}, {1,0.5,1}, 0.05 };
	_entMan->createFireworks(model, stfw, vfw, 3, 1, true, ist, iv, 3);

	Particle* model2 = new Particle(model);
	model2->setRender(false);
	Initialization ist2 = { {-20,0,0}, {0,70,0}, 0.4 };
	_entMan->createFireworks(model2, stfw, vfw, 3, 1, true, ist2, iv, 3);
}

void Level::unloadScene()
{
	Scene::unloadScene();

	delete mSho;
	mSho = nullptr;

	cam->setLocked(false);
}
