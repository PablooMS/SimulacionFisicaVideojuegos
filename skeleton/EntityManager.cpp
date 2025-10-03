#include "EntityManager.h"
#include "Particle.h"
#include "Projectile.h"

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
	for (entityIterator a = tiddies.begin(); a != tiddies.end(); ++a) 
	{
		(*a)->update(t);

		if ((*a)->toDestroy())
			toDelete.push_back(a);
	}

	for (auto a : toDelete) 
	{
		tiddies.erase(a);
	}

	toDelete.clear();
}

void EntityManager::createParticle(Vector3D pos, Vector3D velo, Vector3D acce)
{
	Particle* part = new Particle(pos, velo, acce, 0.95, gPhysx);
	tiddies.push_back(part);
}

void EntityManager::createProjectile(Vector3D pos, Vector3D velo, Vector3D acce, double mass, double lifetime)
{
	Projectile* projectile = new Projectile(pos, velo, acce, 0.95, gPhysx, mass, lifetime);
	tiddies.push_back(projectile);
}


