#pragma once
#include <raylib/raylib.h>

struct ColorPair
{
	union
	{
		struct
		{
			Color a;
			Color b;
		};

		Color data[2];
	};
};
