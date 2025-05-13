#pragma once

#include <raylib/raylib.h>
#include <raylib/raymath.h>

struct ParticleData {
	Vector2 pos = Vector2Zero(); //replace raylibs vectors with mathlib vec2
	Vector2 vel = Vector2Zero();
	Vector2 accel = Vector2Zero();

	float lifetime = 5.f;

	float drag = 0;
	float rotationalDrag = 0;

	float rotation = 0;
	float rotationSpeed = 0; //different from drag because it is added not multiplied

	float scale = 1;
	float scaleChange = -1.f; // needs implementing

	Color color = WHITE;
	Color targetColor = WHITE; // needs implementing
	float colorLerpSpeed = 0;

	Texture* texture=nullptr; //probably replace with sprite later (to support animations etc)
};
