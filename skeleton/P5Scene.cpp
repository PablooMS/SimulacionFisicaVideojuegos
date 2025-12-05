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

	_entMan->createStaticSolid(gMat, { 0, 0, 0 }, 40, 1, 40, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 3, 0 }, 1000, 2, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 8, 3, 0 }, 1000, 2, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 4, 8, 0 }, 1000, 8, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 3, 8 }, 1000, 2, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 8, 3, 8 }, 1000, 2, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 4, 8, 8 }, 1000, 8, 2, 2, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 4, 12, 4 }, 1000, 4, 2, 8, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 4, 16, 8 }, 1000, 1.2, 0.8, 12, { 1, 1, 0.7, 1 });

	model = new SolidDyEnt(pxScene, gPhysx, gMat, {-100, -100, -100}, 10, 1, {0.8, 1, 0.2, 1.0});
	model->setRender(false);
	SolidInit sval = { {12, 16, 20}, 15 };
	SolidInit vval = { { 1, 1, 1}, 2 };
	_entMan->createSolidGenerator(model, sval, vval, 1);

	PxMaterial* bouncyMat = gPhysx->createMaterial(0.6f, 0.6f, 1.0f);
	model2 = new SolidDyEnt(pxScene, gPhysx, bouncyMat, { -100, -100, -100 }, 10, 1, { 0.8, 1, 0.2, 1.0 });
	model2->setRender(false);
	SolidInit sval2 = { {20, 16, 12}, 15 };
	SolidInit vval2 = { { 1, 1, 1}, 2 };
	_entMan->createSolidGenerator(model2, sval2, vval2, 1);

	_forces.push_back(new ForceGen({ 0, 0, 60 }, gPhysx, {-20, 0, 0}, CUBE, 10.0, 5));
	//_forces.push_back(new ForceGen({ 0, 0, 1000 }, gPhysx));

	PxMaterial* iceMat = gPhysx->createMaterial(0.05f, 0.05f, 0.2f);
	model3 = new SolidDyEnt(pxScene, gPhysx, iceMat, { -100, -100, -100 }, 1000, 1, 1, 1, { 0.7, 0.7, 1.0, 1.0 });
	model3->setRender(false);
	SolidInit sval3 = { {-20, 2, 0}, 20 };
	SolidInit vval3 = { { 4, 1, 4}, 0 };
	_entMan->createSolidGenerator(model3, sval3, vval3, 2);
}
