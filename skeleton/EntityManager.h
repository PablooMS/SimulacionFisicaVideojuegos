#pragma once
#include <PxPhysicsAPI.h>
#include <list>
#include "Entity.h"
#include "Vector3D.h"
#include "Generator.h"
#include "ForceGen.h"
#include "Projectile.h"
#include "FireworkLauncher.h"
#include "SquarePart.h"
#include "SolidEnt.h"
#include "SolGen.h"

using entityIterator = std::list<Entity*>::iterator;

class EntityManager
{
public:
	EntityManager(physx::PxPhysics* physx, physx::PxScene* pxsc);
	~EntityManager();

	//NO SOLIDOS
	Particle* createParticle(Vector3D pos, Vector3D velo, Vector3D acce, double lifetime, float size, Vector4 color);
	Projectile* createProjectile(Vector3D pos, Vector3D velo, Vector3D acce, double mass, double lifetime, float size, Vector4 color);
	SquarePart* createCube(Vector3D pos, Vector3D velo, Vector3D acce, double mass, double lifetime, float size, float height, Vector4 color);

	//Generadores
	Generator* createGenerator(Particle* mod, Initialization startval, Initialization varval, int am, double t, bool gaussian);
	FireworkLauncher* createFireworks(Particle* mod, Initialization startval, Initialization varval, int am, double t, bool gaussian,
		Initialization is, Initialization iv, int ttl);


	//SOLIDOS
	SolidDyEnt* createDynamicSolid(physx::PxMaterial* m, Vector3 pos, float dense, float r, Vector4 color);
	SolidDyEnt* createDynamicSolid(physx::PxMaterial* m, Vector3 pos, float dense, float w, float h, float d, Vector4 color);
	SolidStEnt* createStaticSolid(physx::PxMaterial* m, Vector3 pos, float r, Vector4 color);
	SolidStEnt* createStaticSolid(physx::PxMaterial* m, Vector3 pos, float w, float h, float d, Vector4 color);

	//Generadores
	SolGen* createSolidGenerator(SolidDyEnt* mod, SolidInit startval, SolidInit varval, double t);


	void update(double t);

	void applyForce(ForceGen* fgen, double t);

	void clearEnts();

private:
	
	physx::PxPhysics* gPhysx;
	physx::PxScene* pxScene;
	std::list<Entity*> tiddies;
	std::list<SolidEnt*> solids;
	std::list<entityIterator> toDelete;
};

