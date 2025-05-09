#pragma once
class Actor
{
public:
	Actor();
	~Actor();

public:
	void Tick(dt);
	void Render();
};

