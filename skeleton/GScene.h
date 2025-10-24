#pragma once
#include "Scene.h"

class GScene : public Scene
{
public:
	GScene(physx::PxPhysics* physx) : Scene(physx) {}

	virtual void loadScene() override;
};