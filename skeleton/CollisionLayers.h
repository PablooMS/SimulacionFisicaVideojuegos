#pragma once

enum CollisionLayers
{
	LAYER_DEFAULT = 1 << 0,
	LAYER_BULLET = 1 << 1,
	LAYER_ENEMY = 1 << 2,
	LAYER_FLOOR = 1 << 3,
	LAYER_BARREL = 1 << 4
};

