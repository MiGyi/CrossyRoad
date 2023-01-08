// Example of using the Menu class
// while (true) {
//     MenuOptions curPessed = menu->Update();
//     if (curPessed != MenuOptions::NONE) {
//         cerr << "Pressed: " << (int)curPessed << endl;
//     }
// }

#pragma once

#include "raylib.h"
#include "../Helper/Const.h"
#include "SoundHolder.h"
#include <string>

using namespace std;

enum class MenuOptions {
    NEWGAME,
    LOADGAME,
    SCOREBOARD,
    SETTING,
    EXIT,
    NONE = -1
};

class Menu {
private:
    const int numMenuOptions = 5;
    const string menuOptions[5] = { "New Game", "Load Game", "Scoreboard", "Setting", "Exit" }; 
    MenuOptions curOption = MenuOptions::NEWGAME;
    
public:
    Menu();
    ~Menu();
    MenuOptions Update();
    void Draw();

};