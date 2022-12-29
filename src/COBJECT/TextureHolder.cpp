#include "TextureHolder.h"

using namespace std;

TextureHolder::TextureHolder() {
    string character_textures_filepath = "../resources/Pictures/Character/";
    string traffic_light_textures_filepath = "../resources/Pictures/Traffic_light/";
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

    for (int i = 0; i < NumberOfTrafficLight; i++) {
        string traf_i_filepath = "../resources/Pictures/Traffic_light/" + to_string(i) + ".png";
        Texture2D *texture = new Texture2D();
        GetTexture(TrafficLightWidth, TrafficLightHeight, traf_i_filepath, *texture);
        Traffic_light.push_back(texture);
    }
}

TextureHolder::~TextureHolder() {
    Clear();
}

void TextureHolder::Clear() {
    for (int i = 0; i < NumberOfCharacter; i++) {
        for (int j = 0; j < Character[i].size(); j++) {
            UnloadTexture(*Character[i][j]);
            delete Character[i][j];
        }
        Character[i].clear();
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < Vehicle[i].size(); j++) {
            UnloadTexture(*Vehicle[i][j]);
            delete Vehicle[i][j];
        }
        Vehicle[i].clear();
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < Animal[i].size(); j++) {
            UnloadTexture(*Animal[i][j]);
            delete Animal[i][j];
        }
        Animal[i].clear();
    }

    for (int i = 0; i < 3; i++) {
        UnloadTexture(*Traffic_light[i]);
        delete Traffic_light[i];
        Traffic_light.clear();
    }
}

vector <Texture2D *> TextureHolder::GetCharacter(int Character) {
    return this->Character[Character];
}

vector <Texture2D *> TextureHolder::GetTrafficLight(int TrafficLight) {
    return this->Traffic_light;
}

void TextureHolder::LoadTexture(const string& filepath, const string& name) {
    //TODO
}