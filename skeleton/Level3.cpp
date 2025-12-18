#include "Level3.h"
#include "Float.h"

using namespace physx;

void Level3::loadScene()
{
	Level::loadScene();

	PxMaterial* gMat = gPhysx->createMaterial(0.3f, 0.3f, 0.4f);

	//Lluvia
	Particle* r = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,-10,0 }, 0.95, gPhysx, 0, 10, 0.2, { 0.1, 0.1, 0.6, 1.0 });
	r->setRender(false);
	Initialization str = { {0,200,0}, {5,-100,0}, 10 };
	Initialization vr = { {100,0,100}, {1,0,1}, 0 };
	_entMan->createGenerator(r, str, vr, 10, 0.05, false);

	//Awa
	_forces.push_back(new Float(gPhysx, { 0, -55, 0 }, 100.0, 1000));

	//Suelo
	_entMan->createFloor(gMat, { 0, -1, 45 }, 22, { 0.7, 1, 0.5, 1 });
	_entMan->createFloor(gMat, { 0, -100, 0 }, 500, { 0.7, 1, 0.5, 1 }); //Suelo de emergencia

	//Bloques
	_entMan->createDynamicSolid(gMat, { 30, -5, 0 }, 200, 2, 1, 4, { 1, 1, 0.7, 1 }); 
	_entMan->createDynamicSolid(gMat, { 0, -5, 0 }, 200, 10, 1, 10, { 1, 1, 0.7, 1 }); 

	_entMan->createDynamicSolid(gMat, { -2, 2, -2 }, 200, 1, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 2, 2, -2 }, 200, 1, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 4, -2 }, 200, 4, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { -2, 2, 2 }, 200, 1, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 2, 2, 2 }, 200, 1, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 4, 2 }, 200, 4, 1, 1, { 1, 1, 0.7, 1 });
	_entMan->createDynamicSolid(gMat, { 0, 6, 0 }, 200, 2, 1, 4, { 1, 1, 0.7, 1 });

	//Enemigos
	_entMan->createEnemy({ 30, 0, 0 }, 300, 1.2, &enem);
	_entMan->createEnemy({ 0, 10, 0 }, 300, 1.2, &enem);
	enem = 2;
}
