#include "Particle.h"

Particle::Particle()
{
}

Particle::~Particle()
{
}

void Particle::Tick(float dt)
{
}

void Particle::Render()
{
}

ParticleRenderData Particle::GetRenderData()
{
	ParticleRenderData renderData =
	{
		m_pos,
		m_scale,
		m_rotation,
		m_color,
		m_texture
	};
}

bool Particle::Alive()
{
}
