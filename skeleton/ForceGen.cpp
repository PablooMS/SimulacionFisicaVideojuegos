#include "ForceGen.h"
#include <math.h>
#include <iostream>

ForceGen::~ForceGen()
{
	delete trans;
}

void ForceGen::updateTime(double t)
{
	time += t;
}

void ForceGen::process(Entity* p)
{
	//std::cout << "am procesin'ere\n";
	if (!p->generatorEnt())
	{
		if (global || checkInside(p->getPos()))
			applyForce(p);
	}
	else
	{
		std::list<Entity*> ref = p->generatorEntities();

		for (auto e : ref)
		{
			process(e);
		}
	}
}

void ForceGen::handleEvent(ForceEvents evt)
{
}

bool ForceGen::checkInside(Vector3 o)
{
	if (volume == SPHERE)
		return (o - trans->p).magnitude() < radius;
	else if (volume == CYLINDER)
	{
		return sqrt(pow(o.x - trans->p.x, 2) + pow(o.z - trans->p.z, 2)) < radius &&
			(o.y < trans->p.y + height && o.y < trans->p.y - height);
	}
	else
	{
		return (o.x < trans->p.x + radius && o.x > trans->p.x - radius) &&
			(o.y < trans->p.y + radius && o.y < trans->p.y - radius) &&
			(o.z < trans->p.z + radius && o.z > trans->p.z - radius);
	}
}

void ForceGen::applyForce(Entity* p)
{
	//std::cout << "am applyin'ere\n";
	p->applyForce(force);
}
