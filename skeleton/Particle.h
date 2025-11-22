#pragma once
#define _USE_MATH_DEFINES
#include <PxPhysicsAPI.h>
#include "Vector3D.h"
#include "Entity.h"
#include <math.h>

class Particle : public Entity
{
public:
	Particle(Vector3D pos, Vector3D velo, Vector3D acce, float dam, physx::PxPhysics* physx, double mass, double lifetime, float size, Vector4 color);
	Particle(Particle* p);
	Particle(Vector3D pos, Vector3D velo);
	virtual ~Particle();

	virtual void update(double t) override;

	void setPos(Vector3 p);
	void setSpeed(Vector3 v);
	void setLifetime(double t);

	virtual float getHeight() override { return size * 2; };
	virtual float getVolume() override { return M_PI * pow(size, 2); };
	//virtual shape getShape() override { return SPHERE; }

protected:
	virtual void registerRender();

	//Integrates via implicit Euler
	void integrateE(double t);
	//Integrates via semi-implicit Euler
	void integrateSE(double t);
	//Integrates via Verlet
	void integrateV(double t);

	Vector3D acc;
	float damp;

	double mass;

	Vector3D pastPos;

	float size;
	Vector4 color;
	physx::PxPhysics* gPhysx;

	double lifetime;
	double life = 0;
};

