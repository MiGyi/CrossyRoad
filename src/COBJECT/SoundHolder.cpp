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

void SoundHolder::LoadAllSound() {
    collsionSound = LoadSound("../resources/Sounds/collision.wav");
    clickSound = LoadSound("../resources/Sounds/click.wav");
}

SoundHolder::~SoundHolder() {
    UnloadSound(collsionSound);
    UnloadSound(clickSound);
    CloseAudioDevice();
}