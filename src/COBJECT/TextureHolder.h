#pragma once

#include "raylib.h"
#include "../Helper/TextureHelper.h"
#include "../Helper/Const.h"

#include <vector>
#include <string>

class TextureHolder {
private:
    std::vector <Texture2D *> Character[NumberOfCharacter];
    std::vector <Texture2D *> Vehicle[3];
    std::vector <Texture2D *> Animal[3];
    
public:
    TextureHolder();
    ~TextureHolder();
    void LoadTexture(const std::string& filepath, const std::string& name);
    std::vector <Texture2D *> GetCharacter(int Character);
    void Clear();
};