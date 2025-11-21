#pragma once
#include <PxPhysics.h>
#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "Particle.h"
#include "Entity.h"

enum shape {SPHERE, CYLINDER, CUBE};

enum ForceEvents { Explosion };

class ForceGen
{
public:
	ForceGen(Vector3 f, physx::PxPhysics* phsx) 
		: gPhysx(phsx), force(f), global(true), specific(false), volume(SPHERE), radius(0), height(0)
	{
		trans = new physx::PxTransform({0, 0, 0});
	};
	ForceGen(Vector3 f, physx::PxPhysics* phsx, Vector3 po, shape s, float r, float h) 
		: gPhysx(phsx), force(f), global(false), specific(false), volume(s), radius(r), height(h)
	{
		trans = new physx::PxTransform(po);
	};
	//Constructor para fuerzas específicas que serán modificadas en updateTime
	ForceGen(physx::PxPhysics* phsx)
		: gPhysx(phsx), force({ 0, 0, 0 }), global(false), specific(true), volume(SPHERE), radius(0), height(0)
	{
		trans = new physx::PxTransform({0, 0, 0});
	};
	virtual ~ForceGen();

	void updateTime(double t);
	virtual void update() {};
	void process(Entity* p);

	virtual void handleEvent(ForceEvents evt);

	bool isSpecific() { return specific; };

protected:

	bool checkInside(Vector3 o);
	virtual void applyForce(Entity* p);

	physx::PxPhysics* gPhysx;

	Vector3 force;

	bool global;
	bool specific;

	physx::PxTransform* trans;

	shape volume;
	//Radio de la esfera y el cilindo - lado en cubo
	float radius;
	//Media altura en cilindro
	float height;

	double time = 0;
};

