#pragma once
#include "ForceGen.h"

class Explosive : public ForceGen
{
public: 
	Explosive(physx::PxPhysics* phsx, Vector3 po, float r, double tc, float K) 
		: timeC(tc), intensity(K), exploding(false), ForceGen({ 0,0,0 }, phsx, po, SPHERE, r, 0) {}
	virtual ~Explosive() {};

	void explode();
	void setPosition(Vector3 pos);

	virtual void handleEvent(ForceEvents evt) override;

private:

	virtual void applyForce(Entity* p) override;
	virtual void applySolForce(SolidEnt* p) override;

	double timeC;
	float intensity;

	bool exploding;
};

