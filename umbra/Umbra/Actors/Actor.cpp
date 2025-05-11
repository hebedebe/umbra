#include "Actor.h"

Actor::Actor()
	:transform{ActorTransform()}
{
}

Actor::Actor(ActorTransform transform)
	:transform(transform)
{
}

Actor::~Actor()
{
}

void Actor::Tick(const float dt)
{
}

void Actor::Render()
{
}

void Actor::SetActive()
{
	m_active = true;
}

void Actor::SetInactive()
{
	m_active = false;
}

bool Actor::Active()
{
	return m_active;
}
