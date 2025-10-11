#pragma once
#include "Particle.h"

class Firework : public Particle
{
public:
	Firework(Vector3D pos, Vector3D velo, Vector3D acce, float dam, physx::PxPhysics* physx, double lifetime, float size, Vector4 color, int ttli)
		: Particle(pos, velo, acce, dam, physx, lifetime, size, color), ttl(ttli) {}
	Firework(Particle* other, int ttlive) : Particle(other), ttl(ttlive) {}
	~Firework();

	int getTTL() { return ttl; }
	Vector3 getPos() { return trans->p; }

private:
	int ttl;
};

