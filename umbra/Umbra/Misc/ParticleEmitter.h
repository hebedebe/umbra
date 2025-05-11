#pragma once
#include <utility>

#include "Umbra/Actors/Actor.h"

struct ParticleData;
class ParticleSystem;

class ParticleEmitter : public Actor
{
	friend class ParticleSystem;

public:
	float emissionTimer = 1;
	int particlesPerEmission = 1;
	Texture targetTexture;

public:
	ParticleEmitter(ActorTransform transform, ParticleSystem* particleSystem);
	~ParticleEmitter() override;

public:
	virtual void SpawnParticle(ParticleData data);
	virtual void Emit();

	void Tick(float dt) override;
	void Render() override;

private:
	ParticleSystem* m_particleSystem;

	float m_emitterTimer;
};

class RadialParticleEmitter : public ParticleEmitter
{
public:
	std::pair<float, float> emissionAngles;
	std::pair<float, float> emissionVelocities;

public:
	RadialParticleEmitter(ActorTransform transform, ParticleSystem* particleSystem);

public:
	void Emit() override;
};

