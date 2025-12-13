#include "Level1.h"

using namespace physx;

void Level1::loadScene()
{
	Level::loadScene();

	PxMaterial* gMat = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	//Suelo
	_entMan->createFloor(gMat, { 0, -1, 0 }, 100, { 0.7, 1, 0.5, 1 });
	_entMan->createFloor(gMat, { 0, -100, 0 }, 500, { 0.7, 1, 0.5, 1 }); //Suelo de emergencia

	//Bloques
	_entMan->createDynamicSolid(gMat, { -2, 2, -2 }, 800, 1, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 2, 2, -2 }, 800, 1, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 4, -2 }, 800, 4, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { -2, 2, 2 }, 800, 1, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 2, 2, 2 }, 800, 1, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 4, 2 }, 800, 4, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 6, 0 }, 800, 2, 1, 4, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 8, 2 }, 800, 0.5, 0.5, 6, { 1, 1, 0.7, 1 });

	//Enemigos
	_entMan->createEnemy({ 20, 5, 0 }, 1000, 1.2, &enem);
	_entMan->createEnemy({ 0, 10, 0 }, 1000, 1.2, &enem);
	_entMan->createEnemy({ 6, 5, 0 }, 1000, 1.2, &enem);


	//Barriles
	Explosive* bar = new Explosive(gPhysx, { 0, 0, 0 }, 5, 0.3, 5000);
	_forces.push_back(bar);
	_entMan->createBarrel({ 6, 2, 0 }, 800, 1.5, bar);

	enem = 3;
}
