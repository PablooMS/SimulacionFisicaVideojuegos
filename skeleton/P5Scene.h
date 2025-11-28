#pragma once
#include "Scene.h"

class P5A1Scene : public Scene
{
public:
	P5A1Scene(physx::PxPhysics* physx, physx::PxScene* pxsc) : Scene(physx, pxsc) {}

	virtual void loadScene() override;
};

