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

void Torbellino::applySolForce(SolidEnt* se)
{
	Vector3 speed = K * Vector3({ -(trans->p.z - se->getPos().z) , 0, trans->p.x - se->getPos().x });;

	if (!global)
		speed.y = 0.5f * (trans->p.y - se->getPos().y);

	Vector3 dif = speed - se->getBod()->getLinearVelocity();

	if (turb == 0)
		force = roz * dif;
	else
		force = roz * dif + turb * dif.magnitude() * dif;

	se->applySolForce(force * 1000);
}
