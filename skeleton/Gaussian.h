#pragma once
#include "Generator.h"

class Gaussian : public Generator
{
protected:
	virtual Initialization randomize() override;

public:
	Gaussian(physx::PxPhysics* physx, Particle* mod, Initialization startval, Initialization varval, int am) : Generator(physx, mod, startval, varval, am) {}
	~Gaussian();
};

