#pragma once
#include "Scene.h"

class GScene : public Scene
{
public:
	GScene(physx::PxPhysics* physx, physx::PxScene* pxsc) : Scene(physx, pxsc) {}

	virtual void loadScene() override;
};