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
	ForceGen(Vector3 f) : force(f), global(true), pos({0, 0, 0}), volume(SPHERE), radius(0), height(0) {};
	ForceGen(Vector3 f, Vector3 po, shape s, float r, float h) : force(f), global(false), pos(po), volume(s), radius(r), height(h) {};
	~ForceGen();

	void process(Entity* p);

protected:

	bool checkInside(Vector3 o);
	virtual void applyForce(Entity* p);

	Vector3 force;

	bool global;

	Vector3 pos;

	shape volume;
	//Radio de la esfera y el cilindo - medio lado en cubo
	float radius;
	//Media altura en cilindro
	float height;
};

