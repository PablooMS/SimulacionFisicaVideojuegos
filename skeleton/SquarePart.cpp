#include "SquarePart.h"
#include <PxPhysicsAPI.h>

using namespace physx;

SquarePart::SquarePart(Vector3D pos, Vector3D velo, Vector3D acce, float dam, physx::PxPhysics* physx, 
	double mas, double lifetim, float siz, float heigh, Vector4 col) 
	: Particle(pos, velo), height(heigh)
{
	acc = acce;
	damp = dam;
	pastPos = { trans->p.x - vel.x, trans->p.y - vel.y, trans->p.z - vel.z };

	mass = mas;
	forces = { 0, 0, 0 };
	statc = false;

	lifetime = lifetim;

	gPhysx = physx;

	size = siz;
	color = col;

	registerRender();
}

void SquarePart::registerRender()
{
	PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	PxShape* cheto = gPhysx->createShape(PxBoxGeometry(size, height, size), *gMaterial);

	render = new RenderItem(cheto, trans, color);
	rendered = true;
}
