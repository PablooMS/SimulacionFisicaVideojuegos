#include "Wind.h"
#include <math.h>
#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "Float.h"

Wind::Wind(Vector3 spee, physx::PxPhysics* phsx, float roza, float turbo, Vector3 po, shape s, float r, float h, bool rendr)
	: speed(spee), roz(roza), turb(turbo), rendering(rendr), ForceGen({ 0, 0, 0 }, phsx, po, s, r, h)
{
	if (rendering)
		startUpRender();
}

void Wind::startUpRender()
{
	physx::PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);
	physx::PxShape* cheto;

	switch (volume)
	{
	case SPHERE:
		cheto = gPhysx->createShape(physx::PxSphereGeometry(radius), *gMaterial);
		break;
	case CYLINDER:
		cheto = gPhysx->createShape(physx::PxCapsuleGeometry(radius, height), *gMaterial);
		break;
	case CUBE:
		cheto = gPhysx->createShape(physx::PxBoxGeometry(radius, radius, radius), *gMaterial);
		break;
	default:
		cheto = gPhysx->createShape(physx::PxSphereGeometry(radius), *gMaterial);
		break;
	}
	Vector4 color = { 0.5, 0.5, 0.5, 0.1 };

	render = new RenderItem(cheto, trans, color);
}

void Wind::applyForce(Entity* p)
{
	Vector3 dif = speed - p->getVel();

	if (turb == 0)
		force = roz * dif;
	else
		force = roz * dif + turb * dif.magnitude() * dif;

	p->applyForce(force);
}

void Wind::applySolForce(SolidEnt* se)
{
	Vector3 dif = speed - se->getBod()->getLinearVelocity();

	if (turb == 0)
		force = roz * dif;
	else
		force = roz * dif + turb * dif.magnitude() * dif;

	se->applySolForce(force * 1000);
}
