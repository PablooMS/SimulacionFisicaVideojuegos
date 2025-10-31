#include "ForceGen.h"
#include <math.h>
#include <iostream>

ForceGen::~ForceGen()
{
}

void ForceGen::process(Entity* p)
{
	//std::cout << "am procesin'ere\n";
	if (global || checkInside(p->getPos()))
		applyForce(p);
}

bool ForceGen::checkInside(Vector3 o)
{
	if (volume == SPHERE)
		return (o - pos).magnitude() < radius;
	else if (volume == CYLINDER)
	{
		return sqrt(pow(o.x - pos.x, 2) + pow(o.z - pos.z, 2)) < radius && 
			(o.y < pos.y + height && o.y < pos.y - height);
	}
	else
	{
		return (o.x < pos.x + radius && o.x > pos.x - radius) && 
			(o.y < pos.y + radius && o.y < pos.y - radius) &&
			(o.z < pos.z + radius && o.z > pos.z - radius);
	}
}

void ForceGen::applyForce(Entity* p)
{
	//std::cout << "am applyin'ere\n";
	p->applyForce(force);
}
