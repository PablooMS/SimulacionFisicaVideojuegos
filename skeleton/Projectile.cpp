#include "Projectile.h"
#include <PxPhysicsAPI.h>
#include <iostream>

using namespace physx;

Projectile::Projectile(Vector3D pos, Vector3D velo, Vector3D acce, float dam, physx::PxPhysics* physx, double mass, double lifetime) : 
	Particle(pos, velo, acce, dam, physx), mass(mass), lifetime(lifetime)
{
	
}

Projectile::~Projectile()
{
	
}

void Projectile::update(double t)
{
	Particle::update(t);

	life += t;

	if (life > lifetime)
		_toDestroy = true;

	//std::cout << life << " death? " << _toDestroy << "\n";
}
