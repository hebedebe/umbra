#include "SpriteStack.h"

#include <raylib/raymath.h>

#include <utility>

SpriteStack::SpriteStack()
= default;

SpriteStack::SpriteStack(std::vector<Texture> textures, float ySeparation)
	:m_textures(std::move(textures)), m_ySeparation(ySeparation)
{
}

SpriteStack::~SpriteStack()
= default;

void SpriteStack::Render(Vector2 pos, float rotation, float scale, Color color) const
{
	for (int i = 0; i < m_textures.size(); i++)
	{
		Texture tex = m_textures[i];

		// Define source and destination rectangles
		Rectangle source = { 0, 0, (float)tex.width, (float)tex.height };
		Vector2 origin = { tex.width / 2.0f * scale, tex.height / 2.0f * scale };
		Vector2 destPos = Vector2Add(pos, { 0, m_ySeparation * i });

		// Apply scaling in DrawTexturePro directly
		Rectangle dest = { destPos.x, destPos.y, tex.width * scale, tex.height * scale };

		// Draw with center-based rotation
		DrawTexturePro(tex, source, dest, origin, rotation, color);
	}

	DrawCircleV(pos, 3, RED); // Optional debug point
}
