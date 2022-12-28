#pragma once

#include "raylib.h"
#include "Object.h"
#include "Map.h"
#include "Player.h"
#include "TextureHolder.h"
#include "Room.h"

#include <iostream>
#include <vector>

enum class GameState {
    Running,
    Paused,
    GameOver
};

class Game {
    private:
        Room *room = nullptr;
        int score = 0;
        GameState state;

    public:
        Game();
        Game(TextureHolder *textureHolder);
        ~Game();
        bool loop();

        void saveGame();
        void loadGame();
};