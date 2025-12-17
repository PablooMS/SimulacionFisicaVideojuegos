#include "Firework.h"

Firework::~Firework() 
{
	setRender(false);
	//render->release();
	render = nullptr;
}

