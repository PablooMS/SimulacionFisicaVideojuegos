#include "Level.h"

void Level::loadScene()
{
	cam->setLocked(true);

	gun = new Explosive(gPhysx, { 0, 0, 0 }, 1, 0.2, 1000);
	_forces.push_back(gun);

	mSho = new ShootingComponent(gun, cam, 10, 9000, 0.1, 0.5);
}

void Level::update(double t)
{
	Scene::update(t);

	mSho->update(t);

	if (enem == 0)
		change = true;
}

void Level::handleEvent(SceneEvents evt)
{
	Scene::handleEvent(evt);

	if (evt == Shoot)
		mSho->shoot();
}

void Level::unloadScene()
{
	Scene::unloadScene();

	delete mSho;
	mSho = nullptr;

	cam->setLocked(false);
}
