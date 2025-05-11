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
	virtual void Tick(const float dt);
	virtual void Render();

	void SetActive();
	void SetInactive();
	bool Active();

protected:
	bool m_active = true;
};

