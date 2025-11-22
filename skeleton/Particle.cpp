#include "Particle.h"
#include <PxPhysicsAPI.h>

#include <iostream>

using namespace physx;

Particle::Particle(Vector3D pos, Vector3D velo, Vector3D acce, float dam, PxPhysics* physx, double mas, double lifetim, float siz, Vector4 col)
	: Entity({ pos.getX(), pos.getY(), pos.getZ() }, { velo.getX(), velo.getY(), velo.getZ() })
{
	acc = acce;
	damp = dam;
	pastPos = { trans->p.x - vel.x, trans->p.y - vel.y, trans->p.z - vel.z};

	mass = mas;
	forces = { 0, 0, 0 };
	statc = false;

	lifetime = lifetim;

	gPhysx = physx;
	
	size = siz;
	color = col;

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
	color = p->color;
	statc = p->statc;

	mass = p->mass;
	forces = { 0, 0, 0 };


	registerRender();
}

Particle::Particle(Vector3D pos, Vector3D velo)
	: Entity({ pos.getX(), pos.getY(), pos.getZ() }, { velo.getX(), velo.getY(), velo.getZ() })
{
}

Particle::~Particle()
{
	//std::cout << "r: " << rendered << "\n";
	if (rendered)
	{
		//setRender(false);
		render->release();
	}
	render = nullptr;
}

void Particle::update(double t) 
{

	//std::cout << "Forces:\nBefore:" << forces.x << " " << forces.y << " " << forces.z << "\n";
	//std::cout << "inverse mass: " << mass << std::endl;

	if (mass < 1000)
		forces = forces * mass;
	else
		forces *= 1000;

	//std::cout << "During:" << forces.x << " " << forces.y << " " << forces.z << "\n";

	integrateSE(t);

	//std::cout << "After During:" << forces.x << " " << forces.y << " " << forces.z << "\n";

	forces = { 0, 0, 0 };

	//std::cout << "After:" << forces.x << " " << forces.y << " " << forces.z << "\n";

	if (lifetime != -1)
	{
		life += t;

		if (life > lifetime)
			_toDestroy = true;
	}

	//std::cout << trans->p.y << std::endl;
}

void Particle::setPos(Vector3 p)
{
	trans->p = p;
	//std::cout << trans->p.x << " " << trans->p.y << " " << trans->p.z << "\n";
}

void Particle::setSpeed(Vector3 v)
{
	vel = v;
	//std::cout << vel.getX() << " " << vel.getY() << " " << vel.getZ() << "\n";
}

void Particle::setLifetime(double t)
{
	lifetime = t;
	//std::cout << lifetime << "\n";
}

void Particle::registerRender()
{
	PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	PxShape* cheto = gPhysx->createShape(PxSphereGeometry(size), *gMaterial);

	render = new RenderItem(cheto, trans, color);
	rendered = true;
	//setRender(true);
}

void Particle::integrateE(double t)
{
	//std::cout << "posx: " << trans->p.x << "\n";
	trans->p.x += vel.x * t;
	trans->p.y += vel.y * t;
	trans->p.z += vel.z * t;

	vel = Vector3(vel.x + acc.getX() * t + forces.x * t, vel.y + acc.getY() * t + forces.y * t,
		vel.z + acc.getZ() * t + forces.z * t) * pow(damp, t);
}

void Particle::integrateSE(double t)
{
	//std::cout << "before update:" << vel.getX() << " " << vel.getY() << " " << vel.getZ() << "\n";
	vel = Vector3(vel.x + acc.getX() * t + forces.x * t, vel.y + acc.getY() * t + forces.y * t,
		vel.z + acc.getZ() * t + forces.z * t) * pow(damp, t);
	//std::cout << "after update:" << vel.getX() << " " << vel.getY() << " " << vel.getZ() << "\n";

	trans->p.x += vel.x * t;
	trans->p.y += vel.y * t;
	trans->p.z += vel.z * t;

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
