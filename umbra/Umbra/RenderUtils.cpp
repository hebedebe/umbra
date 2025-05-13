#include "RenderUtils.h"

#include <raylib/raylib.h>
#include <vector>

static std::vector<Texture2D> LoadSpriteSheet(const char* filePath, int frameWidth, int frameHeight)
{
    std::vector<Texture2D> frames;

    // Load the entire spritesheet as an Image (editable in CPU memory)
    Image spriteSheet = LoadImage(filePath);

    int sheetWidth = spriteSheet.width;
    int sheetHeight = spriteSheet.height;

    int columns = sheetWidth / frameWidth;
    int rows = sheetHeight / frameHeight;

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            // Define the frame rectangle
            Rectangle frameRec = {
                (float)(x * frameWidth),
                (float)(y * frameHeight),
                (float)frameWidth,
                (float)frameHeight
            };

            // Extract the frame from the spritesheet
            Image frame = ImageFromImage(spriteSheet, frameRec);

            // Convert the frame image into a GPU texture
            Texture2D tex = LoadTextureFromImage(frame);

            // Store the texture
            frames.push_back(tex);

            // Clean up the frame image (no longer needed after upload to GPU)
            UnloadImage(frame);
        }
    }

    // Clean up the original spritesheet
    UnloadImage(spriteSheet);

    return frames;
}
