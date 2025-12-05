#pragma once
#include "Entity.h"
#include "SolidEnt.h"

using SoldIter = std::list<SolidEnt*>::iterator;

struct SolidInit
{
	Vector3 P;
	double T;
};

class SolGen : public SolidEnt
{
public:

	SolGen(physx::PxPhysics* physx, SolidDyEnt* mod, SolidInit startval, SolidInit varval, double time);
	~SolGen();

	void generateSolid();

	virtual void update(double t) override;

	virtual std::list<SolidEnt*>& generatorSolids() override { return ticle; }

private:

	SolidDyEnt* model;
	std::list<SolidEnt*> ticle;
	std::list<SoldIter> toDelete;

	SolidInit start;
	SolidInit var;

	SolidInit randomize(SolidInit s, SolidInit v);

	double time;
	double toNext;

	void spawnTime();

	physx::PxPhysics* gPhysx;
};

