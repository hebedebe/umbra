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
	for (size_t i = 0; i < m_textures.size(); i++)
	{
		Texture tex = m_textures[i];

		// Define source and destination rectangles
		const Rectangle source = { 0, 0, static_cast<float>(tex.width), static_cast<float>(tex.height) };
		const Vector2 origin = { tex.width / 2.0f * scale, tex.height / 2.0f * scale };
		auto [x, y] = Vector2Add(pos, { 0, m_ySeparation * i });

		// Apply scaling in DrawTexturePro directly
		const Rectangle dest = { x, y, tex.width * scale, tex.height * scale };

		// Draw with center-based rotation
		DrawTexturePro(tex, source, dest, origin, rotation, color);
	}

	DrawCircleV(pos, 3, RED); // Optional debug point
}
