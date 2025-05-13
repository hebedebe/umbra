#include "ParticleEmitter.h"

#include <iostream>
#include <random>
#include <thread>
#include <raylib/raymath.h>

#include "Particle.h"
#include "ParticleSystem.h"
#include "ParticleData.h"
#include "ParticleAttributeModifier.h"

ParticleEmitter::ParticleEmitter(ActorTransform transform, ParticleSystem* particleSystem)
	:m_particleSystem(particleSystem)
{
	attributeModifiers = {};
	this->transform = transform;
}

ParticleEmitter::~ParticleEmitter()
{
	for (ParticleAttributeModifier* attributeModifier : attributeModifiers)
	{
		delete attributeModifier;
	}
}

void ParticleEmitter::SpawnParticle(ParticleData data)
{
	for (ParticleAttributeModifier* attributeModifier : attributeModifiers)
	{
		attributeModifier->Modify(data);
	}
	m_particleSystem->m_particles.emplace_back(new Particle{data});
}

void ParticleEmitter::Emit()
{
	SpawnParticle(ParticleData());
}

void ParticleEmitter::Tick(float dt)
{
	Actor::Tick(dt);

	m_lifetime -= dt;
	if (m_lifetime <= 0)
	{
		markedForDeletion = true;
	}

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

void ParticleEmitter::AddAttribute(ParticleAttributeModifier* attribute)
{
	attributeModifiers.emplace_back(attribute);
}

void ParticleEmitter::SetLifeTime(float lifetime)
{
	m_lifetime = lifetime;
}

float random_floattwo(float min, float max) { // put this in mathlib later
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

	float angle = random_floattwo(emissionAngles.first, emissionAngles.second);
	float speed = random_floattwo(emissionVelocities.first, emissionVelocities.second);

	Vector2 velocity = Vector2Multiply({cosf(angle), sinf(angle)}, {speed, speed});

	particleData.pos = transform.position;
	particleData.vel = velocity;

	SpawnParticle(particleData);
}
