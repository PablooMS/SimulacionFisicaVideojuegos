#include "EntityManager.h"
#include "Particle.h"
#include "Projectile.h"
#include "Gaussian.h"
#include "Uniform.h"
#include "FireworkLauncher.h"
#include <iostream>

EntityManager::EntityManager(physx::PxPhysics* physx) : gPhysx(physx)
{
	
}

EntityManager::~EntityManager()
{
	clearEnts();
}

void EntityManager::update(double t) 
{
	//std::cout << "entities: " << tiddies.size() << std::endl;
	int n = 0;
	for (entityIterator a = tiddies.begin(); a != tiddies.end(); ++a) 
	{
		(*a)->update(t);
		//std::cout << n << std::endl;

		if ((*a)->toDestroy())
			toDelete.push_back(a);

		n++;
	}

	for (auto a : toDelete) 
	{
		(*a)->setRender(false);
		tiddies.erase(a);
	}

	toDelete.clear();
}

void EntityManager::applyForce(ForceGen* fgen, double t)
{
	//std::cout << "entitiesToForce: " << tiddies.size() << std::endl;
	int n = 0;
	for (entityIterator a = tiddies.begin(); a != tiddies.end(); ++a)
	{
		//std::cout << n << ": static: " << (*a)->staticEnt() << std::endl;
		if (!(*a)->staticEnt())
			fgen->process((*a));
		n++;
	}
}

void EntityManager::clearEnts()
{
	while (tiddies.size() > 0)
	{
		delete tiddies.front();
		tiddies.pop_front();
	}
}

void EntityManager::createParticle(Vector3D pos, Vector3D velo, Vector3D acce, double lifetime, float size, Vector4 color)
{
	Particle* part = new Particle(pos, velo, acce, 0.95, gPhysx, 0, lifetime, size, color);
	tiddies.push_back(part);
	//part->setRender(true);
}

void EntityManager::createProjectile(Vector3D pos, Vector3D velo, Vector3D acce, double mass, double lifetime, float size, Vector4 color)
{
	Projectile* projectile = new Projectile(pos, velo, acce, 0.95, gPhysx, mass, lifetime, size, color);
	tiddies.push_back(projectile);
	//projectile->setRender(true);
}

void EntityManager::createGenerator(Particle* mod, Initialization startval, Initialization varval, int am, double t, bool gaus)
{
	if (gaus) 
	{ 
		Gaussian* gGen = new Gaussian(gPhysx, mod, startval, varval, am, t);
		tiddies.push_back(gGen);
	}
	else
	{
		Uniform* uGen = new Uniform(gPhysx, mod, startval, varval, am, t);
		tiddies.push_back(uGen);
	}
}

void EntityManager::createFireworks(Particle* mod, Initialization startval, Initialization varval, int am, double t, bool gaussian, Initialization is, Initialization iv, int ttl)
{
	FireworkLauncher* fGen = new FireworkLauncher(gPhysx, mod, startval, varval, am, t, is, iv, ttl);
	tiddies.push_back(fGen);
}


