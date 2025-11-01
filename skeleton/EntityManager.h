#pragma once
#include <PxPhysicsAPI.h>
#include <list>
#include "Entity.h"
#include "Vector3D.h"
#include "Generator.h"
#include "ForceGen.h"

using entityIterator = std::list<Entity*>::iterator;

class EntityManager
{
public:
	EntityManager(physx::PxPhysics* physx);
	~EntityManager();

	void createParticle(Vector3D pos, Vector3D velo, Vector3D acce, double lifetime, float size, Vector4 color);
	void createProjectile(Vector3D pos, Vector3D velo, Vector3D acce, double mass, double lifetime, float size, Vector4 color);
	void createGenerator(Particle* mod, Initialization startval, Initialization varval, int am, double t, bool gaussian);
	void createFireworks(Particle* mod, Initialization startval, Initialization varval, int am, double t, bool gaussian,
		Initialization is, Initialization iv, int ttl);

	void update(double t);

	void applyForce(ForceGen* fgen, double t);

	void clearEnts();

private:
	
	physx::PxPhysics* gPhysx;
	std::list<Entity*> tiddies;
	std::list<entityIterator> toDelete;
};

