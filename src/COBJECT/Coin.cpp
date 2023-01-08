#include "Coin.h"

Coin::Coin(float x, float y) {
    this->x = x;
    this->y = y;
    this->speed = 100.0f;
    this->motion = TextureHolder::GetInstance()->GetCoin();
}

void Coin::Update(float DeltaTime) {
    this->motion_timer += DeltaTime * abs(this->speed / BaseSpeed) * AnimalAnimationSpeed ;
    if (this->motion_timer > 0.2f) {
        this->motion_index++;
        this->motion_timer = 0.0f;
    }

    if (this->motion_index >= (int)this->motion.size()) {
        this->motion_index = 0;
    }
}

void Coin::Draw() {
    DrawTexturePro(*motion[motion_index], { 0, 0, CoinWidth, CoinHeight }, { x, y, CoinWidth, CoinHeight }, { 0, 0 }, 0, WHITE);
    DrawRectangleLines(x, y, CoinWidth, CoinHeight, YELLOW);
}

Rectangle Coin::getBoundingBox() {
    return { x, y, CoinWidth, CoinHeight };
}

Coin::~Coin() {
    motion.clear();
}

void Coin::save(std::ofstream& fout) {
    Object::save(fout);
}

void Coin::load(std::ifstream& fin) {
    Object::load(fin);
    this->motion = TextureHolder::GetInstance()->GetCoin();
}
