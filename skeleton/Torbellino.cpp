#include "Torbellino.h"

void Torbellino::applyForce(Entity* p)
{
	Vector3 speed = K * Vector3({ -(trans->p.z - p->getPos().z) , 0, trans->p.x - p->getPos().x });

	Vector3 dif = speed - p->getVel();

	if (turb == 0)
		force = roz * dif;
	else
		force = roz * dif + turb * dif.magnitude() * dif;

	p->applyForce(force);
}
