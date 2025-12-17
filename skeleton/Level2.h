#pragma once
#include "Level.h"

class Level2 : public Level
{
public:
	Level2(physx::PxPhysics* physx, physx::PxScene* pxsc, Camera* ca, std::string nex) : Level(physx, pxsc, ca, nex) {}
	virtual ~Level2() { unloadScene(); };

	virtual void loadScene() override;
};

