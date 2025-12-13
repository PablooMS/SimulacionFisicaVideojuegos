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
	//int n = 0;
	for (entityIterator a = tiddies.begin(); a != tiddies.end(); ++a) 
	{
		(*a)->update(t);
		//std::cout << n << std::endl;

		if ((*a)->toDestroy())
			toDelete.push_back(a);

		//n++;
	}
	for (SoldIter b = solids.begin(); b != solids.end(); ++b) 
	{
		(*b)->update(t);
		//std::cout << n << std::endl;

		if ((*b)->toDestroy())
			toDeleteSol.push_back(b);

		//n++;
	}

	for (auto a : toDelete) 
	{
		(*a)->setRender(false);
		tiddies.erase(a);
	}
	for (auto b : toDeleteSol) 
	{
		//(*b)->setRender(false);
		delete* b;
		solids.erase(b);
	}

	toDelete.clear();
	toDeleteSol.clear();
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
		//n++;
	}

	for (SoldIter b = solids.begin(); b != solids.end(); b++)
	{
		if (!(*b)->staticEnt())
			fgen->process((*b));
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
	while (!solids.empty())
	{
		auto ac = solids.front()->getAct();

		if(ac != nullptr)
			pxScene->removeActor(*ac);

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

SolidDyEnt* EntityManager::createDynamicSolid(physx::PxMaterial* m, Vector3 pos, float dense, float w, float h, float d, Vector4 color)
{
	SolidDyEnt* srD = new SolidDyEnt(pxScene, gPhysx, m, pos, dense, w, h, d, color);
	solids.push_back(srD);
	return srD;
}

SolidStEnt* EntityManager::createStaticSolid(physx::PxMaterial* m, Vector3 pos, float r, Vector4 color)
{
	SolidStEnt* stD = new SolidStEnt(pxScene, gPhysx, m, pos, r, color);
	solids.push_back(stD);
	return stD;
}

SolidStEnt* EntityManager::createStaticSolid(physx::PxMaterial* m, Vector3 pos, float w, float h, float d, Vector4 color)
{
	SolidStEnt* stD = new SolidStEnt(pxScene, gPhysx, m, pos, w, h, d, color);
	solids.push_back(stD);
	return stD;
}

SolGen* EntityManager::createSolidGenerator(SolidDyEnt* mod, SolidInit startval, SolidInit varval, double t)
{
	SolGen* sGen = new SolGen(gPhysx, mod, startval, varval, t);
	solids.push_back(sGen);
	return sGen;
}

Enemy* EntityManager::createEnemy(Vector3 pos, float dense, float r, int* cont)
{
	Enemy* em = new Enemy(pxScene, gPhysx, pos, dense, r, cont);
	solids.push_back(em);
	return em;
}

Barrel* EntityManager::createBarrel(Vector3 pos, float dense, float h, Explosive* ex)
{
	Barrel* bar = new Barrel(pxScene, gPhysx, pos, dense, h * 0.75, h, h * 0.75, ex);
	solids.push_back(bar);
	return bar;
}

Bullet* EntityManager::createBullet(Vector3 pos, float lifetime, float dense, float r)
{
	Bullet* bul = new Bullet(pxScene, gPhysx, pos, lifetime, dense, r);
	solids.push_back(bul);
	return bul;
}

SolidStEnt* EntityManager::createFloor(physx::PxMaterial* m, Vector3 pos, float r, Vector4 color)
{
	physx::PxFilterData floorFilter;
	floorFilter.word0 = LAYER_FLOOR;
	floorFilter.word1 = LAYER_DEFAULT | LAYER_ENEMY | LAYER_BULLET | LAYER_BARREL;
	
	SolidStEnt* flo = new SolidStEnt(pxScene, gPhysx, m, pos, r, 1, r, color, floorFilter);
	solids.push_back(flo);
	return flo;
}


