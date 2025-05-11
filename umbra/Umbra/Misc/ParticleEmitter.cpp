#include "ParticleEmitter.h"

#include <random>
#include <raylib/raymath.h>

#include "Particle.h"
#include "ParticleSystem.h"
#include "ParticleData.h"

ParticleEmitter::ParticleEmitter(ActorTransform transform, ParticleSystem* particleSystem)
	:m_particleSystem(particleSystem)
{
	this->transform = transform;
}

ParticleEmitter::~ParticleEmitter()
{
	//delete targetTexture;
}

void ParticleEmitter::SpawnParticle(ParticleData data)
{
	m_particleSystem->m_particles.emplace_back(new Particle{data});
}

void ParticleEmitter::Emit()
{
	SpawnParticle(ParticleData());
}

void ParticleEmitter::Tick(float dt)
{
	Actor::Tick(dt);

	m_emitterTimer -= dt;
	if (m_emitterTimer <= 0)
	{
		m_emitterTimer = emissionTimer;
		for (int i = 0; i < particlesPerEmission; ++i)
		{
			Emit();
		}
	}
}

void ParticleEmitter::Render()
{
	Actor::Render();
	DrawCircleV(transform.position, 3, YELLOW);
}

float random_float(float min, float max) { // put this in mathlib later
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(min, max);
	return dis(gen);
}

RadialParticleEmitter::RadialParticleEmitter(ActorTransform transform, ParticleSystem* particleSystem)
	: ParticleEmitter(transform, particleSystem)
{
}

void RadialParticleEmitter::Emit()
{
	ParticleData particleData;

	float angle = random_float(emissionAngles.first, emissionAngles.second);
	float speed = random_float(emissionVelocities.first, emissionVelocities.second);

	Vector2 velocity = Vector2Multiply({cosf(angle), sinf(angle)}, {speed, speed});

	particleData.pos = transform.position;
	particleData.vel = velocity;

	particleData.texture = targetTexture;

	SpawnParticle(particleData);
}
