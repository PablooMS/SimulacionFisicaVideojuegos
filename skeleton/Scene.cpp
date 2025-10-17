#include "Scene.h"

Scene::Scene(physx::PxPhysics* physx) : gPhysx(physx)
{
	_entMan = new EntityManager(physx);
}

Scene::~Scene()
{
	delete _entMan;
	_entMan = nullptr;
}

void Scene::update(double t)
{
	_entMan->update(t);
}

void Scene::loadScene()
{

}

void Scene::unloadScene()
{
	_entMan->clearEnts();
}
