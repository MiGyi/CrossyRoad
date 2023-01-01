#pragma once

#include "raylib.h"
#include "../Helper/TextureHelper.h"
#include "../Helper/Const.h"

#include <vector>
#include <string>

// Singleton class
class TextureHolder {
private:
    TextureHolder();
    void LoadAllTexture();
    void UnloadAllTexture();

    static TextureHolder *instance;

    std::vector <Texture2D *> Character[NumberOfCharacter];
    std::vector <Texture2D *> Vehicle;
    std::vector <Texture2D *> Animal[NumberOfAnimal];
    std::vector <Texture2D *> Traffic_light;
    std::vector <Texture2D *> Forest;
    std::vector <Texture2D *> Road;
    
public:
    ~TextureHolder();
    static TextureHolder *GetInstance();

    void LoadTexture(const std::string& filepath, const std::string& name);
    std::vector <Texture2D *> GetCharacter(int Character);
    std::vector <Texture2D *> GetForestTextures();
    Texture2D *GetForest(int ForestType);
    std::vector <Texture2D *> GetRoadTextures();
    Texture2D *GetRoad(int RoadType);
    std::vector <Texture2D *> GetTrafficLight();
    std::vector <Texture2D *> GetVehicle();
    std::vector <Texture2D *> GetAnimal(int Animal);
};