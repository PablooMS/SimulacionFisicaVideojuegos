#pragma once
#include <PxPhysicsAPI.h>
#include <list>
#include "Entity.h"
#include "Vector3D.h"

using entityIterator = std::list<Entity*>::iterator;

class EntityManager
{
public:
	EntityManager(physx::PxPhysics* physx);
	~EntityManager();

	void createParticle(Vector3D pos, Vector3D velo, Vector3D acce);
	void createProjectile(Vector3D pos, Vector3D velo, Vector3D acce, double mass, double lifetime);

	void update(double t);

private:
	
	physx::PxPhysics* gPhysx;
	std::list<Entity*> tiddies;
	std::list<entityIterator> toDelete;
};

