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

void ForceGen::process(SolidEnt* se)
{
	if (!se->generatorEnt())
	{
		if (global || checkInside(se->getPos()))
		{
			applySolForce(se);
		}

	}
	else
	{
		std::list<SolidEnt*> ref = se->generatorSolids();

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
	else if(volume == CUBE)
	{
		/*std::cout << o.x << " --- " << trans->p.x + radius << " / " << trans->p.x - radius << "\n";
		std::cout << o.y << " --- " << trans->p.y + height << " / " << trans->p.y - height << "\n";
		std::cout << o.z << " --- " << trans->p.z + radius << " / " << trans->p.z - radius << "\n";

		if ((o.x < trans->p.x + radius && o.x > trans->p.x - radius) &&
			(o.y < trans->p.y + height && o.y > trans->p.y - height) &&
			(o.z < trans->p.z + radius && o.z > trans->p.z - radius))
			std::cout << "Dentro\n";*/

		return (o.x < trans->p.x + radius && o.x > trans->p.x - radius) &&
			(o.y < trans->p.y + height && o.y > trans->p.y - height) &&
			(o.z < trans->p.z + radius && o.z > trans->p.z - radius);
	}
	else
	{
		return (o.x < trans->p.x + radius && o.x > trans->p.x - radius) &&
			(o.z < trans->p.z + radius && o.z > trans->p.z - radius);
	}
}

void ForceGen::applyForce(Entity* p)
{
	//std::cout << "am applyin'ere\n";
	p->applyForce(force);
}

void ForceGen::applySolForce(SolidEnt* se)
{
	se->applySolForce(force * 1000);
}
