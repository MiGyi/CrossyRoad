#include "raylib.h"
#include "Object.h"
#include "Map.h"
#include "Player.h"
#include "TextureHolder.h"

#include <math.h>
#include <string>
#include <vector>
#include <iostream>

class Room{
private:
    Player *player = nullptr;
    Map *map = nullptr;
    float speed = 100.0f;

public:
    Room();
    ~Room();
    bool Collision();
    void Update(float GFT);
    void Draw();
};