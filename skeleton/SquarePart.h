#pragma once
#include "Particle.h"

class SquarePart : public Particle
{
public:

	SquarePart(Vector3D pos, Vector3D velo, Vector3D acce, float dam, physx::PxPhysics* physx, 
		double mass, double lifetime, float size, float heigh, Vector4 color);

	virtual float getHeight() override { return height; };
	virtual float getVolume() override { return height * pow(size, 2); };
	virtual shape getShape() override { return CUBE; }

private:

	virtual void registerRender() override;

	float height;

};

