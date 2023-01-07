#pragma once

#include "raylib.h"
#include "Object.h"
#include "Map.h"
#include "Player.h"
#include "TextureHolder.h"
#include "Room.h"
#include "Menu.h"
#include "../Helper/Const.h"

#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <string>

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

        multiset<int> BestScores;
    public:
        Game();
        ~Game();
        void updateRoom();
        void updateMenu();
        void run();
        void saveGame();
        void loadGame();

        void UpdateBestScores();
        void SaveBestScores();
        void LoadBestScores();
        void updateScoreboard();
};
