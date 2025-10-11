#pragma once
#include "Generator.h"

class Uniform : public Generator
{
protected:

	virtual Initialization randomize() override;

	virtual void spawnTime() override;

public:
	Uniform(physx::PxPhysics* physx, Particle* mod, Initialization startval, Initialization varval, int am, double t) 
		: Generator(physx, mod, startval, varval, am, t) {}
	~Uniform();
};

