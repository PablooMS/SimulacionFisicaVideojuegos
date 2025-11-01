#include "Torbellino.h"

void Torbellino::applyForce(Entity* p)
{
	Vector3 speed = K * Vector3({ -(trans->p.z - p->getPos().z) , 0, trans->p.x - p->getPos().x });;

	if (!global)
		speed.y = 0.5f * (trans->p.y - p->getPos().y);

	Vector3 dif = speed - p->getVel();

	if (turb == 0)
		force = roz * dif;
	else
		force = roz * dif + turb * dif.magnitude() * dif;

	p->applyForce(force);
}
