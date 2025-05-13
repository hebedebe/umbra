#include "Car.h"

#include <raylib/raymath.h>

Car::Car(SpriteStack spriteStack, float accel, float drag, float rotAccel, float rotDrag)
	:m_spriteStack(spriteStack), m_accel(accel), m_drag(drag), m_rotAccel(rotAccel), m_rotDrag(rotDrag)
{
}

Car::~Car()
= default;

void Car::Tick(const float dt)
{
	Actor::Tick(dt);

	float forward = (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)) * -m_accel;
	float turn = (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * m_rotAccel;

	m_rotationVel += turn * dt;

	m_rotation += m_rotationVel * dt;
	m_rotation *= 1 - m_rotDrag * dt;

	Vector2 vel = Vector2Multiply(Vector2{ cosf(m_rotation/180*PI), sinf(m_rotation/180*PI) }, Vector2( forward, forward ));
	m_velocity *= 1 - m_drag * dt;
	m_velocity += vel * dt;

	transform.position += m_velocity * dt;

	if (transform.position.x > 800)
	{
		transform.position.x = 0;
	} else if (transform.position.x < 0)
	{
		transform.position.x = 800;
	}

	if (transform.position.y > 600)
	{
		transform.position.y = 0;
	}
	else if (transform.position.y < 0)
	{
		transform.position.y = 600;
	}
}

void Car::Render()
{
	Actor::Render();
	m_spriteStack.Render(transform.position, m_rotation, 4);
}

