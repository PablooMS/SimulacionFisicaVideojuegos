#pragma once
#include "Particle.h"

class Projectile : public Particle
{
public:
	Projectile(Vector3D pos, Vector3D velo, Vector3D acce, float dam, physx::PxPhysics* physx, double mass, double lifetime, float size, Vector4 col);
	virtual ~Projectile();

	virtual void update(double t) override;

private:
	double mass;
};

