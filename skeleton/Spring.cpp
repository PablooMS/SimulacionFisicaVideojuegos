#include "Spring.h"

Spring::Spring(Entity* e1, Vector3 e2) : Entity({0, 0, 0}, {0, 0, 0})
{
	statc = true;

	ending1 = e1;
	
	twoEnd = false;
	end2 = e2;
	ending2 = nullptr;
}

Spring::Spring(Entity* e1, Entity* e2) : Entity({ 0, 0, 0 }, { 0, 0, 0 })
{
	statc = true;

	ending1 = e1;

	twoEnd = true;
	ending2 = e2;
}

void Spring::update(double t)
{
}

