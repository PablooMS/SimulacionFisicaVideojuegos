#include "GameSolids.h"

Enemy::Enemy(physx::PxScene* scene, physx::PxPhysics* physx, Vector3 pos, float dense, float r, int* cont)
	: SolidDyEnt(scene, physx, gPhysx->createMaterial(0.5f, 0.5f, 0.8f), pos, dense, r, {0, 1, 0, 1}),
	en_cont(cont)
{
	physx::PxFilterData enemyFilter;
	enemyFilter.word0 = LAYER_ENEMY;
	enemyFilter.word1 = LAYER_DEFAULT | LAYER_BULLET | LAYER_FLOOR | LAYER_BARREL;
	form->setSimulationFilterData(enemyFilter);

	mBod->userData = this;
}

void Enemy::die()
{
	*en_cont -= 1;
	_toDestroy = true;
}

Barrel::Barrel(physx::PxScene* scene, physx::PxPhysics* physx, Vector3 pos, 
	float dense, float w, float h, float d, Explosive* exp)
	: SolidDyEnt(scene, physx, gPhysx->createMaterial(0.8f, 0.8f, 0.3f), pos, dense, w, h, d, { 1, 0, 0, 1 }),
	ex(exp)
{
	physx::PxFilterData barrelFilter;
	barrelFilter.word0 = LAYER_BARREL;
	barrelFilter.word1 = LAYER_DEFAULT | LAYER_BULLET | LAYER_ENEMY | LAYER_FLOOR;
	form->setSimulationFilterData(barrelFilter);

	mBod->userData = this;
}

void Barrel::boom()
{
	ex->explode();
	_toDestroy = true;
}

Bullet::Bullet(physx::PxScene* scene, physx::PxPhysics* physx, Vector3 pos, float life, float dense, float r)
	: SolidDyEnt(scene, physx, gPhysx->createMaterial(0.5f, 0.5f, 0.4f), pos, dense, r, { 0.3, 0.3, 0.3, 1 })
{
	lifetime = life;

	physx::PxFilterData bulletFilter;
	bulletFilter.word0 = LAYER_BULLET;
	bulletFilter.word1 = LAYER_DEFAULT | LAYER_ENEMY | LAYER_FLOOR | LAYER_BARREL;
	form->setSimulationFilterData(bulletFilter);

	mBod->userData = this;
}
