#include "SquarePart.h"
#include <PxPhysicsAPI.h>

using namespace physx;

SquarePart::SquarePart(Vector3D pos, Vector3D velo, Vector3D acce, float dam, physx::PxPhysics* physx, 
	double mass, double lifetime, float size, float heigh, Vector4 color) 
	: Particle(pos, velo, acce, dam, physx, mass, lifetime, size, color), height(heigh)
{
}

void SquarePart::registerRender()
{
	PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	PxShape* cheto = gPhysx->createShape(PxBoxGeometry(size, height, size), *gMaterial);

	render = new RenderItem(cheto, trans, color);
	rendered = true;
}
