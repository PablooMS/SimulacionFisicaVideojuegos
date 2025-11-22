#include "Float.h"

Float::Float(physx::PxPhysics* phsx, Vector3 po, float r, Vector4 color)
	: ForceGen({ 0, 0, 0 }, gPhysx, po, INF_TALL_CUBE, r, r), h0(po.y + height/2)
{
	transTop = new physx::PxTransform(trans->p);
	transTop->p.y += height / 2;
	transBot = new physx::PxTransform(trans->p);
	transTop->p.y -= height / 2;

	startUpRender();
}

void Float::startUpRender()
{
	physx::PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);
	physx::PxShape* cheto;
	Vector4 color = { 0.5, 0.5, 0.5, 0.1 };

	cheto = gPhysx->createShape(physx::PxBoxGeometry(radius, height / 10, radius), *gMaterial);

	renderTop = new RenderItem(cheto, transTop, color);

	cheto = gPhysx->createShape(physx::PxBoxGeometry(radius, height / 10, radius), *gMaterial);

	renderBot = new RenderItem(cheto, transBot, color);
}

void Float::applyForce(Entity* e)
{
	float h = e->getPos().y;
	float eH = e->getHeight();

	float immersed;
	if (h - h0 > eH * 0.5)
		immersed = 0.0;
	else if (h0 - h > eH * 0.5)
		immersed = 1.0;
	else
		immersed = (h0 - h) / eH + 0.5;

	Vector3 forc(0, density * e->getVolume() * immersed * 9.8, 0);

	e->applyForce(forc);
}