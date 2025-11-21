#pragma once
#include "ForceGen.h"

class Float : public ForceGen
{
public:
	Float(physx::PxPhysics* phsx, Vector3 po, float r) : ForceGen({ 0, 0, 0 }, gPhysx, po, CUBE, r, r) {};
};

