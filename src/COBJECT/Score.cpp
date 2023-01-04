#include "Score.h"

void Score::increase() {
    score++;
}

void Score::Draw() {
    DrawText(std::to_string(score).c_str(), 10, 10, 20, WHITE);
}

void Score::save(std::ofstream& fout) {
    fout << score << '\n';
}

void Score::load(std::ifstream& fin) {
    fin >> score;
}

