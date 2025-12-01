#pragma once
#include "Entity.h"
#include "SolidEnt.h"

using SoldIter = std::list<Entity*>::iterator;

struct SolidInit
{
	Vector3 P;
	double T;
};

class SolGen : public Entity
{
public:

	SolGen(physx::PxPhysics* physx, SolidDyEnt* mod, SolidInit startval, SolidInit varval, double time);
	~SolGen();

	void generateSolid();

	virtual void update(double t) override;

	std::list<Entity*>& generatorEntities() override { return ticle; }

private:

	SolidDyEnt* model;
	std::list<Entity*> ticle;
	std::list<SoldIter> toDelete;

	SolidInit start;
	SolidInit var;

	virtual SolidInit randomize(SolidInit s, SolidInit v);

	double time;
	double toNext;

	virtual void spawnTime();

	physx::PxPhysics* gPhysx;
};

