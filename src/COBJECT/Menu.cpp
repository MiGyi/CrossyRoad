#include "Menu.h"

Menu::Menu() {
}

Menu::~Menu() {
}

MenuOptions Menu::Update() {
    if (IsKeyPressed(KEY_DOWN)) {
        PlaySound(SoundHolder::GetInstance().GetClickSound());
        curOption = (MenuOptions)(((int)curOption + 1) % numMenuOptions);
    }
    else if (IsKeyPressed(KEY_UP)) {
        PlaySound(SoundHolder::GetInstance().GetClickSound());
        curOption = (MenuOptions)((((int)curOption) + numMenuOptions - 1) % numMenuOptions);
    }
    if (IsKeyPressed(KEY_ENTER)) {
        PlaySound(SoundHolder::GetInstance().GetClickSound());
        return curOption;
    }
    
    return MenuOptions::NONE;
}

void Menu::Draw() {
    for (int i = 0; i < numMenuOptions; i++) {
        if (i == (int)curOption)
        {
            DrawText(menuOptions[i].c_str(), screenWidth / 2 - MeasureText(menuOptions[i].c_str(), 20) / 2, screenHeight / 2 - 20 + i * 40, 20, RED);
        }
        else
        {
            DrawText(menuOptions[i].c_str(), screenWidth / 2 - MeasureText(menuOptions[i].c_str(), 20) / 2, screenHeight / 2 - 20 + i * 40, 20, BLACK);
        }
    }
}