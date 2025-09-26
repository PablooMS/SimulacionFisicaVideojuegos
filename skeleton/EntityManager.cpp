#include "EntityManager.h"
#include "Particle.h"

EntityManager::EntityManager(physx::PxPhysics* physx) : gPhysx(physx)
{
	
}

EntityManager::~EntityManager()
{
	while (tiddies.size() > 0) 
	{
		delete tiddies.front();
		tiddies.pop_front();
	}
}

void EntityManager::update(double t) 
{
	for (auto a : tiddies) 
	{
		a->update(t);
	}
}

void EntityManager::createParticle(Vector3D pos, Vector3D velo, Vector3D acce)
{
	Particle* part = new Particle(pos, velo, acce, 0.99, gPhysx);
	tiddies.push_back(part);
}


