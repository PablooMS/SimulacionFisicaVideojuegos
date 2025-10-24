#pragma once
#include "Scene.h"

class P3Scene : public Scene
{
public:
	P3Scene(physx::PxPhysics* physx) : Scene(physx) {}

	virtual void loadScene() override;
};
