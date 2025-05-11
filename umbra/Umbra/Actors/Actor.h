#pragma once
#include "ActorTransform.h"

class Actor
{
public:
	ActorTransform transform;

public:
	Actor();
	Actor(ActorTransform transform);
	virtual ~Actor();

public:
	virtual void Tick(float dt);
	virtual void Render();
};

