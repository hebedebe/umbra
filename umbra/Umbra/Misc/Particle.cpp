#include "Particle.h"

Particle::Particle()
	:m_data{ ParticleData() }
{
}

Particle::Particle(ParticleData data)
	:m_data{ data }
{
}

Particle::~Particle()
= default;

void Particle::Tick(float dt)
{
	m_data.lifetime -= dt;

	m_data.vel = Vector2
	{
		(m_data.vel.x + m_data.accel.x * dt) * (1 - m_data.drag * dt),
		(m_data.vel.y + m_data.accel.y * dt) * (1 - m_data.drag * dt)
	};

	m_data.pos = Vector2
	{
		m_data.pos.x + m_data.vel.x * dt,
		m_data.pos.y + m_data.vel.y * dt
	};

	m_data.rotation += m_data.rotationAccel * dt;
	m_data.rotation *= 1 - m_data.rotationalDrag * dt;
}

void Particle::Render() const
{
	DrawTextureEx(m_data.texture, m_data.pos, m_data.rotation, m_data.scale, m_data.color);
}

bool Particle::Alive()
{
	bool expiredLifetime = (m_data.lifetime <= 0);

	return expiredLifetime;
}
