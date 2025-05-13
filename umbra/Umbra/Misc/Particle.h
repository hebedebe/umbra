#pragma once
#include "ParticleData.h"
#include "Umbra/Actors/Actor.h"

class Particle : public Actor
{
	friend class ParticleSystem;
	friend class ParticleEmitter;

public:
	Particle(ParticleData data);
	Particle();
	~Particle();

public:
	void Tick(float dt) override;
	void Render() override;

	bool Alive();

	Vector2 GetRenderPosition();
	Color GetCurrentColor();

protected:
	ParticleData m_data;

	float m_colorLerp;
};

