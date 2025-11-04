#pragma once
#include "Scene.h"
#include <vector>

class GameScene : public Scene
{
public:
	GameScene(physx::PxPhysics* physx) : Scene(physx) {}

	virtual void loadScene() override;
	virtual void unloadScene() override;

private:
	physx::PxTransform* floorT;
	RenderItem* floor;

	std::vector<physx::PxTransform*> buildT;
	std::vector<RenderItem*> buildings;
};

