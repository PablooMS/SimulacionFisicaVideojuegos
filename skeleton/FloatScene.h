#pragma once
#include "Scene.h"

class FloatScene : public Scene
{
public:
	FloatScene(physx::PxPhysics* physx) : Scene(physx) {}

	virtual void loadScene() override;
};

