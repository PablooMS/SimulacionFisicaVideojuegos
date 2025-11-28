#include "P5Scene.h"
#include <PxPhysics.h>
#include <PxPhysicsAPI.h>

using namespace physx;

void P5A1Scene::loadScene()
{
	PxMaterial* gMat = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	_entMan->createStaticSolid(gMat, { 0, 0, 0 }, 100, 0.5, 100, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 6, 0 }, 1000, 5, 5, 5, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 20, 6, 0 }, 1000, 5, 5, 5, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 10, 20, 0 }, 1000, 20, 5, 5, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 6, 20 }, 1000, 5, 5, 5, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 20, 6, 20 }, 1000, 5, 5, 5, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 10, 20, 20 }, 1000, 20, 5, 5, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 10, 30, 10 }, 1000, 10, 5, 20, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 10, 40, 20 }, 1000, 3, 2, 30, { 1, 1, 0.7, 1 });
}
