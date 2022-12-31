#pragma once

#include "raylib.h"
#include "Object.h"
#include "Map.h"
#include "Player.h"
#include "TextureHolder.h"
#include "Room.h"
#include "Menu.h"

#include <iostream>
#include <vector>

enum class ScreenState {
    MENU,
    INGAME,
    SCOREBOARD,
    NONE = -1
};

class Game {
    private:
        Room *room = nullptr;
        Menu *menu = nullptr;
        int score = 0;
        ScreenState state = ScreenState::MENU;
    public:
        Game();
        ~Game();
        void updateRoom();
        void updateMenu();
        void run();
        void saveGame();
        void loadGame();
};