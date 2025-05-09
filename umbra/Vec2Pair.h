#pragma once
#include <raylib/raylib.h>

struct Vec2Pair
{
	union
	{
		struct
		{
			Vector2 a;
			Vector2 b;
		};

		Vector2 data[2];
	};
};
