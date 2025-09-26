#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Vector3D.h"
#include "Particle.h"
#include "EntityManager.h";

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

	/* PxShape* cheto = gPhysics->createShape(PxSphereGeometry(3), *gMaterial);
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

	entMan = new EntityManager(gPhysics);
	//entMan->createParticle(Vector3D(), Vector3D(10, 10, 10), Vector3D());
	entMan->createParticle(Vector3D(), Vector3D(0, 0, 0), Vector3D(0,1,0));
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	gScene->fetchResults(true);

	entMan->update(t);
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
void keyPress(unsigned char key, const PxTransform& camera)
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