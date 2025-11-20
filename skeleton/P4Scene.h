#pragma once
#include "Scene.h"

class P4Scene : public Scene
{
public:
	P4Scene(physx::PxPhysics* physx) : Scene(physx) {}

	virtual void loadScene() override;
};

