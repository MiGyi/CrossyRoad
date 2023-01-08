#include "raylib.h"
#include "Object.h"
#include "Map.h"
#include "Player.h"
#include "Score.h"
#include "TextureHolder.h"
#include "SoundHolder.h"

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
    float speed = BaseSpeed;

    Player *player = nullptr;
    Map *map = nullptr;
    Score *score = nullptr;
public:
    Room();
    Room(int Character) {
        player = new Player(Character);
        map = new Map(this->speed, 9, 6, 6);
        score = new Score();
    }
    ~Room();
    bool Collision();
    bool Update(float GFT);
    void Draw();
    void pauseToggle();
    int GetScore() { return 0;}

    void save();
    void load();
};
