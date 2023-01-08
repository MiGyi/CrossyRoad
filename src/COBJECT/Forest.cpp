#include "Forest.h"

using namespace std;

Forest::Forest(float y, bool isSafe, float speed, int MaxObject) {
    this->y = y;
    this->speed = speed;
    this->isSafe = isSafe;
    this->MaxObject = isSafe ? 0 : MaxObject;
}

Forest::Forest(Texture2D *texture, int type, float y, bool isSafe, float speed, int MaxObject) {
    this->texture = texture;
    this->type = type;
    this->y = y;
    this->speed = speed;
    this->isSafe = isSafe;
    this->MaxObject = isSafe ? 0 : MaxObject;
    GenerateCoin();
}

void Forest::GenerateObject() {
    if ((int)Objects.size() >= MaxObject) return;
    if (speed > 0 && !Objects.empty() && Objects.back()->GetX() < 100) return;
    if (speed < 0 && !Objects.empty() && Objects.back()->GetX() > screenWidth - 200) return;
    int getRand = GetRandomValue(1, 150);
    if (getRand == 6) {
        int randIndex = GetRandomValue(0, NumberOfAnimal - 1);
        Objects.push_back(new Animal(y, speed, speed > 0, randIndex));
    }
};

Forest::~Forest() {
    ClearObject();
    ClearCoin();
    texture = nullptr;
}

void Forest::save(std::ofstream& fout) {
    fout << "0\n";
    fout << type << '\n';
    //fout << "Forest_start\n";
    Line::save(fout);
    //fout << "Forest_end\n";
}

void Forest::load(std::ifstream& fin, Texture2D* texture, int type) {
    this->texture = texture;
    this->type = type;
    //string comment;
    //fin >> comment;
    Line::load(fin);
    //fin >> comment;
}
