#pragma once
#include "Gaussian.h"
#include "Firework.h"

using fireIterator = std::list<Firework*>::iterator;

class FireworkLauncher : public Gaussian
{
private:
	std::list<Firework*> firs;
	std::list<fireIterator> toDeletes;

	Initialization istart;
	Initialization ivar;

	int ilives;

	void generateInitParticle();

	void generateParticle(Vector3 startPos, int tt);

public:
	FireworkLauncher(physx::PxPhysics* physx, Particle* mod, Initialization startval, Initialization varval, int am, double t, 
		Initialization is, Initialization iv, int ttl)
		: Gaussian(physx, mod, startval, varval, am, t), istart(is), ivar(iv), ilives(ttl) {}
	virtual ~FireworkLauncher();

	virtual void update(double t) override;
};

