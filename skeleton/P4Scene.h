#pragma once
#include "Scene.h"

class P4Scene : public Scene
{
public:
	P4Scene(physx::PxPhysics* physx, physx::PxScene* pxsc) : Scene(physx, pxsc) {}

	virtual void loadScene() override;
};

