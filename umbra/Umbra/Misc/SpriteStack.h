#pragma once

#include <vector>
#include <raylib/raylib.h>

class SpriteStack
{
public:
	SpriteStack(std::vector<Texture> textures, float ySeparation);
	SpriteStack();
	~SpriteStack();

public:
	void Render(Vector2 pos, float rotation, float scale=1, Color color=WHITE) const;
	void RenderSpritesheet(Vector2 pos, float rotation, float scale, Color color) const;

private:
	std::vector<Texture> m_textures;
	float m_ySeparation;
};

