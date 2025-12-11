#pragma once
#include "Level.h"

class Level1 : public Level
{
public:
	Level1(physx::PxPhysics* physx, physx::PxScene* pxsc, Camera* ca, std::string nex) : Level(physx, pxsc, ca, nex) {}
	virtual ~Level1() { unloadScene(); };

	virtual void loadScene() override;
};

