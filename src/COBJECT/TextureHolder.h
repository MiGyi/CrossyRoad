#pragma once

#include "raylib.h"
#include "../Helper/TextureHelper.h"
#include "../Helper/Const.h"

#include <vector>
#include <string>

class TextureHolder {
private:
    static std::vector <Texture2D *> Character[NumberOfCharacter];
    static std::vector <Texture2D *> Vehicle;
    static std::vector <Texture2D *> Animal[3];
    static std::vector <Texture2D *> Traffic_light;
    static std::vector <Texture2D *> Forest;
    static std::vector <Texture2D *> Road;
    
public:
    // TextureHolder();
    // ~TextureHolder();
    static void LoadAllTexture();
    static void UnloadAllTexture();
    void LoadTexture(const std::string& filepath, const std::string& name);
    static std::vector <Texture2D *> GetCharacter(int Character);
    static std::vector <Texture2D *> GetForestTextures();
    static Texture2D *GetForest(int ForestType);
    static std::vector <Texture2D *> GetRoadTextures();
    static Texture2D *GetRoad(int RoadType);
    static std::vector <Texture2D *> GetTrafficLight();
    static std::vector <Texture2D *> GetVehicle();
    static std::vector <Texture2D *> GetAnimal(int Animal);
};