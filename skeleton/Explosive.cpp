#define _USE_MATH_DEFINES

#include "Explosive.h"
#include <cmath>
#include <iostream>

void Explosive::explode()
{
	time = 0;
	exploding = true;
	//std::cout << "AAAAAAAA\n";
}

void Explosive::handleEvent(ForceEvents evt)
{
	//std::cout << "readytoGo\n";
	if (evt == Explosion)
		explode();
}

void Explosive::applyForce(Entity* p)
{
	//std::cout << "time: " << time << std::endl;

	if (!exploding || time > 4 * timeC)
		return; 

	//std::cout << "ei";

	Vector3 dif = p->getPos() - trans->p;
	Vector3 forc = (intensity / pow(dif.magnitude(), 2)) * dif * pow(M_E, -(time / timeC));

	//std::cout << "x: " << forc.x << " y: " << forc.y << " z: " << forc.z << std::endl;

	p->applyForce(forc);
}
