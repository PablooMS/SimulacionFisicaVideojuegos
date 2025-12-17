#include "FireworkLauncher.h"
#include <iostream>

FireworkLauncher::~FireworkLauncher()
{
	//std::cout << firs.size() << "\n";
	while (firs.size() > 0)
	{
		//std::cout << firs.size() << "\n";
		delete (*firs.begin());
		firs.erase(firs.begin());
	}
}

void FireworkLauncher::generateInitParticle()
{
	Firework* aux = new Firework(model, ilives);

	Initialization values = randomize(istart, ivar);

	aux->setPos(values.P);
	aux->setSpeed(values.S);
	aux->setLifetime(values.T);

	firs.push_back(aux);
	//aux->setRender(true);
}

void FireworkLauncher::generateParticle(Vector3 startPos, int tt)
{
	Firework* aux = new Firework(model, tt);

	Initialization ne = start;
	start.P = startPos;

	Initialization values = randomize(ne, var);

	aux->setPos(values.P);
	aux->setSpeed(values.S);
	aux->setLifetime(values.T);

	firs.push_back(aux);
	//aux->setRender(true);
}

void FireworkLauncher::update(double t)
{
	for (fireIterator a = firs.begin(); a != firs.end(); ++a)
	{
		(*a)->update(t);

		if ((*a)->toDestroy())
			toDeletes.push_back(a);
	}

	for (fireIterator a : toDeletes)
	{
		(*a)->setRender(false);
		int ttl = (*a)->getTTL();
		Vector3 death = (*a)->getPos();
		firs.erase(a);

		for (int i = 0; i < ammount * ttl; i++) 
		{
			generateParticle(death, ttl - 1);
		}
	}

	toNext -= t;
	if (toNext < 0)
	{
		generateInitParticle();

		spawnTime();
	}


	toDeletes.clear();
}
