#include "TextureHolder.h"

using namespace std;

TextureHolder *TextureHolder::instance = nullptr;

TextureHolder *TextureHolder::GetInstance() {
    if (instance == nullptr) {
        instance = new TextureHolder();
    }
    return instance;
}

TextureHolder::TextureHolder() {
    LoadAllTexture();
}

TextureHolder::~TextureHolder() {
    UnloadAllTexture();
}

void TextureHolder::LoadAllTexture() {
    // Load Character Texture
    string character_textures_filepath = "../resources/Pictures/Character/";
    for (int i = 0; i < NumberOfCharacter; i++) {
        string char_i_filepath = character_textures_filepath + char(i + '0') + "/";
        for (int j = 1; j <= 9; j++) {
            Texture2D *texture = new Texture2D();
            GetTexture(PeopleWidth, PeopleHeight, char_i_filepath + "image_part_00" + char(j + '0') + ".png", *texture);
            Character[i].push_back(texture);
        }
        for (int j = 0; j <= 6; j++) {
            Texture2D *texture = new Texture2D();
            GetTexture(PeopleWidth, PeopleHeight, char_i_filepath + "image_part_01" + char(j + '0') + ".png", *texture);
            Character[i].push_back(texture);
        }
    }

    // Load Animal Texture
    string animal_textures_filepath = "../resources/Pictures/Animal/";
    for (int i = 0; i < NumberOfAnimal; i++) {
        string animal_i_filepath = animal_textures_filepath + char(i + '0') + "/";
        for (int j = 0; j < 3; j++) {
            Texture2D *texture = new Texture2D();
            GetTexture(AnimalWidth, AnimalHeight, animal_i_filepath + char(j + '0') + ".png", *texture);
            Animal[i].push_back(texture);
        }
    }

    // Load Traffic Light Texture
    for (int i = 0; i < NumberOfTrafficLight; i++) {
        string traf_i_filepath = "../resources/Pictures/Traffic_light/" + to_string(i) + ".png";
        Texture2D *texture = new Texture2D();
        GetTexture(TrafficLightWidth, TrafficLightHeight, traf_i_filepath, *texture);
        Traffic_light.push_back(texture);
    }

    // Load Forest Texture
    string forest_textures_filepath = "../resources/Pictures/Lane/Forest/";
    for (int i = 1; i <= 3; i++) {
        Texture2D *texture = new Texture2D();
        GetTexture(LaneWidth, LaneHeight, forest_textures_filepath + char(i + '0') + ".png", *texture);
        Forest.push_back(texture);
    }

    // Load Road Texture
    string road_textures_filepath = "../resources/Pictures/Lane/Road/";
    for (int i = 1; i <= 1; i++) {
        Texture2D *texture = new Texture2D();
        GetTexture(LaneWidth, LaneHeight, road_textures_filepath + char(i + '0') + ".png", *texture);
        Road.push_back(texture);
    }

    // Load Vehicle Texture
    string vehicle_textures_filepath = "../resources/Pictures/Vehicle/";
    for (int i = 0; i < NumberOfVehicle; i++) {
        Texture2D *texture = new Texture2D();
        GetTexture(VehicleWidth, VehicleHeight, vehicle_textures_filepath + char(i + '0') + ".png", *texture);
        Vehicle.push_back(texture);
    }
}

// TextureHolder::~TextureHolder() {
//     Clear();
// }

void TextureHolder::UnloadAllTexture() {
    // Unload Character Texture
    for (int i = 0; i < NumberOfCharacter; i++) {
        for (int j = 0; j < (int)Character[i].size(); j++) {
            UnloadTexture(*Character[i][j]);
            delete Character[i][j];
        }
        Character[i].clear();
    }

    // Unload Vehicle Texture
    for (int i = 0; i < 3; i++) {
        UnloadTexture(*Vehicle[i]);
        delete Vehicle[i];
    }
    Vehicle.clear();

    // Unload Animal Texture
    for (int i = 0; i < NumberOfAnimal; i++) {
        for (int j = 0; j < (int)Animal[i].size(); j++) {
            UnloadTexture(*Animal[i][j]);
            delete Animal[i][j];
        }
        Animal[i].clear();
    }

    // Unload Traffic Light Texture
    for (int i = 0; i < 3; i++) {
        UnloadTexture(*Traffic_light[i]);
        delete Traffic_light[i];
        Traffic_light.clear();
    }

    // Unload Forest Texture
    for (int i = 0; i < (int)Forest.size(); i++) {
        UnloadTexture(*Forest[i]);
        delete Forest[i];
    }
    Forest.clear();

    // Unload Road Texture
    for (int i = 0; i < (int)Road.size(); i++) {
        UnloadTexture(*Road[i]);
        delete Road[i];
    }
    Road.clear();

    // Unload Item Texture
    for (int i = 0; i < NumberOfItems; i++) {
        for (int j = 0; j < (int)Item[i].size(); j++) {
            UnloadTexture(*Item[i][j]);
            delete Item[i][j];
        }
        Item[i].clear();
    }
}

vector <Texture2D *> TextureHolder::GetCharacter(int Character) {
    return TextureHolder::Character[Character];
}

vector <Texture2D *> TextureHolder::GetForestTextures() {
    return TextureHolder::Forest;
}

Texture2D *TextureHolder::GetForest(int index) {
    return TextureHolder::Forest[index];
}

vector <Texture2D *> TextureHolder::GetRoadTextures() {
    return TextureHolder::Road;
}

Texture2D *TextureHolder::GetRoad(int index) {
    return TextureHolder::Road[index];
}

vector <Texture2D *> TextureHolder::GetTrafficLight() {
    return TextureHolder::Traffic_light;
}

vector <Texture2D *> TextureHolder::GetVehicle() {
    return TextureHolder::Vehicle;
}

vector <Texture2D *> TextureHolder::GetAnimal(int index) {
    return TextureHolder::Animal[index];
}

void TextureHolder::LoadTexture(const string& filepath, const string& name) {
    //TODO
}