#include "SoundHolder.h"

SoundHolder::SoundHolder() {
    InitAudioDevice();  
    LoadAllSound();
}

SoundHolder& SoundHolder::GetInstance() {
    static SoundHolder instance;
    return instance;
}

Sound SoundHolder::GetCollisionSound() {
    return collsionSound;
}

Sound SoundHolder::GetClickSound() {
    return clickSound;
}

Sound SoundHolder::GetBackgoundSound() {
    return backgoundSound;
}

Sound SoundHolder::GetCoinSound() {
    return coinSound;
}

void SoundHolder::LoadAllSound() {
    collsionSound = LoadSound("../resources/Sounds/collision.wav");
    clickSound = LoadSound("../resources/Sounds/click.wav");
    backgoundSound = LoadSound("../resources/Sounds/background.mp3");
    coinSound = LoadSound("../resources/Sounds/coin.wav");
}

SoundHolder::~SoundHolder() {
    UnloadSound(collsionSound);
    UnloadSound(clickSound);
    UnloadSound(backgoundSound);
    UnloadSound(coinSound);
    CloseAudioDevice();
}