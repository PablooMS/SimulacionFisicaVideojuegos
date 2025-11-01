#pragma once
#include "ForceGen.h"

class Torbellino : public ForceGen
{
public:

	Torbellino(physx::PxPhysics* phsx, float strength, float roza, float turbo)
		: K(strength), roz(roza), turb(turbo), ForceGen({0, 0, 0}, phsx) {}
	Torbellino(physx::PxPhysics* phsx, float strength, float roza, float turbo, Vector3 po, shape s, float r, float h, bool rendr)
		: K(strength), roz(roza), turb(turbo), ForceGen({0, 0, 0}, phsx, po, s, r, h) {}
	virtual ~Torbellino() {}

protected:

	virtual void applyForce(Entity* p) override;

	float K;

	float roz;
	float turb;
};

