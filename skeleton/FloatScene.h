#pragma once
#include "Scene.h"

class FloatScene : public Scene
{
public:
	FloatScene(physx::PxPhysics* physx, physx::PxScene* pxsc) : Scene(physx, pxsc) {}

	virtual void loadScene() override;
};

