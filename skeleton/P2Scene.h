#pragma once
#include "Scene.h"

class P2Scene : public Scene
{
public:
	P2Scene(physx::PxPhysics* physx) : Scene(physx) {}

	virtual void loadScene() override;
};

