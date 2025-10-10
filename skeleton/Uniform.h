#pragma once
#include "Generator.h"

class Uniform : public Generator
{
protected:

	virtual Initialization randomize() override;

public:
	Uniform(physx::PxPhysics* physx, Particle* mod, Initialization startval, Initialization varval, int am) : Generator(physx, mod, startval, varval, am) {}
	~Uniform();
};

