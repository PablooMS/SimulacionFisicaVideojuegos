#pragma once
#include "SolidEnt.h"
#include "Explosive.h"
#include "CollisionLayers.h"

class Enemy : public SolidDyEnt
{
public:

	Enemy(physx::PxScene* scene, physx::PxPhysics* physx,
		Vector3 pos, float dense, float r, int* cont);
	~Enemy() { en_cont = nullptr; };

private:

	void die();

	int* en_cont;

};

class Barrel : public SolidDyEnt
{
public:

	Barrel(physx::PxScene* scene, physx::PxPhysics* physx,
		Vector3 pos, float dense, float w, float h, float d,
		Explosive* exp);
	~Barrel() { ex = nullptr; }

private:

	void boom();

	Explosive* ex;
};

class Bullet : public SolidDyEnt
{
public:
	Bullet(physx::PxScene* scene, physx::PxPhysics* physx,
		Vector3 pos, float life, float dense, float r);
	~Bullet() {};

private:


};

