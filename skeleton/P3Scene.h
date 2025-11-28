#pragma once
#include "Scene.h"

class P3Scene : public Scene
{
public:
	P3Scene(physx::PxPhysics* physx, physx::PxScene* pxsc) : Scene(physx, pxsc) {}

	virtual void loadScene() override;
};
