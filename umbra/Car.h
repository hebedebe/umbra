#pragma once
#include "Umbra/Actors/Actor.h"
#include "Umbra/Misc/SpriteStack.h"

class Car :
    public Actor
{
public:
    Car(SpriteStack spriteStack, float accel, float drag, float rotAccel, float rotDrag);
    ~Car() override;

public:
    void Tick(const float dt) override;
    void Render() override;

private:
    SpriteStack m_spriteStack;

    float m_accel;
    float m_drag;
    float m_rotAccel;
    float m_rotDrag;

    Vector2 m_velocity = {0};
    float m_rotation = 0;
    float m_rotationVel = 0;
};

