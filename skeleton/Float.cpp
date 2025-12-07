#include "Float.h"
#include <iostream>

Float::Float(physx::PxPhysics* phsx, Vector3 po, float r, float dense)
	: ForceGen({ 0, 0, 0 }, phsx, po, INF_TALL_CUBE, r, r), h0(po.y + height/2), density(dense)
{
	transTop = new physx::PxTransform(trans->p);
	transTop->p.y += height / 2;
	/*transBot = new physx::PxTransform(trans->p);
	transTop->p.y -= height / 2;*/

	startUpRender();
}

void Float::startUpRender()
{
	physx::PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);
	physx::PxShape* cheto;
	Vector4 color = { 0.0, 0.0, 1.0, 1.0 };

	cheto = gPhysx->createShape(physx::PxBoxGeometry(radius, 0.1, radius), *gMaterial);

	renderTop = new RenderItem(cheto, transTop, color);

	/*cheto = gPhysx->createShape(physx::PxBoxGeometry(radius, height / 10, radius), *gMaterial);

	renderBot = new RenderItem(cheto, transBot, color);*/
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

	/*std::cout << "Dense: " << density << " Volume: " << e->getVolume() << " Immersed " << immersed << std::endl;
	std::cout << "Force: " << forc.y << std::endl;*/

	e->applyForce(forc);
}

void Float::applySolForce(SolidEnt* se)
{
	float h = se->getPos().y;
	float eH = se->getHeight();

	float immersed;
	if (h - h0 > eH * 0.5)
		immersed = 0.0;
	else if (h0 - h > eH * 0.5)
		immersed = 1.0;
	else
		immersed = (h0 - h) / eH + 0.5;

	Vector3 forc(0, density * se->getVolume() * immersed * 9.8, 0);

	se->applyForce(forc);
}
