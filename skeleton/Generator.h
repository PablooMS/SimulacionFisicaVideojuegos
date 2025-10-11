#pragma once
#include <PxPhysicsAPI.h>
#include <list>
#include "Entity.h"
#include "Vector3D.h"
#include "Particle.h"

using particleIterator = std::list<Particle*>::iterator;

struct Initialization 
{
	Vector3 P;
	Vector3 S;
	double T;
};

class Generator : public Entity
{
private:
	physx::PxPhysics* gPhysx;
	std::list<Particle*> ticles;
	std::list<particleIterator> toDelete;

	Particle* model;
	int ammount;

protected:
	Initialization start;

	Initialization var;

	virtual Initialization randomize();

	double time;
	double toNext;

	virtual void spawnTime();

public:
	Generator(physx::PxPhysics* physx, Particle* mod, Initialization startval, Initialization varval, int amount, double time);
	~Generator();

	virtual void generateParticle();

	virtual void update(double t) override;
};

