#include "GameSolids.h"

Enemy::Enemy(physx::PxScene* scene, physx::PxPhysics* physx, Vector3 pos, float dense, float r, int* cont)
	: SolidDyEnt(scene, physx, gPhysx->createMaterial(0.5f, 0.5f, 0.8f), pos, dense, r, {0, 1, 0, 1}),
	en_cont(cont)
{

}

Barrel::Barrel(physx::PxScene* scene, physx::PxPhysics* physx, Vector3 pos, 
	float dense, float w, float h, float d, Explosive* exp)
	: SolidDyEnt(scene, physx, gPhysx->createMaterial(0.8f, 0.8f, 0.3f), pos, dense, w, h, d, { 1, 0, 0, 1 }),
	ex(exp)
{

}

Bullet::Bullet(physx::PxScene* scene, physx::PxPhysics* physx, Vector3 pos, float life, float dense, float r)
	: SolidDyEnt(scene, physx, gPhysx->createMaterial(0.5f, 0.5f, 0.4f), pos, dense, r, { 0.3, 0.3, 0.3, 1 })
{
	lifetime = life;
}
