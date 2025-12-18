#pragma once
#include "Level.h"

class Level3 : public Level
{
public:
	Level3(physx::PxPhysics* physx, physx::PxScene* pxsc, Camera* ca, std::string nex) : Level(physx, pxsc, ca, nex) {}
	virtual ~Level3() { unloadScene(); };

	virtual void loadScene() override;
};

