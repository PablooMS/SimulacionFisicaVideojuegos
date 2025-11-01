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
	updateForces();
	_entMan->update(t);
}

void Scene::loadScene()
{

}

void Scene::unloadScene()
{
	_entMan->clearEnts();
	while (!_forces.empty())
	{
		delete _forces.front();
		_forces.pop_front();
	}

}

void Scene::updateForces()
{
	for (forceIterator a = _forces.begin(); a != _forces.end(); ++a)
	{
		_entMan->applyForce((*a));
	}
}
