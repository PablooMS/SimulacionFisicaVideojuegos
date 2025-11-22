 #pragma once
#include "ForceGen.h"

class Float : public ForceGen
{
public:
	Float(physx::PxPhysics* phsx, Vector3 po, float r, float dense);

	virtual ~Float() 
	{
		renderTop->release();
		//renderBot->release();
	};

protected:

	void startUpRender();

	virtual void applyForce(Entity* p) override;

	float density;
	float h0;

	physx::PxTransform* transTop;
	RenderItem* renderTop;
	/*physx::PxTransform* transBot;
	RenderItem* renderBot;*/
	bool rendering;
};

