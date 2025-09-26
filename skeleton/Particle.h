#pragma once
#include <PxPhysicsAPI.h>
#include "Vector3D.h"
#include "RenderUtils.hpp"
#include "Entity.h"

class Particle : public Entity
{
public:
	Particle(Vector3D pos, Vector3D velo, Vector3D acce, float dam, physx::PxPhysics* physx);
	~Particle();

	void update(double t) override;

private:
	void integrate(double t);

	Vector3D vel;
	Vector3D acc;
	physx::PxTransform* trans;
	float damp;

	RenderItem* render;
	physx::PxPhysics* gPhysx;
};

