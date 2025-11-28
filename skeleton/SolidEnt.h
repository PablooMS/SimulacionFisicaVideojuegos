#pragma once
#include "Entity.h"
#include <PxPhysics.h>
#include <PxPhysicsAPI.h>

class SolidEnt : public Entity
{
public:
	SolidEnt(physx::PxPhysics* physx, Vector3 pos) : Entity(pos), gPhysx(physx) {};
	virtual ~SolidEnt() {};
	
	virtual physx::PxRigidActor* getBod() { return nullptr; };

protected:

	physx::PxPhysics* gPhysx;

};

class SolidDyEnt : public SolidEnt
{
public:
	SolidDyEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat,
		Vector3 pos, float dense, float r, Vector4 color);				//Esfera
	SolidDyEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat,
		Vector3 pos, float dense, float w, float h, float d, Vector4 color);	//Cubo
	virtual ~SolidDyEnt();

	virtual physx::PxRigidActor* getBod() override { return mBod; }

private:

	physx::PxRigidBody* mBod;

};

class SolidStEnt : public SolidEnt
{
public:
	SolidStEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat,
		Vector3 pos, float r, Vector4 color);				//Esfera
	SolidStEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat,
		Vector3 pos, float w, float h, float d, Vector4 color);	//Cubo
	virtual ~SolidStEnt();

	virtual physx::PxRigidActor* getBod() override { return mBod; }

private:

	physx::PxRigidActor* mBod;

};

