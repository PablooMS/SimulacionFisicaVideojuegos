#include "Level1.h"

using namespace physx;

void Level1::loadScene()
{
	Level::loadScene();

	PxMaterial* gMat = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	_entMan->createStaticSolid(gMat, { 0, 0, 0 }, 40, 1, 40, { 0.7, 1, 0.5, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 3, 0 }, 1000, 2, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 8, 3, 0 }, 1000, 2, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 4, 8, 0 }, 1000, 8, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 3, 8 }, 1000, 2, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 8, 3, 8 }, 1000, 2, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 4, 8, 8 }, 1000, 8, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 4, 12, 4 }, 1000, 4, 2, 8, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 4, 16, 8 }, 1000, 1.2, 0.8, 12, { 1, 1, 0.7, 1 });
}
