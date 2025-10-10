#include "Generator.h"
#include <iostream>

Generator::Generator(physx::PxPhysics* physx, Particle* mod, Initialization startval, Initialization varval, int amoun) 
	: gPhysx(physx), model(mod), start(startval), var(varval), ammount(amoun)
{
}

Generator::~Generator()
{
	while (ticles.size() > 0)
	{
		delete ticles.front();
		ticles.pop_front();
	}

	delete model;
	model = nullptr;
}

Initialization Generator::randomize()
{
	Initialization result;


	return result;
}

void Generator::generateParticle()
{
	Particle* aux = new Particle(model);

	Initialization values = randomize();

	aux->setPos(values.P);
	aux->setSpeed(values.S);
	aux->setLifetime(values.T);

	ticles.push_back(aux);
}

void Generator::update(double t)
{
	for (particleIterator a = ticles.begin(); a != ticles.end(); ++a)
	{
		(*a)->update(t);

		if ((*a)->toDestroy())
			toDelete.push_back(a);
	}

	for (auto a : toDelete)
	{
		ticles.erase(a);
	}

	for (int i = 0; i < ammount; i++) 
	{
		std::cout << "segs";
		generateParticle();
	}

	toDelete.clear();
}

