#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "../Helper/TextureHelper.h"
#include "TextureHolder.h"

#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

#include <iostream>

using namespace std;

class Setting {
    private:
    int OptionIndex = 0;
    int MainSetting[3] = { 1, 0, 0}; // FPS, Character, Mute
    const int MaxOption[3] = { 3, 3, 2};
    const int FPSoptions[3] = { 30, 60, 120};
    const int Character = 3;
    const int Mute = 2;
    const string SettingMenu[3] = { "FPS: ", "Character: ", "Mute: "};

    public:
    int GetFPS() { return FPSoptions[MainSetting[0]]; }
    int GetCharacter() { return MainSetting[1]; }
    bool GetMute() { return MainSetting[2]; }

    void Update() {
        if (IsKeyPressed(KEY_RIGHT)) MainSetting[OptionIndex] = (MainSetting[OptionIndex] + 1) % MaxOption[OptionIndex];
        if (IsKeyPressed(KEY_LEFT)) MainSetting[OptionIndex] = (MainSetting[OptionIndex] + MaxOption[OptionIndex] - 1) % MaxOption[OptionIndex];
        if (IsKeyPressed(KEY_DOWN)) OptionIndex = (OptionIndex + 1) % 3;
        if (IsKeyPressed(KEY_UP)) OptionIndex = (OptionIndex + 2) % 3;

        // temporary
        if (GetMute()) {
            SetMasterVolume(0);
        }
        else {
            SetMasterVolume(1);
        }
    }

    void Draw() {
        BeginDrawing();
        ClearBackground(GRAY);
        DrawText("Setting", screenWidth / 2 - MeasureText("Setting", 20) / 2, 100, 20, BLACK);
        for (int i = 0; i < 3; i++) {
            if (i == OptionIndex) {
                DrawText(SettingMenu[i].c_str(), screenWidth / 4 , screenHeight / 2 - 20 + i * 40, 20, RED);
            }
            else {
                DrawText(SettingMenu[i].c_str(), screenWidth / 4 , screenHeight / 2 - 20 + i * 40, 20, BLACK);
            }

            string temp = (i == 0) ? to_string(FPSoptions[MainSetting[i]]) : to_string(MainSetting[i]);
            temp = (i == 2) ? (MainSetting[i] == 0 ? "Off" : "On") : temp;
            DrawText(temp.c_str(), screenWidth / 2 , screenHeight / 2 - 20 + i * 40, 20, BLACK);
        }
        DrawText("Press Enter to go back to menu", screenWidth / 2 - MeasureText("Press Enter to go back to menu", 16) / 2, 800, 20, BLACK);
        EndDrawing();
    }
};