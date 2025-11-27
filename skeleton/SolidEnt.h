#pragma once
#include "Entity.h"
#include <PxPhysics.h>
#include <PxPhysicsAPI.h>

class SolidEnt : public Entity
{
public:
	SolidEnt(physx::PxPhysics* physx, physx::PxMaterial* mat, 
		Vector3 pos, float dense, float r);				//Esfera
	SolidEnt(physx::PxPhysics* physx, physx::PxMaterial* mat, 
		Vector3 pos, float dense, int w, int h, int d);	//Cubo
	~SolidEnt();

private:

	physx::PxRigidBody* mBod;
	physx::PxPhysics* gPhysx;
};

