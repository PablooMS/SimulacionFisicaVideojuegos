#include "P5Scene.h"
#include <PxPhysics.h>
#include <PxPhysicsAPI.h>
#include "SolidEnt.h"
#include "SolGen.h"

using namespace physx;

P5A1Scene::~P5A1Scene()
{

}

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

	model = new SolidDyEnt(pxScene, gPhysx, gMat, { -100, -100, -100 }, 1000, 2, { 0.8, 1, 0.2, 1.0 });
	model->setRender(false);
	SolidInit sval = { {30, 40, 50}, 15 };
	SolidInit vval = { { 3, 3, 3}, 2 };
	_entMan->createSolidGenerator(model, sval, vval, 1);

	PxMaterial* bouncyMat = gPhysx->createMaterial(0.6f, 0.6f, 1.0f);
	model2 = new SolidDyEnt(pxScene, gPhysx, bouncyMat, { -100, -100, -100 }, 1000, 2, { 0.8, 1, 0.2, 1.0 });
	model2->setRender(false);
	SolidInit sval2 = { {50, 40, 30}, 15 };
	SolidInit vval2 = { { 3, 3, 3}, 2 };
	_entMan->createSolidGenerator(model2, sval2, vval2, 1);
}
