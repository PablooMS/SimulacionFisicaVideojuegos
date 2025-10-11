#include "Firework.h"

Firework::~Firework() 
{
	render->release();
	render = nullptr;
}

