#pragma once
#include <raylib/raylib.h>

struct ParticleRenderData
{
	Vector2 pos;
	Vector2 scale;
	float rotation;
	Color color;
	Texture* texture;
};
