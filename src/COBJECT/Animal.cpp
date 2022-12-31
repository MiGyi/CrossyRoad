#include "Animal.h"

using namespace std;

Animal::Animal(float y, float speed, bool FromLeftToRight, int index) {
    this->x = FromLeftToRight ? -AnimalWidth : screenWidth;
    this->y = y;
    this->speed = speed;
    this->direction = FromLeftToRight ? 1 : -1;
    this->index = index;
    if (!FromLeftToRight && speed > 0) speed = -speed;
    this->motion = TextureHolder::GetAnimal(index);

}

void Animal::Update(float DeltaTime) {
    this->motion_timer += DeltaTime * abs(this->speed / BaseSpeed) * AnimalAnimationSpeed ;
    if (this->motion_timer > 0.2f) {
        this->motion_index++;
        this->motion_timer = 0.0f;
    }

    if (this->motion_index >= (int)this->motion.size()) {
        this->motion_index = 0;
    }
    this->x += DeltaTime * this->speed;
}

void Animal::Draw() {
    DrawTexturePro(*motion[motion_index], { 0, 0, AnimalWidth * float(direction), AnimalHeight }, { x, y, AnimalWidth, AnimalHeight }, { 0, 0 }, 0, WHITE);
    //DrawRectangleRec({ this->x, this->y, AnimalWidth, AnimalHeight }, RED);
    DrawRectangleLines(x, y, AnimalWidth, AnimalHeight, BLUE);
}

Rectangle Animal::getBoundingBox() {
    return { x, y, AnimalWidth, AnimalHeight };
}

Animal::~Animal() {
    motion.clear();
}

void Animal::save(std::ofstream& fout) {
    fout << "0\n";
    fout << direction << '\n';
    fout << index << '\n';
    Object::save(fout);
}

void Animal::load(std::ifstream& fin) {
    fin >> direction;
    fin >> index;
    motion = TextureHolder::GetAnimal(index);
    Object::load(fin);
}
