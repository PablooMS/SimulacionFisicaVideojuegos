#include "Spring.h"

Spring::Spring(Entity* e1, Vector3 e2, int length, int konstant) : Entity({0, 0, 0}, {0, 0, 0})
{
	statc = true;

	ending1 = e1;
	
	twoEnd = false;
	end2 = e2;
	ending2 = nullptr;

	l = length;
	k = konstant;
}

Spring::Spring(Entity* e1, Entity* e2, int length, int konstant) : Entity({ 0, 0, 0 }, { 0, 0, 0 })
{
	statc = true;

	ending1 = e1;

	twoEnd = true;
	ending2 = e2;

	l = length;
	k = konstant;
}

void Spring::update(double t)
{
	Vector3 force;
	float mag;
	if (twoEnd)
	{
		force = ending1->getPos() - ending2->getPos();
		mag = force.normalize();
		force = -k * (mag - l) * force;
		ending1->applyForce(force);
		ending2->applyForce(-force);
	}
	else
	{
		force = ending1->getPos() - end2;
		mag = force.normalize();
		ending1->applyForce(-k * (mag - l) * force);
	}
}

