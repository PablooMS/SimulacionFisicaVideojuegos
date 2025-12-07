#include "Level.h"

void Level::loadScene()
{
	cam->setLocked(true);
}

void Level::update(double t)
{
	Scene::update(t);

	if (enem == 0)
		change = true;
}

void Level::unloadScene()
{
	Scene::unloadScene();

	cam->setLocked(false);
}
