#include "ShootingComponent.h"

using namespace physx;

void ShootingComponent::update(double t)
{
	if (ti >= 0)
		ti -= t;
}

void ShootingComponent::shoot()
{
	if (ti >= 0)
		return;

	Vector3 camPos = cam->getTransform().p;
	Vector3 camDir = cam->getDir();

	entMan->createBullet(camPos, lifetime, dense, r);

	//Coloca la fuerza de la explosión justo detrás de la bala generada y detona
	ex->setPosition(camPos - camDir * 0.1);
	ex->explode();

	ti = maxT;
}
