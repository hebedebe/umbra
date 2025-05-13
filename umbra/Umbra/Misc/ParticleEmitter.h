#pragma once
#include <utility>
#include <vector>

//#include "ParticleAttributeModifier.h"
#include "Umbra/Actors/Actor.h"

struct ParticleData;
class ParticleSystem;
class ParticleAttributeModifier;

class ParticleEmitter : public Actor
{
	friend class ParticleSystem;

public:
	float emissionTimer = 0.0f;
	int particlesPerEmission = 1.f;
	std::vector<ParticleAttributeModifier*> attributeModifiers;

public:
	ParticleEmitter(ActorTransform transform, ParticleSystem* particleSystem);
	~ParticleEmitter() override;

public:
	virtual void SpawnParticle(ParticleData data);
	virtual void Emit();

	void Tick(float dt) override;
	void Render() override;

	void AddAttribute(ParticleAttributeModifier* attribute);
	void SetLifeTime(float lifetime);

protected:
	ParticleSystem* m_particleSystem;

private:
	float m_lifetime = 9999999;
	float m_emitterTimer;
};

class RadialParticleEmitter : public ParticleEmitter
{
public:
	std::pair<float, float> emissionAngles = {0, 2*PI};
	std::pair<float, float> emissionVelocities = {20, 50};

public:
	RadialParticleEmitter(ActorTransform transform, ParticleSystem* particleSystem);

public:
	void Emit() override;
};

