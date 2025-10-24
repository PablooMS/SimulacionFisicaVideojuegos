#include "P2Scene.h"

void P2Scene::loadScene()
{
	//WaterHose
	/*Particle* p = new Particle({0,0,0}, {0,0,0}, {0,-10,0}, 0.95, gPhysx, 10, 1, {0.1, 0.1, 1.0, 1.0});
	p->setRender(false);
	Initialization st = { {0,0,-10}, {50,10,0}, 5 };
	Initialization v = { {1,0,1}, {5,2,2}, 1 };
	_entMan->createGenerator(p, st, v, 5, 0.1, true);*/

	//Rain
	Particle* r = new Particle({0,0,0}, {0,0,0}, {0,-10,0}, 0.95, gPhysx, 10, 1, {0.1, 0.1, 0.6, 1.0});
	r->setRender(false);
	Initialization str = { {0,300,0}, {5,-100,0}, 10 };
	Initialization vr = { {100,0,100}, {1,0,1}, 0 };
	_entMan->createGenerator(r, str, vr, 5, 0.1, false);

	//Fog
	/*Particle* f = new Particle({0,0,0}, {0,0,0}, {0,0,0}, 0.95, gPhysx, 10, 5, {0.3, 0.3, 0.3, 1.0});
	f->setRender(false);
	Initialization stf = { {0,50,-100}, {0,0,0}, 20 };
	Initialization vf = { {50,50,50}, {0.5,0.5,0.5}, 5 };
	_entMan->createGenerator(f, stf, vf, 5, 0.1, true);*/

	//Fireworks
	/*Particle* fw = new Particle({0,0,0}, {0,0,0}, {0,0,0}, 0.95, gPhysx, 10, 1, {1.0, 0.6, 0.1, 1.0});
	fw->setRender(false);
	Initialization stfw = { {0,0,0}, {0,0,0}, 2 };
	Initialization vfw = { {0,0,0}, {10,10,10}, 0.5 };
	Initialization ist = { {50,0,-150}, {0,100,0}, 3 };
	Initialization iv = { {0,0,0}, {10,5,10}, 1 };
	_entMan->createFireworks(fw, stfw, vfw, 3, 5, true, ist, iv, 3);*/
}
