#include "Score.h"

void Score::increase(int x) {
    score += x;
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

int Score::GetScore() {
    return score;
}
