#pragma once
#include "Scene.h"

class P5A1Scene : public Scene
{
public:

	P5A1Scene(physx::PxPhysics* physx, physx::PxScene* pxsc) : Scene(physx, pxsc) {}
	~P5A1Scene();

	virtual void loadScene() override;

private:

	SolidDyEnt* model;
	SolidDyEnt* model2;
};

