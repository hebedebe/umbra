#include "ParticleSystem.h"

#include "Particle.h"
#include "ParticleEmitter.h"

ParticleSystem::ParticleSystem()
= default;

ParticleSystem::~ParticleSystem()
{
	//ClearEmitters(false); // emitters are stored as normal actors so we let them get cleaned up separately
	ClearParticles(false);
}

void ParticleSystem::Tick(const float dt)
{
	Actor::Tick(dt);

	for (auto emitter : m_emitters)
	{
		emitter->Tick(dt);
	}

	for (auto particle : m_particles)
	{
		particle->Tick(dt);
	}
}

void ParticleSystem::Render()
{
	Actor::Render();

	for (int i = 0; i < m_particles.size();)
	{
		Particle* particle = m_particles[i];
		if (!particle->Alive())
		{
			delete particle;
			particle = nullptr;
			m_particles.erase(m_particles.begin() + i);
			continue;
		}

		particle->Render();
		i++;
	}

	for (auto emitter : m_emitters)
	{
		emitter->Render();
	}
}

void ParticleSystem::ClearEmitters(bool tidy)
{
	for (auto emitter : m_emitters)
	{
		delete emitter;
	}

	if (tidy)
	{
		m_particles.clear();
	}
}

void ParticleSystem::ClearParticles(bool tidy)
{
	for (auto particle : m_particles)
	{
		delete particle;
	}

	if (tidy)
	{
		m_particles.clear();
	}
}
