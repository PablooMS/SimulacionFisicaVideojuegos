#include "SolGen.h"
#include <random>

SolGen::SolGen(physx::PxPhysics* physx, SolidDyEnt* mod, SolidInit startval, SolidInit varval, double t)
	: gPhysx(physx), model(mod), start(startval), var(varval), time(t), toNext(t)
{
	statc = false;
	gen = true;
}

SolGen::~SolGen()
{
	while (ticle.size() > 0)
	{
		ticle.front()->setRender(false);
		delete ticle.front();
		ticle.pop_front();
	}

	delete model;
	model = nullptr;
}

void SolGen::generateSolid()
{
	SolidDyEnt* aux = new SolidDyEnt(model);

	SolidInit values = randomize(start, var);

	aux->setPos(values.P);
	aux->setLifetime(values.T);

	ticle.push_back(aux);
}

void SolGen::update(double t)
{
	for (SoldIter a = ticle.begin(); a != ticle.end(); ++a)
	{
		(*a)->update(t);

		if ((*a)->toDestroy())
			toDelete.push_back(a);
	}

	for (auto a : toDelete)
	{
		(*a)->setRender(false);
		ticle.erase(a);
	}

	toNext -= t;
	if (toNext < 0)
	{
		generateSolid();

		spawnTime();
	}


	toDelete.clear();
}

SolidInit SolGen::randomize(SolidInit s, SolidInit v)
{
	SolidInit result;

	std::random_device rd{};
	std::normal_distribution<double> _u{ 0,1 };
	std::mt19937 _mtseed(rd());

	result.P = s.P + Vector3(_u(_mtseed) * v.P.x, _u(_mtseed) * v.P.y, _u(_mtseed) * v.P.z);
	result.T = s.T + _u(_mtseed) * v.T;
}

void SolGen::spawnTime()
{
	std::random_device rd{};
	std::normal_distribution<double> _u{ 1, 0.3 };
	std::mt19937 _mtseed(rd());

	toNext = time * _u(_mtseed);
}
