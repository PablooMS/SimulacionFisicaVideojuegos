#include "GameSolids.h"
#include <iostream>

Enemy::Enemy(physx::PxScene* scene, physx::PxPhysics* physx, Vector3 pos, float dense, float r, int* cont)
	: SolidDyEnt(scene, physx, physx->createMaterial(0.5f, 0.5f, 0.8f), pos, dense, r, {0, 1, 0, 1}, filterData()),
	en_cont(cont)
{
	mBod->userData = this;
}

void Enemy::die()
{
	*en_cont -= 1;
	_toDestroy = true;
}

physx::PxFilterData Enemy::filterData()
{
	physx::PxFilterData enemyFilter;
	enemyFilter.word0 = LAYER_ENEMY;
	enemyFilter.word1 = LAYER_DEFAULT | LAYER_BULLET | LAYER_FLOOR | LAYER_BARREL;
	return enemyFilter;
}






Barrel::Barrel(physx::PxScene* scene, physx::PxPhysics* physx, Vector3 pos, 
	float dense, float w, float h, float d, Explosive* exp)
	: SolidDyEnt(scene, physx, physx->createMaterial(0.8f, 0.8f, 0.3f), pos, dense, w, h, d, { 1, 0, 0, 1 }, filterData()),
	ex(exp)
{
	mBod->userData = this;
}

void Barrel::boom()
{
	ex->setPosition(trans->p);
	ex->explode();
	_toDestroy = true;
}

physx::PxFilterData Barrel::filterData()
{
	physx::PxFilterData barrelFilter;
	barrelFilter.word0 = LAYER_BARREL;
	barrelFilter.word1 = LAYER_DEFAULT | LAYER_BULLET | LAYER_ENEMY | LAYER_FLOOR;
	return barrelFilter;
}






Bullet::Bullet(physx::PxScene* scene, physx::PxPhysics* physx, Vector3 pos, float life, float dense, float r)
	: SolidDyEnt(scene, physx, physx->createMaterial(0.5f, 0.5f, 0.4f), pos, dense, r, { 0.3, 0.3, 0.3, 1 }, filterData())
{
	lifetime = life;

	mBod->userData = this;
}

physx::PxFilterData Bullet::filterData()
{
	physx::PxFilterData bulletFilter;
	bulletFilter.word0 = LAYER_BULLET;
	bulletFilter.word1 = LAYER_DEFAULT | LAYER_ENEMY | LAYER_FLOOR | LAYER_BARREL;
	return bulletFilter;
}
