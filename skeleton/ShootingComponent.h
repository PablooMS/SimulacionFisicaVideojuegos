#pragma once
#include "GameSolids.h"
#include "Explosive.h"
#include "EntityManager.h"

class ShootingComponent
{
public:

	ShootingComponent(EntityManager* e, Explosive* explo, Camera* camr, float life, float den, float ra, float cool) 
		: entMan(e), ex(explo), cam(camr), lifetime(life), dense(den), r(ra), ti(0), maxT(cool) {}
	~ShootingComponent();

	void update(double t);

	void shoot();

private:

	//Cooldown
	float ti;
	float maxT;

	//Para crear la bala
	float lifetime;
	float dense;
	float r;

	//Referencias externas
	Explosive* ex;
	Camera* cam;
	EntityManager* entMan;
};

