#pragma once
#include "ForceGen.h"

class Wind : public ForceGen
{
public:

	Wind(Vector3 spee, physx::PxPhysics* phsx, float roza, float turbo) : speed(spee), roz(roza), turb(turbo), ForceGen({ 0, 0, 0 }, phsx) {}
	Wind(Vector3 spee, physx::PxPhysics* phsx, float roza, float turbo, Vector3 po, shape s, float r, float h, bool rendr);
	virtual ~Wind() 
	{ 
		if(rendering)
			render->release();
	}

protected:

	void startUpRender();

	virtual void applyForce(Entity* p) override;

	Vector3 speed;
	float roz;
	float turb;

	RenderItem* render;
	bool rendering;

};

