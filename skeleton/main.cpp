#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Vector3D.h"
#include "Particle.h"
#include "EntityManager.h";
#include "SceneManager.h";
#include "Projectile.h";
#include "SceneResource.h"

#include <iostream>


std::string display_text = "This is a test";


using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;


PxMaterial*				gMaterial	= NULL;

PxPvd*                  gPvd        = NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene      = NULL;
ContactReportCallback gContactReportCallback;

EntityManager* entMan;
SceneManager* _scenes;

int shots = 0;


// Initialize physics engine
void initPhysics(bool interactive)
{

	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	//MODIFICAR LA CAMARA
	Camera* cam = GetCamera();

	//PRACTICA 0
	/*PxShape* cheto = gPhysics->createShape(PxSphereGeometry(3), *gMaterial);
	Vector3D pos(10, 0, 0);
	PxTransform* sphTrans = new PxTransform(PxVec3(pos.getX(), pos.getY(), pos.getZ()));
	Vector4 color(1.0, 0.6, 0.1, 1.0);

	RenderItem* rend = new RenderItem(cheto, sphTrans, color);
	RegisterRenderItem(rend);


	PxShape* cheto2 = gPhysics->createShape(PxSphereGeometry(3), *gMaterial);
	Vector3D pos2(0, 10, 0);
	PxTransform* sphTrans1 =  new PxTransform(PxVec3(pos2.getX(), pos2.getY(), pos2.getZ()));
	Vector4 color2(0.6, 0.1, 1.0, 1.0);

	RenderItem* rend2 = new RenderItem(cheto2, sphTrans1, color2);
	RegisterRenderItem(rend2);


	PxShape* cheto3 = gPhysics->createShape(PxSphereGeometry(3), *gMaterial);
	Vector3D pos3(0, 0, 10);
	PxTransform* sphTrans2 =  new PxTransform(PxVec3(pos3.getX(), pos3.getY(), pos3.getZ()));
	Vector4 color3(0.1, 1.0, 0.6, 1.0);

	RenderItem* rend3 = new RenderItem(cheto3, sphTrans2, color3);
	RegisterRenderItem(rend3); */

	//ENTITY MANAGER
	//entMan = new EntityManager(gPhysics, gScene);

	//PRACTICA 1.1
	//entMan->createParticle(Vector3D(), Vector3D(10, 10, 10), Vector3D());
	//entMan->createParticle(Vector3D(), Vector3D(0, 0, 0), Vector3D(0,1,0), 3);

#pragma region PRACTICA 1.2
	/*
	//Flecha Real
	entMan->createProjectile(Vector3D(-2,5,0), Vector3D(80, 20, 0), Vector3D(0, -9.8, 0), 0.025, 10);
	//Flecha adaptada
	entMan->createProjectile(Vector3D(-2,5,0), Vector3D(40, 30, 0), Vector3D(0, -20, 0), 0.25, 10);
	//Suelo y mapa
	PxShape* suelo = gPhysics->createShape(PxBoxGeometry(50, 1, 150), *gMaterial);
	Vector3D pos(50, -5, -75);
	PxTransform* floTrans = new PxTransform(PxVec3(pos.getX(), pos.getY(), pos.getZ()));
	Vector4 color(0.5, 1.0, 0.0, 1.0);
	RenderItem* rend = new RenderItem(suelo, floTrans, color);
	RegisterRenderItem(rend);

	PxShape* diana = gPhysics->createShape(PxSphereGeometry(5), *gMaterial);
	Vector3D pos2(20, 3, -10);
	PxTransform* diaTrans = new PxTransform(PxVec3(pos2.getX(), pos2.getY(), pos2.getZ()));
	Vector4 color2(0.8, 0.3, 1.0, 1.0);
	RenderItem* rend2 = new RenderItem(diana, diaTrans, color2);
	RegisterRenderItem(rend2);

	PxShape* diana2 = gPhysics->createShape(PxSphereGeometry(5), *gMaterial);
	Vector3D pos3(80, 5, -50);
	PxTransform* diaTrans2 = new PxTransform(PxVec3(pos3.getX(), pos3.getY(), pos3.getZ()));
	RenderItem* rend3 = new RenderItem(diana2, diaTrans2, color2);
	RegisterRenderItem(rend3);

	PxShape* diana3 = gPhysics->createShape(PxSphereGeometry(5), *gMaterial);
	Vector3D pos4(50, 5, -120);
	PxTransform* diaTrans3 = new PxTransform(PxVec3(pos4.getX(), pos4.getY(), pos4.getZ()));
	RenderItem* rend4 = new RenderItem(diana3, diaTrans3, color2);
	RegisterRenderItem(rend4);*/
#pragma endregion

#pragma region PRACTICA 2

	//WaterHose
	/*Particle* p = new Particle({0,0,0}, {0,0,0}, {0,-10,0}, 0.95, gPhysics, 10, 1, {0.1, 0.1, 1.0, 1.0});
	p->setRender(false);
	Initialization st = { {0,0,-10}, {50,10,0}, 5 };
	Initialization v = { {1,0,1}, {5,2,2}, 1 };
	entMan->createGenerator(p, st, v, 5, 0.1, true);*/

	//Rain
	/**Particle* r = new Particle({0,0,0}, {0,0,0}, {0,-10,0}, 0.95, gPhysics, 10, 1, {0.1, 0.1, 0.6, 1.0});
	r->setRender(false);
	Initialization str = { {0,300,0}, {5,-100,0}, 10 };
	Initialization vr = { {100,0,100}, {1,0,1}, 0 };
	entMan->createGenerator(r, str, vr, 5, 0.1, false);*/

	//Fog
	/*Particle* f = new Particle({0,0,0}, {0,0,0}, {0,0,0}, 0.95, gPhysics, 10, 5, {0.3, 0.3, 0.3, 1.0});
	f->setRender(false);
	Initialization stf = { {0,50,-100}, {0,0,0}, 20 };
	Initialization vf = { {50,50,50}, {0.5,0.5,0.5}, 5 };
	entMan->createGenerator(f, stf, vf, 5, 0.1, true);*/

	//Fireworks
	/*Particle* fw = new Particle({0,0,0}, {0,0,0}, {0,0,0}, 0.95, gPhysics, 10, 1, {1.0, 0.6, 0.1, 1.0});
	fw->setRender(false);
	Initialization stfw = { {0,0,0}, {0,0,0}, 2 };
	Initialization vfw = { {0,0,0}, {10,10,10}, 0.5 };
	Initialization ist = { {50,0,-150}, {0,100,0}, 3 };
	Initialization iv = { {0,0,0}, {10,5,10}, 1 };
	entMan->createFireworks(fw, stfw, vfw, 3, 5, true, ist, iv, 3);*/
#pragma endregion
	
	//SCENE MANAGER
	_scenes = new SceneManager();

	P2Scene* es = new P2Scene(gPhysics, gScene);
	_scenes->registerScene(es, "P2");		// Escena practica 2

	GScene* g = new GScene(gPhysics, gScene);
	_scenes->registerScene(g, "Grav");		// Escena practica 3 pt 1 (gravedad)

	P3Scene* sc = new P3Scene(gPhysics, gScene);
	_scenes->registerScene(sc, "P3");		// Escena práctica 3 pt 2

	LobbyScene* l = new LobbyScene(gPhysics, gScene);
	_scenes->registerScene(l, "Lobby");

	GameScene* game = new GameScene(gPhysics, gScene);
	_scenes->registerScene(game, "Game");

	P4Scene* p4 = new P4Scene(gPhysics, gScene);
	_scenes->registerScene(p4, "P4");

	FloatScene* f = new FloatScene(gPhysics, gScene);
	_scenes->registerScene(f, "Flo");

	P5A1Scene* p5a1 = new P5A1Scene(gPhysics, gScene);
	_scenes->registerScene(p5a1, "P5a1");

	_scenes->changeScene("Lobby");
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	gScene->fetchResults(true);

	//entMan->update(t);
	_scenes->update(t);
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	
	gFoundation->release();
}

