#include "Particle.h"
#include <PxPhysicsAPI.h>

#include <iostream>

using namespace physx;

Particle::Particle(Vector3D pos, Vector3D velo, Vector3D acce, float dam, PxPhysics* physx, double lifetim, float siz)
{
	vel = velo;
	acc = acce;
	damp = dam;
	trans = new physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()));
	pastPos = { trans->p.x - vel.getX(), trans->p.y - vel.getY(), trans->p.z - vel.getZ()};

	lifetime = lifetim;

	gPhysx = physx;
	
	size = siz;

	registerRender();
}

Particle::Particle(Particle* p)
{
	vel = p->vel;
	acc = p->acc;
	trans = new physx::PxTransform(*p->trans);
	damp = p->damp;
	pastPos = p->pastPos;
	lifetime = p->lifetime;
	gPhysx = p->gPhysx;
	size = p->size;

	registerRender();
}

Particle::~Particle()
{
	render->release();
	render = nullptr;
}

void Particle::update(double t) 
{
	integrateSE(t);

	life += t;

	if (life > lifetime)
		_toDestroy = true;
}

void Particle::setPos(Vector3 p)
{
	trans->p = p;
	//std::cout << trans->p.x << " " << trans->p.y << " " << trans->p.z << "\n";
}

void Particle::setSpeed(Vector3 v)
{
	vel = Vector3D(v.x, v.y, v.z);
	//std::cout << vel.getX() << " " << vel.getY() << " " << vel.getZ() << "\n";
}

void Particle::setLifetime(double t)
{
	lifetime = t;
	//std::cout << lifetime << "\n";
}

void Particle::setRender(bool r)
{
	if (r) 
	{
		RegisterRenderItem(render);
		//std::cout << "registering\n";
	}
	else 
	{
		DeregisterRenderItem(render);
		//std::cout << "de-registering\n";
	}
}

void Particle::registerRender()
{
	PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	PxShape* cheto = gPhysx->createShape(PxSphereGeometry(size), *gMaterial);
	Vector4 color(1.0, 0.6, 0.1, 1.0);

	render = new RenderItem(cheto, trans, color);
	//setRender(true);
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
	//std::cout << "before update:" << vel.getX() << " " << vel.getY() << " " << vel.getZ() << "\n";
	vel = Vector3D(vel.getX() + acc.getX() * t, vel.getY() + acc.getY() * t,
		vel.getZ() + acc.getZ() * t).scalar(pow(damp, t));
	//std::cout << "after update:" << vel.getX() << " " << vel.getY() << " " << vel.getZ() << "\n";

	trans->p.x += vel.getX() * t;
	trans->p.y += vel.getY() * t;
	trans->p.z += vel.getZ() * t;

	//std::cout << trans->p.y << "\n";
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
