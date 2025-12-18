#include "SolidEnt.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

using namespace physx;

SolidDyEnt::SolidDyEnt(physx::PxScene* scene, PxPhysics* physx, PxMaterial* mat, Vector3 pos,
	float dens, float r, Vector4 col, physx::PxFilterData filter)
	: SolidEnt(physx, pos), dense(dens), mMat(mat), color(col)
{
	statc = false;
	gScene = scene;
	
	mBod = physx->createRigidDynamic(*trans);

	form = gPhysx->createShape(PxSphereGeometry(r), *mat);
	dim = Vector3(r, 0, 0);

	//Añadir filtors
	form->setSimulationFilterData(filter);

	mBod->attachShape(*form); 

	PxRigidBodyExt::updateMassAndInertia(*mBod, dense);

	scene->addActor(*mBod);

	render = new RenderItem(form, mBod, color);
	rendered = true;

	s = SPHERE;
}

SolidDyEnt::SolidDyEnt(physx::PxScene* scene, PxPhysics* physx, PxMaterial* mat, Vector3 pos,
	float dens, float w, float h, float d, Vector4 col, physx::PxFilterData filter)
	: SolidEnt(physx, pos), dense(dens), mMat(mat), color(col)
{
	statc = false;
	gScene = scene;
	
	mBod = physx->createRigidDynamic(*trans);

	form = gPhysx->createShape(PxBoxGeometry(w, h, d), *mat);
	dim = Vector3(w, h, d);

	form->setSimulationFilterData(filter);

	mBod->attachShape(*form);

	PxRigidBodyExt::updateMassAndInertia(*mBod, dense);

	scene->addActor(*mBod);

	render = new RenderItem(form, mBod, color);
	rendered = true;

	s = CUBE;
}

SolidDyEnt::SolidDyEnt(SolidDyEnt* o, Vector3 pos)
	: SolidEnt(o->gPhysx, pos)
{
	statc = false;
	s = o->s;
	gScene = o->gScene;
	mMat = o->mMat;
	dense = o->dense;
	dim = o->dim;
	color = o->color;
	lifetime = o->lifetime;

	mBod = gPhysx->createRigidDynamic(*trans);

	PxShape* gog;

	if (s == SPHERE)
		gog = gPhysx->createShape(PxSphereGeometry(dim.x), *mMat);

	else
		gog = gPhysx->createShape(PxBoxGeometry(dim.x, dim.y, dim.z), *mMat);

	mBod->attachShape(*gog);

	PxRigidBodyExt::updateMassAndInertia(*mBod, dense);

	gScene->addActor(*mBod);

	render = new RenderItem(gog, mBod, color);
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

float SolidDyEnt::getVolume()
{
	if (s == SPHERE)
		return dim.x * dim.x * M_PI;

	if (s == CUBE)
		return 8 * dim.x * dim.y * dim.z;

	return dim.x * dim.x * dim.x;
}

void SolidDyEnt::setPos(Vector3 p)
{
	//std::cout << p.x << " " << p.y << " " << p.z << "\n";
	trans->p = p;
}

void SolidDyEnt::setLifetime(double t)
{
	lifetime = t;
}

void SolidDyEnt::update(double t)
{
	if (lifetime > 0)
	{
		life += t;

		if (life > lifetime)
			_toDestroy = true;
	}
}

void SolidDyEnt::applySolForce(Vector3 f)
{
	mBod->addForce(f);
	std::cout << f.y / mBod->getMass() << "\n\n";
}

/// /////////////


SolidStEnt::SolidStEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat, Vector3 pos, 
	float r, Vector4 color, physx::PxFilterData filter) : SolidEnt(physx, pos)
{
	statc = true;

	mBod = physx->createRigidStatic(*trans);

	form = gPhysx->createShape(PxSphereGeometry(r), *mat);
	form->setSimulationFilterData(filter);

	mBod->attachShape(*form);

	scene->addActor(*mBod);

	render = new RenderItem(form, mBod, color);
	rendered = true;

	s = SPHERE;
}

SolidStEnt::SolidStEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat, Vector3 pos, 
	float w, float h, float d, Vector4 color, physx::PxFilterData filter) : SolidEnt(physx, pos)
{
	statc = true;

	mBod = physx->createRigidStatic(*trans);

	form = gPhysx->createShape(PxBoxGeometry(w, h, d), *mat);
	form->setSimulationFilterData(filter);

	mBod->attachShape(*form);

	scene->addActor(*mBod);

	render = new RenderItem(form, mBod, color);
	rendered = true;

	s = CUBE;
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

