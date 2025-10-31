#include "Wind.h"
#include <math.h>

void Wind::applyForce(Entity* p)
{
	Vector3 dif = speed - p->getVel();

	if (turb == 0)
		force = roz * dif;
	else
		force = roz * dif + turb * dif.magnitude() * dif;

	p->applyForce(force);
}
