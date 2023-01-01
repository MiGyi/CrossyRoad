#include "raylib.h"
#include "Object.h"
#include "Map.h"
#include "Player.h"
#include "TextureHolder.h"

#include <math.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

enum class RoomState {
    Running,
    Paused,
    GameOver
};

class Room{
private:
    RoomState state = RoomState::Running;
    int score = 0;
    float speed = BaseSpeed;
    Player *player = nullptr;
    Map *map = nullptr;
public:
    Room();
    ~Room();
    bool Collision();
    bool Update(float GFT);
    void Draw();
    void pauseToggle();

    void save();
    void load();
};
