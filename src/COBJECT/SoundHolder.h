#pragma once

#include "raylib.h"
#include "../Helper/Const.h"

#include <vector>
#include <string>

// Singleton class
class SoundHolder {
private:
    SoundHolder();
    ~SoundHolder();

    SoundHolder(const SoundHolder &) = delete;
    SoundHolder &operator=(const SoundHolder &) = delete;

    Sound collsionSound;
    Sound clickSound;
    Sound backgoundSound;
    Sound coinSound;
    Sound engineSound;

    void LoadAllSound();

public:
    static SoundHolder &GetInstance();

    Sound GetCollisionSound();
    Sound GetClickSound();
    Sound GetBackgoundSound();
    Sound GetCoinSound();
    Sound GetEngineSound();
};