#include "Level2.h"
#include "Wind.h"

using namespace physx;

void Level2::loadScene()
{
	Level::loadScene();

	PxMaterial* gMat = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	//Suelo
	_entMan->createFloor(gMat, { 0, -1, 0 }, 100, { 0.7, 1, 0.5, 1 });
	_entMan->createFloor(gMat, { 0, -100, 0 }, 500, { 0.7, 1, 0.5, 1 }); //Suelo de emergencia

	//Lluvia
	/*Particle* r = new Particle({0,0,0}, {0,0,0}, {0,-10,0}, 0.95, gPhysx, 0, 10, 0.2, {0.1, 0.1, 0.6, 1.0});
	r->setRender(false);
	Initialization str = { {0,200,0}, {5,-100,0}, 10 };
	Initialization vr = { {100,0,100}, {1,0,1}, 0 };
	_entMan->createGenerator(r, str, vr, 10, 0.05, false);*/

	//Fuerzas
	_forces.push_back(new Wind({-100, 5, 100}, gPhysx, 0.8, 0.1, {20, 5, -10}, SPHERE, 15, 10, true));

	//Particulas para el viento
	Particle* f = new Particle({ 0,0,0 }, { 0,0,0 }, { 0,0,0 }, 0.95, gPhysx, 0.1, 3, 0.2, { 0.3, 0.3, 0.3, 1.0 });
	f->setRender(false);
	Initialization stf = { {20,5,-10}, {0,0,0}, 3 };
	Initialization vf = { {5,5,5}, {0.5,0.5,0.5}, 0.2 };
	_entMan->createGenerator(f, stf, vf, 5, 0.1, true);

	//Ventana
	SolidStEnt* glass = _entMan->createStaticSolid(gMat, { 0, 8, 10 }, 10, 8, 1, { 1, 1, 0.7, 0 });
	glass->setRender(false);
	_entMan->createStaticSolid(gMat, { 0, 0, 10 }, 10, 1, 1, { 0.7, 0.4, 1, 0 });
	_entMan->createStaticSolid(gMat, {0, 16, 10}, 10, 1, 1, { 0.7, 0.4, 1, 0});
	_entMan->createStaticSolid(gMat, { 9.5, 8, 10 }, 1, 8, 1, { 0.7, 0.4, 1, 0 });
	_entMan->createStaticSolid(gMat, { -9.5, 8, 10 }, 1, 8, 1, { 0.7, 0.4, 1, 0 });

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
	_entMan->createEnemy({ 0, 10, 0 }, 800, 1.2, &enem);
	enem = 1;
}
