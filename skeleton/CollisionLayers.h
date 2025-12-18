#pragma once

enum CollisionLayers
{
	LAYER_DEFAULT = 1 << 0,		//00001
	LAYER_BULLET = 1 << 1,		//00010
	LAYER_ENEMY = 1 << 2,		//00100
	LAYER_FLOOR = 1 << 3,		//01000
	LAYER_BARREL = 1 << 4		//10000
};

