#include "Particle.h"
#include <PxPhysicsAPI.h>

#include <iostream>

using namespace physx;

Particle::Particle(Vector3D pos, Vector3D velo, Vector3D acce, float dam, PxPhysics* physx)
{
	vel = velo;
	acc = acce;
	damp = dam;
	trans = new physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()));
	pastPos = { trans->p.x - vel.getX(), trans->p.y - vel.getY(), trans->p.z - vel.getZ()};

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
	integrateV(t);
}

void Particle::integrateE(double t)
{
	//std::cout << "posx: " << trans->p.x << "\n";
	trans->p.x += vel.getX() * t;
	trans->p.y += vel.getY() * t;
	trans->p.z += vel.getZ() * t;

	vel = Vector3D(vel.getX() + acc.getX() * t, vel.getY() + acc.getY() * t,
		vel.getZ() + acc.getZ() * t).scalar(pow(damp, t));
}

void Particle::integrateSE(double t)
{
	vel = Vector3D(vel.getX() + acc.getX() * t, vel.getY() + acc.getY() * t,
		vel.getZ() + acc.getZ() * t).scalar(pow(damp, t));

	trans->p.x += vel.getX() * t;
	trans->p.y += vel.getY() * t;
	trans->p.z += vel.getZ() * t;
}

void Particle::integrateV(double t)
{
	Vector3D aid({ trans->p.x, trans->p.y, trans->p.z });

	trans->p.x = 2 * trans->p.x - pastPos.getX() + t * t * acc.getX();
	trans->p.y = 2 * trans->p.y - pastPos.getY() + t * t * acc.getY();
	trans->p.z = 2 * trans->p.z - pastPos.getZ() + t * t * acc.getZ();

	pastPos = aid;
	std::cout << pastPos.getY() << "\n";
}
