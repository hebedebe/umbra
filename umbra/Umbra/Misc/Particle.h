#pragma once
#include "ParticleData.h"
#include "raylib/raylib.h"

class ParticleSystem;

class Particle
{
	friend class ParticleSystem;

public:
	Particle();
	Particle(ParticleData data);
	~Particle();

public:
	void Tick(float dt);
	void Render() const;

	bool Alive();

private:
	ParticleSystem* m_system = nullptr;

	ParticleData m_data;
};

