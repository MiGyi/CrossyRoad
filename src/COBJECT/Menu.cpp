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
    // Draw title
    // font size = 80
    DrawText(menuTitle.c_str(), screenWidth / 2 - MeasureText(menuTitle.c_str(), 80) / 2, screenHeight / 2 - 300, 80, BLACK);
    // Draw options
    for (int i = 0; i < numMenuOptions; i++) {
        if (i == (int)curOption)
        {
            DrawText(menuOptions[i].c_str(), screenWidth / 2 - MeasureText(menuOptions[i].c_str(), 40) / 2, screenHeight / 2 - 40 + i * 80, 40, RED);
        }
        else
        {
            DrawText(menuOptions[i].c_str(), screenWidth / 2 - MeasureText(menuOptions[i].c_str(), 40) / 2, screenHeight / 2 - 40 + i * 80, 40, BLACK);
        }
    }
}