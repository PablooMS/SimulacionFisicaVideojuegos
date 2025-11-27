#include "SolidEnt.h"

using namespace physx;

SolidDyEnt::SolidDyEnt(physx::PxScene* scene, PxPhysics* physx, PxMaterial* mat, Vector3 pos,
	float dense, float r, Vector4 color) : SolidEnt(physx, pos)
{
	statc = false;
	
	mBod = physx->createRigidDynamic(*trans);

	PxShape* google = gPhysx->createShape(PxSphereGeometry(r), *mat);

	mBod->attachShape(*google); 

	PxRigidBodyExt::updateMassAndInertia(*mBod, dense);

	scene->addActor(*mBod);

	render = new RenderItem(google, mBod, color);
	rendered = true;
}

SolidDyEnt::SolidDyEnt(physx::PxScene* scene, PxPhysics* physx, PxMaterial* mat, Vector3 pos,
	float dense, int w, int h, int d, Vector4 color) : SolidEnt(physx, pos)
{
	statc = false;
	
	mBod = physx->createRigidDynamic(*trans);

	PxShape* google = gPhysx->createShape(PxBoxGeometry(w, h, d), *mat);

	mBod->attachShape(*google);

	PxRigidBodyExt::updateMassAndInertia(*mBod, dense);

	scene->addActor(*mBod);

	render = new RenderItem(google, mBod, color);
	rendered = true;
}

SolidDyEnt::~SolidDyEnt()
{
	mBod->release();
	mBod = nullptr;

	if (rendered)
	{
		render->release();
	}
	render = nullptr;
}


/// /////////////


SolidStEnt::SolidStEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat, Vector3 pos, 
	float dense, float r, Vector4 color) : SolidEnt(physx, pos)
{
	statc = true;

	mBod = physx->createRigidStatic(*trans);

	PxShape* google = gPhysx->createShape(PxSphereGeometry(r), *mat);

	mBod->attachShape(*google);

	scene->addActor(*mBod);

	render = new RenderItem(google, mBod, color);
	rendered = true;
}

SolidStEnt::SolidStEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat, Vector3 pos, 
	float dense, int w, int h, int d, Vector4 color) : SolidEnt(physx, pos)
{
	statc = true;

	mBod = physx->createRigidStatic(*trans);

	PxShape* google = gPhysx->createShape(PxBoxGeometry(w, h, d), *mat);

	mBod->attachShape(*google);

	scene->addActor(*mBod);

	render = new RenderItem(google, mBod, color);
	rendered = true;
}

SolidStEnt::~SolidStEnt()
{
	mBod->release();
	mBod = nullptr;

	if (rendered)
	{
		render->release();
	}
	render = nullptr;
}

