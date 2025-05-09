#include "ParticleSystem.h"

#include "Particle.h"

ParticleSystem::ParticleSystem()
= default;

ParticleSystem::~ParticleSystem()
{
	for (Particle* particle : m_particles)
	{
		delete particle;
		particle = nullptr;
	}
}

void ParticleSystem::SpawnParticle(Particle* particle)
{
	particle->m_system = this;
	m_particles.emplace_back(particle);
}

void ParticleSystem::Tick(float dt)
{

	for (auto iter = m_particles.begin(); iter!= m_particles.end();) {

		Particle* particle = *iter;

		if (!particle->Alive()) {
			iter = m_particles.erase(iter);  // erase returns the next valid iterator
			continue;
		}

		particle->Tick(dt);
		++iter;
	}
}

void ParticleSystem::Render()
{
	for (Particle* particle: m_particles)
	{
		particle->Render();
	}
}
