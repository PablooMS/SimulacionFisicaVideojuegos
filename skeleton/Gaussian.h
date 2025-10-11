#pragma once
#include "Generator.h"

class Gaussian : public Generator
{
protected:
	virtual Initialization randomize() override;

	virtual void spawnTime() override;

public:
	Gaussian(physx::PxPhysics* physx, Particle* mod, Initialization startval, Initialization varval, int am, double t) 
		: Generator(physx, mod, startval, varval, am, t) {}
	~Gaussian();
};

