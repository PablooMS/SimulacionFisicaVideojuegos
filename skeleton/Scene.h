#pragma once
#include <PxPhysicsAPI.h>
#include "EntityManager.h"
#include "ForceGen.h"

using forceIterator = std::list<ForceGen*>::iterator;

enum SceneEvents { Explode, Shoot };

class Scene
{
public:

	Scene(physx::PxPhysics* physx, physx::PxScene* pxsc);
	~Scene();

	virtual void update(double t);

	virtual void loadScene();
	bool changeable() {	return change; }
	std::string nextScene() { return next; }
	virtual void unloadScene();

	EntityManager* sceneEntManager() { return _entMan; }

	virtual void handleEvent(SceneEvents evt);

protected:

	void updateForces(double t);

	bool change = false;
	std::string next;

	physx::PxPhysics* gPhysx;
	physx::PxScene* pxScene;
	EntityManager* _entMan;

	std::list<ForceGen*> _forces;
};

