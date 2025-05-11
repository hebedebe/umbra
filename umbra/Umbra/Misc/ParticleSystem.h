#pragma once
#include <vector>

#include "Umbra/Actors/Actor.h"

class ParticleEmitter;
class Particle;

class ParticleSystem : public Actor
{
	friend class ParticleEmitter;
	friend class Particle;

public:
	ParticleSystem();
	~ParticleSystem();

public:
	void Tick(float dt) override;
	void Render() override;

	void ClearEmitters(bool tidy = true);
	void ClearParticles(bool tidy = true);

private:
	std::vector<ParticleEmitter*> m_emitters;
	std::vector<Particle*> m_particles;
};

