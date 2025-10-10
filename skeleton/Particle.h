#pragma once
#include <PxPhysicsAPI.h>
#include "Vector3D.h"
#include "RenderUtils.hpp"
#include "Entity.h"

class Particle : public Entity
{
public:
	Particle(Vector3D pos, Vector3D velo, Vector3D acce, float dam, physx::PxPhysics* physx, double lifetime, float size);
	Particle(Particle* p);
	~Particle();

	virtual void update(double t) override;

	void setPos(Vector3 p);
	void setSpeed(Vector3 v);
	void setLifetime(double t);

protected:
	void registerRender();

	//Integrates via implicit Euler
	void integrateE(double t);
	//Integrates via semi-implicit Euler
	void integrateSE(double t);
	//Integrates via Verlet
	void integrateV(double t);

	Vector3D vel;
	Vector3D acc;
	physx::PxTransform* trans;
	float damp;

	Vector3D pastPos;

	RenderItem* render;
	physx::PxPhysics* gPhysx;

	double lifetime;
	double life = 0;

	float size;
};

