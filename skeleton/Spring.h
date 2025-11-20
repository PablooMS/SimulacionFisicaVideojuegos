#pragma once
#include "Entity.h"

class Spring : public Entity
{
public:
	Spring(Entity* e1, Vector3 e2, int length, int konstant);
	Spring(Entity* e1, Entity* e2, int length, int konstant);

	virtual void update(double t) override;

private:
	
	int l;
	int k;

	bool twoEnd;
	Entity* ending1;
	Entity* ending2;
	Vector3 end2;
};

