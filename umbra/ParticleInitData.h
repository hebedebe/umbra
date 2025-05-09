#pragma once
#include <vector>

#include "ColorPair.h"
#include "FloatPair.h"
#include "Vec2Pair.h"

struct ParticleInitData
{
	Vec2Pair posRange;
	Vec2Pair velRange;
	Vec2Pair accelRange;

	FloatPair lifetimeRange;

	FloatPair dragRange;
	FloatPair rotationalDragRange;

	FloatPair rotationRange;
	FloatPair rotationAccelRange;

	FloatPair scaleRange;
	FloatPair targetScaleRange;
	FloatPair scaleLerpSpeedRange;

	ColorPair colorRange;
	ColorPair targetColorRange;
	FloatPair colorLerpSpeedRange;

	Texture textures[];
};
