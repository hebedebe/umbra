#pragma once
#include "ParticleRenderData.h"
#include "raylib/raylib.h"

class ParticleSystem;

class Particle
{
	friend class ParticleSystem;

public:
	Particle();
	~Particle();

public:
	void Tick(float dt);
	void Render();
	ParticleRenderData GetRenderData();

	bool Alive();

private:
	ParticleSystem* m_system;

	Vector2 m_pos;
	Vector2 m_vel;
	Vector2 m_accel;

	float m_drag;
	float m_rotationalDrag;

	float m_rotation;
	float m_rotationAccel; //different from drag because it is added not multiplied

	Vector2 m_scale;
	Vector2 m_targetScale;
	float m_scaleLerpSpeed;

	Color m_color;
	Color m_targetColor;
	float m_colorLerpSpeed;

	Texture* m_texture; //probably replace with sprite later (to support animations etc)
};

