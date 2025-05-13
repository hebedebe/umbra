#pragma once
#include <vector>
#include <raylib/raylib.h>

class RenderUtils
{
public:
    std::vector<Texture2D> LoadSpriteSheet(const char* filePath, int frameWidth, int frameHeight);
};
