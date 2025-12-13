#pragma once
#include "Entity.h"
#include <PxPhysics.h>
#include <PxPhysicsAPI.h>

class SolidEnt : public Entity
{
public:
	SolidEnt(physx::PxPhysics* physx, Vector3 pos) : Entity(pos), gPhysx(physx) {};
	virtual ~SolidEnt() {};
	
	virtual physx::PxRigidBody* getBod() { return nullptr; };
	virtual physx::PxRigidActor* getAct() { return nullptr; };

	virtual std::list<SolidEnt*>& generatorSolids() { return std::list<SolidEnt*>(1); }

	virtual void applySolForce(Vector3 f) {};

protected:

	physx::PxPhysics* gPhysx;
	physx::PxShape* form;
	shape s;
};

class SolidDyEnt : public SolidEnt
{
public:
	SolidDyEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat,
		Vector3 pos, float dense, float r, Vector4 color, 
		physx::PxFilterData filter = physx::PxFilterData());				//Esfera
	SolidDyEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat,
		Vector3 pos, float dense, float w, float h, float d, Vector4 color, 
		physx::PxFilterData filter = physx::PxFilterData());				//Cubo
	SolidDyEnt(SolidDyEnt* o, Vector3 pos);
	virtual ~SolidDyEnt();

	virtual physx::PxRigidBody* getBod() override { return mBod; }
	virtual physx::PxRigidActor* getAct() override { return mBod; }
	virtual Vector3 getPos() override { return mBod->getGlobalPose().p; }

	void setPos(Vector3 p);
	void setLifetime(double t);

	virtual void update(double t) override;

	virtual void applySolForce(Vector3 f) override;

protected:

	physx::PxScene* gScene;

	physx::PxRigidBody* mBod;
	physx::PxMaterial* mMat;

	float dense;
	Vector3 dim;
	Vector4 color;

	int lifetime;
	double life = 0;
};

class SolidStEnt : public SolidEnt
{
public:
	SolidStEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat,
		Vector3 pos, float r, Vector4 color,
		physx::PxFilterData filter = physx::PxFilterData());				//Esfera
	SolidStEnt(physx::PxScene* scene, physx::PxPhysics* physx, physx::PxMaterial* mat,
		Vector3 pos, float w, float h, float d, Vector4 color,
		physx::PxFilterData filter = physx::PxFilterData());				//Cubo
	virtual ~SolidStEnt();

	virtual physx::PxRigidActor* getAct() override { return mBod; }

private:

	physx::PxRigidActor* mBod;

};

