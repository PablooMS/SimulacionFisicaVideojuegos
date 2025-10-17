#pragma once
#include <PxPhysicsAPI.h>
#include "EntityManager.h"

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

protected:

	bool change;
	std::string next;

	physx::PxPhysics* gPhysx;
	EntityManager* _entMan;
};

