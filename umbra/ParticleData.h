#pragma once

#include <raylib/raylib.h>

struct ParticleData {
	Vector2 pos; //replace raylibs vectors with mathlib vec2
	Vector2 vel;
	Vector2 accel;

	float lifetime = 99999999999999.f; // replace with infinity macro later

	float drag = 0;
	float rotationalDrag = 0;

	float rotation = 0;
	float rotationAccel = 0; //different from drag because it is added not multiplied

	float scale = 1;
	float targetScale = 1; // needs implementing
	float scaleLerpSpeed = 0;

	Color color = WHITE;
	Color targetColor = WHITE; // needs implementing
	float colorLerpSpeed = 0;

	Texture texture = LoadTexture("Umbra/Textures/Tex_DefaultParticle.png"); //probably replace with sprite later (to support animations etc)
};