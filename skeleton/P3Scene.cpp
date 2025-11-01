#include "P3Scene.h"
#include <PxPhysics.h>
#include <PxPhysicsAPI.h>

void P3Scene::loadScene()
{
	physx::PxMaterial* gMaterial = gPhysx->createMaterial(0.5f, 0.5f, 0.6f);

	//Suelo y mapa
	physx::PxShape* suelo = gPhysx->createShape(physx::PxBoxGeometry(50, 1, 150), *gMaterial);
	Vector3D pos(50, -5, -75);
	physx::PxTransform* floTrans = new physx::PxTransform(physx::PxVec3(pos.getX(), pos.getY(), pos.getZ()));
	Vector4 color(0.5, 1.0, 0.0, 1.0);
	RenderItem* rend = new RenderItem(suelo, floTrans, color);
	RegisterRenderItem(rend);

	Vector4 color2(0.8, 0.3, 1.0, 1.0);
	_entMan->createParticle({ 20, 3, -10 }, { 0, 0, 0 }, { 0, 0, 0 }, -1, 5, color2);
	_entMan->createParticle({ 80, 5, -50 }, { 0, 0, 0 }, { 0, 0, 0 }, -1, 5, color2);
	_entMan->createParticle({ 50, 5, -120 }, { 0, 0, 0 }, { 0, 0, 0 }, -1, 5, color2);

	/*
	physx::PxShape* diana = gPhysx->createShape(physx::PxSphereGeometry(5), *gMaterial);
	Vector3D pos2(20, 3, -10);
	physx::PxTransform* diaTrans = new physx::PxTransform(physx::PxVec3(pos2.getX(), pos2.getY(), pos2.getZ()));
	
	RenderItem* rend2 = new RenderItem(diana, diaTrans, color2);
	RegisterRenderItem(rend2);

	physx::PxShape* diana2 = gPhysx->createShape(physx::PxSphereGeometry(5), *gMaterial);
	Vector3D pos3(80, 5, -50);
	physx::PxTransform* diaTrans2 = new physx::PxTransform(physx::PxVec3(pos3.getX(), pos3.getY(), pos3.getZ()));
	RenderItem* rend3 = new RenderItem(diana2, diaTrans2, color2);
	RegisterRenderItem(rend3);

	physx::PxShape* diana3 = gPhysx->createShape(physx::PxSphereGeometry(5), *gMaterial);
	Vector3D pos4(50, 5, -120);
	physx::PxTransform* diaTrans3 = new physx::PxTransform(physx::PxVec3(pos4.getX(), pos4.getY(), pos4.getZ()));
	RenderItem* rend4 = new RenderItem(diana3, diaTrans3, color2);
	RegisterRenderItem(rend4);*/
}
