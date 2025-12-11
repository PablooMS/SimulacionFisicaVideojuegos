#pragma once
#include "GameSolids.h"
#include "Explosive.h"
#include "EntityManager.h"

class ShootingComponent
{
public:

	ShootingComponent(Explosive* explo, Camera* camr, float life, float den, float ra, int cool) 
		: ex(explo), cam(camr), lifetime(life), dense(den), r(ra), ti(0), maxT(cool) {}
	~ShootingComponent();

	void update(double t);

	void shoot();

private:

	//Cooldown
	int ti;
	int maxT;

	//Para crear la bala
	float lifetime;
	float dense;
	float r;

	//Referencias externas
	Explosive* ex;
	Camera* cam;
	EntityManager* entMan;
};

