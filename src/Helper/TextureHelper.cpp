#include "TextureHelper.h"

void GetTexture(float width, float height, std::string filepath, Texture2D& texture) {
    Image image = LoadImage(filepath.c_str());
    ImageResize(&image, width, height);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    //texture = LoadTexture(filepath.c_str());
}