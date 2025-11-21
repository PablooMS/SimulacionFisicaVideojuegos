#pragma once
#include "Entity.h"
#include "ForceGen.h"

class Spring : public ForceGen
{
public:
	Spring(physx::PxPhysics* phsx, Entity* e1, Vector3 e2, float length, float konstant);
	Spring(physx::PxPhysics* phsx, Entity* e1, Entity* e2, float length, float konstant);

	virtual void update() override;

private:
	
	float l;
	float k;

	bool twoEnd;
	Entity* ending1;
	Entity* ending2;
	Vector3 end2;
};

