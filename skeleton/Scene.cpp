#include "Scene.h"
#include <iostream>

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
	updateForces(t);
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

void Scene::handleEvent(SceneEvents evt)
{
	//std::cout << "handling event ";
	switch (evt)
	{
	case Explode:
		//std::cout << "exploding\n";
		for (forceIterator a = _forces.begin(); a != _forces.end(); ++a)
			(*a)->handleEvent(ForceEvents::Explosion);
		break;
	default:
		break;
	}
}

void Scene::updateForces(double t)
{
	//std::cout << "forces: " << _forces.size() << std::endl;
	for (forceIterator a = _forces.begin(); a != _forces.end(); ++a)
	{
		(*a)->updateTime(t);
		_entMan->applyForce((*a), t);
	}
}
