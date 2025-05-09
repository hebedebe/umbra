#pragma once
#include <unordered_set>
#include <vector>

#include "ColorPair.h"
#include "ParticleInitData.h"
#include "Vec2Pair.h"
#include "Umbra/Actors/Actor.h"

using std::vector;

struct ParticleData;
class Particle;

class ParticleSystem : public Actor
{
	friend class Particle;

public:
	float emissionDelay;



public:
	ParticleSystem();
	ParticleSystem(ParticleInitData particleInitData);
	~ParticleSystem();

public:
	void SpawnParticle();
	void SpawnParticle(Particle* particle);
	void SpawnParticle(ParticleData particle);

	void Tick(float dt);
	void Render();

private:
	vector<Particle*> m_particles;
	ParticleInitData m_initData;

	float m_emissionTimer;
};

