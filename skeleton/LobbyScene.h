#pragma once
#include "Scene.h"
#include <vector>

class LobbyScene : public Scene
{
public:
	LobbyScene(physx::PxPhysics* physx, physx::PxScene* pxsc) : Scene(physx, pxsc) {}

	virtual void loadScene() override;
	virtual void unloadScene() override;

private:
	physx::PxTransform* floorT;
	RenderItem* floor;

	std::vector< physx::PxTransform*> buildT;
	std::vector<RenderItem*> buildings;
};

