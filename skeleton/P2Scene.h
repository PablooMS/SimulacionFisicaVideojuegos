#pragma once
#include "Scene.h"

class P2Scene : public Scene
{
public:
	P2Scene(physx::PxPhysics* physx, physx::PxScene* pxsc) : Scene(physx, pxsc) {}

	virtual void loadScene() override;
};

