#include "Particle.h"
#include <PxPhysicsAPI.h>

#include <iostream>

using namespace physx;

Particle::Particle(Vector3D pos, Vector3D velo, Vector3D acce, float dam, PxPhysics* physx)
{
	vel = velo;
	acc = acce;
	trans = new physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()));

	gPhysx = physx;
	PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	PxShape* cheto = gPhysx->createShape(PxSphereGeometry(3), *gMaterial);
	Vector4 color(1.0, 0.6, 0.1, 1.0);

	render = new RenderItem(cheto, trans, color);
	RegisterRenderItem(render);
}

Particle::~Particle()
{
	render->release();
	render = nullptr;
}

void Particle::update(double t) 
{
	integrate(t);
}

void Particle::integrate(double t)
{
	//std::cout << "posx: " << trans->p.x << "\n";
	trans->p.x += vel.getX() * t;
	trans->p.y += vel.getY() * t;
	trans->p.z += vel.getZ() * t;

	vel = Vector3D(vel.getX() + acc.getX() * t, vel.getY() + acc.getY() * t, 
		vel.getZ() + acc.getZ() * t).scalar(pow(damp, t));
}
