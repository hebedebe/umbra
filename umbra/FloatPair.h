#pragma once

struct FloatPair
{
	union
	{
		struct
		{
			float a;
			float b;
		};

		float data[2];
	};
};
