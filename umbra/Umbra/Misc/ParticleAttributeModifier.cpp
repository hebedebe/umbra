#include "ParticleAttributeModifier.h"

#include <random>


float random_float(float min, float max) { // put this in mathlib later
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(min, max);
	return dis(gen);
}

ParticleAttributeModifier::ParticleAttributeModifier()
= default;

ParticleAttributeModifier::~ParticleAttributeModifier()
= default;

void ParticleAttributeModifier::Modify(ParticleData& data)
{
	EditParticleData(data);
}

TextureAttributeModifier::TextureAttributeModifier(Texture* texture)
	:m_texture(texture)
{
}

void TextureAttributeModifier::EditParticleData(ParticleData& data)
{
	data.texture = m_texture;
}

FloatAttributeRandomiser::FloatAttributeRandomiser(float a, float b)
	:m_a(a), m_b(b)
{
}

void LifetimeAttributeRandomiser::EditParticleData(ParticleData& data)
{
	data.lifetime = random_float(m_a, m_b);
}

void DragAttributeRandomiser::EditParticleData(ParticleData& data)
{
	data.drag = random_float(m_a, m_b);
}

void RotationalDragAttributeRandomiser::EditParticleData(ParticleData& data)
{
	data.rotationalDrag = random_float(m_a, m_b);
}

void RotationAttributeRandomiser::EditParticleData(ParticleData& data)
{
	data.rotation = random_float(m_a, m_b);
}

void RotationSpeedAttributeRandomiser::EditParticleData(ParticleData& data)
{
	data.rotationSpeed = random_float(m_a, m_b);
}

void ScaleAttributeRandomiser::EditParticleData(ParticleData& data)
{
	data.scale = random_float(m_a, m_b);
}

void ScaleChangeAttributeRandomiser::EditParticleData(ParticleData& data)
{
	data.scaleChange = random_float(m_a, m_b);
}

void ColorLerpSpeedAttributeRandomiser::EditParticleData(ParticleData& data)
{
	data.colorLerpSpeed = random_float(m_a, m_b);
}

void ColorAttributeRandomiser::EditParticleData(ParticleData& data)
{
	data.color = ColorLerp(m_a, m_b, random_float(0, 1));
}

void TargetColorAttributeRandomiser::EditParticleData(ParticleData& data)
{
	data.targetColor = ColorLerp(m_a, m_b, random_float(0, 1));
}