// Function called when a key is pressed
void keyPress(unsigned char key, const Camera& camera)
{
	PX_UNUSED(camera);

	switch(toupper(key))
	{
	//case 'B': break;
	//case ' ':	break;
	case ' ':
	{
		break;
	}
	case 'B':
	{
		if (_scenes->currentScene() != "P3" && _scenes->currentScene() != "Game")
			break;

		//Flecha Real
		PxVec3 cameraPos = camera.getTransform().p;
		Vector3D camPos(cameraPos.x, cameraPos.y, cameraPos.z);
		Vector3D dir(camera.getDir().x * 80, camera.getDir().y * 80, camera.getDir().z * 80);
		
		_scenes->requestEntMan()->createProjectile(camPos, dir, Vector3D(0, -9.8, 0), 5, 10, 1, { 1.0, 1.0, 1.0, 1.0 });

		//Versión simple
		//entMan->createProjectile(Vector3D(-2, 5, 0), Vector3D(80, 10, 0), Vector3D(0, -9.8, 0), 0.025, 10);

		shots++;
		if (shots > 10)
		{
			shots = 0;
			_scenes->handleEvent(SceneEvents::Explode);
		}
		break;
	}
	case 'V':
	{
		if (_scenes->currentScene() != "P3" && _scenes->currentScene() != "Game")
			break;

		//Flecha adaptada
		PxVec3 cameraPos = camera.getTransform().p;
		Vector3D camPos(cameraPos.x, cameraPos.y, cameraPos.z);
		Vector3D dir(camera.getDir().x * 40, camera.getDir().y * 40, camera.getDir().z * 40);

		_scenes->requestEntMan()->createProjectile(camPos, dir, Vector3D(0, -9.8, 0), 10, 10, 1, {1.0, 1.0, 1.0, 1.0});

		// Versión simple
		//entMan->createProjectile(Vector3D(-2, 5, 0), Vector3D(40, 30, 0), Vector3D(0, -30, 0), 0.25, 10); 

		shots++;
		if (shots > 10)
		{
			shots = 0;
			_scenes->handleEvent(SceneEvents::Explode);
		}
		break;
	}
	case 'N':
	{
		if (_scenes->currentScene() != "P3" && _scenes->currentScene() != "Game")
			break;

		//Bala
		PxVec3 cameraPos = camera.getTransform().p;
		Vector3D camPos(cameraPos.x, cameraPos.y, cameraPos.z);
		Vector3D dir(camera.getDir().x * 200, camera.getDir().y * 200, camera.getDir().z * 200);

		_scenes->requestEntMan()->createProjectile(camPos, dir, Vector3D(0, -9.8, 0), 20, 10, 0.3, { 1.0, 1.0, 1.0, 1.0 });

		shots++;
		if (shots > 10)
		{
			shots = 0;
			_scenes->handleEvent(SceneEvents::Explode);
		}
		break;
	}
	case 'M':
	{
		if (_scenes->currentScene() != "P3" && _scenes->currentScene() != "Game")
			break;

		_scenes->handleEvent(SceneEvents::Explode);
		break;
	}
	case 'A':
	{
		GetCamera()->shiftPos({ 10, 0, 0 });
		break;
	}
	case 'D':
	{
		GetCamera()->shiftPos({ -10, 0, 0 });
		break;
	}
	case '1':
	{
		_scenes->changeScene("Lobby");
		GetCamera()->setPos(PxVec3(50.0f, 20.0f, 200.0f), PxVec3(0.0f, 0.0f, -0.7f));
		break;
	}
	case '2':
	{
		_scenes->changeScene("Game");
		GetCamera()->setPos(PxVec3(50.0f, 20.0f, 100.0f), PxVec3(0.0f, 0.0f, -0.7f));
		break;
	}
	case '3':
	{
		_scenes->changeScene("P3");
		GetCamera()->setPos(PxVec3(50.0f, 20.0f, 50.0f), PxVec3(0.0f, 0.0f, -0.7f));
		break;
	}
	case '4':
	{
		_scenes->changeScene("P2");
		GetCamera()->setPos(PxVec3(0.0f, 20.0f, 0.0f), PxVec3(0.0f, 0.0f, -0.7f));
		break;
	}
	case '5':
	{
		_scenes->changeScene("Grav");
		GetCamera()->setPos(PxVec3(50.0f, 20.0f, 50.0f), PxVec3(0.0f, 0.0f, -0.7f));
		break;
	}
	case '6':
	{
		_scenes->changeScene("P4");
		GetCamera()->setPos(PxVec3(0.0f, 20.0f, 100.0f), PxVec3(0.0f, 0.0f, -0.7f));
		break;
	}
	case '7':
	{
		_scenes->changeScene("Flo");
		GetCamera()->setPos(PxVec3(0.0f, 0.0f, 100.0f), PxVec3(0.0f, -0.0f, -0.7f));
		break;
	}
	case '8':
	{
		_scenes->changeScene("P5a1");
		GetCamera()->setPos(PxVec3(40.0f, 20.0f, 40.0f), PxVec3(-0.5f, -0.1f, -0.5f));
		break;
	}
	default:
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}


int main(int, const char*const*)
{
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}