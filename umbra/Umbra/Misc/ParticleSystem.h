#pragma once
#include <unordered_set>
#include <vector>

#include "Umbra/Actors/Actor.h"

using std::vector;

class Particle;

class ParticleSystem : public Actor
{
	friend class Particle;

public:
	ParticleSystem();
	~ParticleSystem();

public:
	void SpawnParticle(Particle* particle);

	void Tick(float dt);
	void Render();

private:
	vector<Particle*> m_particles;
};

