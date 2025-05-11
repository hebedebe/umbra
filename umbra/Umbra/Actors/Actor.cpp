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

void Actor::Tick(float dt)
{
}

void Actor::Render()
{
}
