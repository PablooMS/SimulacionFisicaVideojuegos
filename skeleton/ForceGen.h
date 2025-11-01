#pragma once
#include <PxPhysics.h>
#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "Particle.h"
#include "Entity.h"

enum shape {SPHERE, CYLINDER, CUBE};

class ForceGen
{
public:
	ForceGen(Vector3 f, physx::PxPhysics* phsx) 
		: gPhysx(phsx), force(f), global(true), volume(SPHERE), radius(0), height(0) 
	{
		trans = new physx::PxTransform({0, 0, 0});
	};
	ForceGen(Vector3 f, physx::PxPhysics* phsx, Vector3 po, shape s, float r, float h) 
		: gPhysx(phsx), force(f), global(false), volume(s), radius(r), height(h) 
	{
		trans = new physx::PxTransform(po);
	};
	virtual ~ForceGen();

	void process(Entity* p);

protected:

	bool checkInside(Vector3 o);
	virtual void applyForce(Entity* p);

	physx::PxPhysics* gPhysx;

	Vector3 force;

	bool global;

	physx::PxTransform* trans;

	shape volume;
	//Radio de la esfera y el cilindo - lado en cubo
	float radius;
	//Media altura en cilindro
	float height;
};

