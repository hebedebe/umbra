#include "Particle.h"

#include <raylib/raymath.h>
#include <raylib/raylib.h>

#include "ParticleShortcuts.h"

Particle::Particle()
	:m_data{ ParticleData() }
{
}

Particle::Particle(ParticleData data)
	:m_data{ data }
{
}

Particle::~Particle()
{
	Actor::~Actor();
}

void Particle::Tick(const float dt)
{
	Actor::Tick(dt);

	Vector2 dtVec{ dt, dt };

	VEL = Vector2Add(VEL, Vector2Multiply(ACCEL, dtVec)); // substitute with mathlib stuff later
	POS = Vector2Add(POS, Vector2Multiply(VEL, dtVec));

	LIFE -= dt;

	ROTSPD *= 1 - ROTDRAG * dt;
	ROT += ROTSPD * dt;

	SCALE += SCALECHANGE * dt;
}

void Particle::Render()
{
	Actor::Render();

	DrawTextureEx(*TEX, GetRenderPosition(), ROT, SCALE, COLOR);
	//DrawTextureV(TEX, POS, COLOR);
	//DrawCircleV(POS, SCALE * 3, COLOR);
}

bool Particle::Alive()
{
	return LIFE > 0 && SCALE > 0;
}

Vector2 Particle::GetRenderPosition()
{
	return
	{
		POS.x - ((TEX->width * SCALE) / 2),
		POS.y - ((TEX->height * SCALE) / 2)
	};
}
