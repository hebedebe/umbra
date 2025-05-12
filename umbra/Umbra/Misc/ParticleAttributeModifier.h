#pragma once
#include "ParticleData.h"

class ParticleAttributeModifier
{
	friend class ParticleEmitter; // shouldn't be needed but wtv
	friend class ParticleSystem;

public:
	ParticleAttributeModifier();
	virtual ~ParticleAttributeModifier();

public:
	void Modify(ParticleData& data);

protected:
	virtual void EditParticleData(ParticleData& data) = 0;
};

class TextureAttributeModifier : public ParticleAttributeModifier
{
public:
	TextureAttributeModifier(Texture* texture);

protected:
	Texture* m_texture;

protected:
	void EditParticleData(ParticleData& data) override;
};

class FloatAttributeRandomiser : public ParticleAttributeModifier
{
public:
	FloatAttributeRandomiser(float a, float b);

protected:
	float m_a;
	float m_b;
};

class LifetimeAttributeRandomiser : public FloatAttributeRandomiser
{
public:
	LifetimeAttributeRandomiser(float a, float b)
		: FloatAttributeRandomiser(a, b)
	{
	}

protected:
	void EditParticleData(ParticleData& data) override;
};

class DragAttributeRandomiser : public FloatAttributeRandomiser
{
public:
	DragAttributeRandomiser(float a, float b)
		: FloatAttributeRandomiser(a, b)
	{
	}

protected:
	void EditParticleData(ParticleData& data) override;
};

class RotationalDragAttributeRandomiser : public FloatAttributeRandomiser
{
public:
	RotationalDragAttributeRandomiser(float a, float b)
		: FloatAttributeRandomiser(a, b)
	{
	}

protected:
	void EditParticleData(ParticleData& data) override;
};

class RotationAttributeRandomiser : public FloatAttributeRandomiser
{
public:
	RotationAttributeRandomiser(float a, float b)
		: FloatAttributeRandomiser(a, b)
	{
	}

protected:
	void EditParticleData(ParticleData& data) override;
};

class RotationSpeedAttributeRandomiser : public FloatAttributeRandomiser
{
public:
	RotationSpeedAttributeRandomiser(float a, float b)
		: FloatAttributeRandomiser(a, b)
	{
	}

protected:
	void EditParticleData(ParticleData& data) override;
};

class ScaleAttributeRandomiser : public FloatAttributeRandomiser
{
public:
	ScaleAttributeRandomiser(float a, float b)
		: FloatAttributeRandomiser(a, b)
	{
	}

protected:
	void EditParticleData(ParticleData& data) override;
};

class ScaleChangeAttributeRandomiser : public FloatAttributeRandomiser
{
public:
	ScaleChangeAttributeRandomiser(float a, float b)
		: FloatAttributeRandomiser(a, b)
	{
	}

protected:
	void EditParticleData(ParticleData& data) override;
};

class ColorLerpSpeedAttributeRandomiser : public FloatAttributeRandomiser
{
public:
	ColorLerpSpeedAttributeRandomiser(float a, float b)
		: FloatAttributeRandomiser(a, b)
	{
	}

protected:
	void EditParticleData(ParticleData& data) override;
};


