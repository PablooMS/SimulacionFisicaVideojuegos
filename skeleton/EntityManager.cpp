#include "EntityManager.h"
#include "Particle.h"
#include "Projectile.h"
#include "Gaussian.h"
#include "Uniform.h"
#include "FireworkLauncher.h"
#include <iostream>

EntityManager::EntityManager(physx::PxPhysics* physx, physx::PxScene* pxsc) : gPhysx(physx), pxScene(pxsc)
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
	while (solids.size() > 0)
	{
		pxScene->removeActor(*solids.front()->getBod());
		delete solids.front();
		solids.pop_front();
	}
}

Particle* EntityManager::createParticle(Vector3D pos, Vector3D velo, Vector3D acce, double lifetime, float size, 
	Vector4 color)
{
	Particle* part = new Particle(pos, velo, acce, 0.95, gPhysx, 0, lifetime, size, color);
	tiddies.push_back(part);
	//part->setRender(true);
	return part;
}

Projectile* EntityManager::createProjectile(Vector3D pos, Vector3D velo, Vector3D acce, double mass, double lifetime, 
	float size, Vector4 color)
{
	Projectile* projectile = new Projectile(pos, velo, acce, 0.95, gPhysx, mass, lifetime, size, color);
	tiddies.push_back(projectile);
	//projectile->setRender(true);
	return projectile;
}

Generator* EntityManager::createGenerator(Particle* mod, Initialization startval, Initialization varval, int am, 
	double t, bool gaus)
{
	if (gaus) 
	{ 
		Gaussian* gGen = new Gaussian(gPhysx, mod, startval, varval, am, t);
		tiddies.push_back(gGen);
		return gGen;
	}
	else
	{
		Uniform* uGen = new Uniform(gPhysx, mod, startval, varval, am, t);
		tiddies.push_back(uGen);
		return uGen;
	}
}

FireworkLauncher* EntityManager::createFireworks(Particle* mod, Initialization startval, Initialization varval, 
	int am, double t, bool gaussian, Initialization is, Initialization iv, int ttl)
{
	FireworkLauncher* fGen = new FireworkLauncher(gPhysx, mod, startval, varval, am, t, is, iv, ttl);
	tiddies.push_back(fGen);
	return fGen;
}

SquarePart* EntityManager::createCube(Vector3D pos, Vector3D velo, Vector3D acce, double mass, double lifetime, 
	float size, float height, Vector4 color)
{
	SquarePart* sqp = new SquarePart(pos, velo, acce, 0.80, gPhysx, mass, lifetime, size, height, color);
	tiddies.push_back(sqp);
	return sqp;
}

SolidDyEnt* EntityManager::createDynamicSolid(physx::PxMaterial* m, Vector3 pos, float dense, float r, Vector4 color)
{
	SolidDyEnt* srD = new SolidDyEnt(pxScene, gPhysx, m, pos, dense, r, color);
	solids.push_back(srD);
	return srD;
}

SolidDyEnt* EntityManager::createDynamicSolid(physx::PxMaterial* m, Vector3 pos, float dense, int w, int h, int d, Vector4 color)
{
	SolidDyEnt* srD = new SolidDyEnt(pxScene, gPhysx, m, pos, dense, w, h, d, color);
	solids.push_back(srD);
	return srD;
}

SolidStEnt* EntityManager::createStaticSolid(physx::PxMaterial* m, Vector3 pos, float dense, float r, Vector4 color)
{
	SolidStEnt* stD = new SolidStEnt(pxScene, gPhysx, m, pos, dense, r, color);
	solids.push_back(stD);
	return stD;
}

SolidStEnt* EntityManager::createStaticSolid(physx::PxMaterial* m, Vector3 pos, float dense, int w, int h, int d, Vector4 color)
{
	SolidStEnt* stD = new SolidStEnt(pxScene, gPhysx, m, pos, dense, w, h, d, color);
	solids.push_back(stD);
	return stD;
}


