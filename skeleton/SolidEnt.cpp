#include "SolidEnt.h"

using namespace physx;


SolidEnt::SolidEnt(PxPhysics* physx, PxMaterial* mat, Vector3 pos, float dense, float r)
	: Entity(pos), gPhysx(physx)
{
	statc = false;
	
	mBod = physx->createRigidDynamic(*trans);

	mBod->attachShape(*gPhysx->createShape(PxSphereGeometry(r), *mat)); 

	PxRigidBodyExt::updateMassAndInertia(*mBod, dense);
}

SolidEnt::SolidEnt(PxPhysics* physx, PxMaterial* mat, Vector3 pos, float dense, int w, int h, int d)
	: Entity(pos), gPhysx(physx)
{
	statc = false;
	
	mBod = physx->createRigidDynamic((*trans));

	mBod->attachShape(*gPhysx->createShape(PxBoxGeometry(w, h, d), *mat));
}

SolidEnt::~SolidEnt()
{
}
