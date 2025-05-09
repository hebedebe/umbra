#include "ParticleSystem.h"

#include <array>
#include <ctime>

#include "Particle.h"

template<typename T>
static T randomChoice(const T items[])
{
	std::srand(time(nullptr));
	T random_item = items[std::rand() % items.size()];
	return random_item;
}

ParticleSystem::ParticleSystem()
= default;

ParticleSystem::ParticleSystem(ParticleInitData particleInitData)
{
	m_initData = particleInitData;
}

ParticleSystem::~ParticleSystem()
{
	for (Particle* particle : m_particles)
	{
		delete particle;
		particle = nullptr;
	}
}

void ParticleSystem::SpawnParticle()
{
	ParticleData data =
	{
		.pos = randomChoice(m_initData.posRange.data),
		.vel = randomChoice(m_initData.velRange.data),
		.accel = randomChoice(m_initData.accelRange.data),

		.lifetime = randomChoice(m_initData.lifetimeRange.data),

		.drag = randomChoice(m_initData.dragRange.data),
		.rotationalDrag = randomChoice(m_initData.rotationalDragRange.data),

		.rotation = randomChoice(m_initData.rotationRange.data),
		.rotationAccel = randomChoice(m_initData.rotationAccelRange.data),

		.scale = randomChoice(m_initData.scaleRange.data),
		.targetScale = randomChoice(m_initData.targetScaleRange.data),
		.scaleLerpSpeed = randomChoice(m_initData.scaleLerpSpeedRange.data),

		.color = randomChoice(m_initData.colorRange.data),
		.targetColor = randomChoice(m_initData.targetColorRange.data),
		.colorLerpSpeed = randomChoice(m_initData.colorLerpSpeedRange.data),

		.texture = randomChoice(m_initData.textures)
	};

	Particle* particle = new Particle(data);
	particle->m_system = this;
	m_particles.emplace_back(particle);
}

void ParticleSystem::SpawnParticle(Particle* particle)
{
	particle->m_system = this;
	m_particles.emplace_back(particle);
}

void ParticleSystem::SpawnParticle(ParticleData particleData)
{
	Particle* particle = new Particle(particleData);
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
