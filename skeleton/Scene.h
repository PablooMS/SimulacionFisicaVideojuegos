#pragma once
#include <PxPhysicsAPI.h>
#include "EntityManager.h"
#include "ForceGen.h"

using forceIterator = std::list<ForceGen*>::iterator;

enum SceneEvents { Explode };

class Scene
{
public:

	Scene(physx::PxPhysics* physx);
	~Scene();

	void update(double t);

	virtual void loadScene();
	bool changeable() {	return change; }
	std::string nextScene() { return next; }
	void unloadScene();

	EntityManager* sceneEntManager() { return _entMan; }

	void handleEvent(SceneEvents evt);

protected:

	void updateForces(double t);

	bool change;
	std::string next;

	physx::PxPhysics* gPhysx;
	EntityManager* _entMan;

	std::list<ForceGen*> _forces;
};

