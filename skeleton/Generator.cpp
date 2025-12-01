#include "Generator.h"
#include <iostream>
#include "SolGen.h"

Generator::Generator(physx::PxPhysics* physx, Particle* mod, Initialization startval, Initialization varval, int amoun, double t) 
	: gPhysx(physx), model(mod), start(startval), var(varval), ammount(amoun), time(t), toNext(t)
{
	statc = false;
	gen = true;
}

Generator::~Generator()
{
	while (ticles.size() > 0)
	{
		ticles.front()->setRender(false);
		delete ticles.front();
		ticles.pop_front();
	}

	delete model;
	model = nullptr;
}

Initialization Generator::randomize(Initialization v, Initialization s)
{
	Initialization result;


	return result;
}

void Generator::spawnTime()
{
	
}

void Generator::generateParticle()
{
	Particle* aux = new Particle(model);

	Initialization values = randomize(start, var);

	aux->setPos(values.P);
	aux->setSpeed(values.S);
	aux->setLifetime(values.T);

	ticles.push_back(aux);
	//aux->setRender(true);
}

void Generator::update(double t)
{
	for (particleIterator a = ticles.begin(); a != ticles.end(); ++a)
	{
		(*a)->update(t);
		//std::cout << "mama mia\n";

		if ((*a)->toDestroy())
			toDelete.push_back(a);
	}

	for (auto a : toDelete)
	{
		(*a)->setRender(false);
		ticles.erase(a);
	}

	toNext -= t;
	if (toNext < 0) 
	{
		for (int i = 0; i < ammount; i++)
		{
			//std::cout << "segs\n";
			generateParticle();
		}

		spawnTime();
	}
	

	toDelete.clear();
}

