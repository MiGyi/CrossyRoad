#include "Line.h"

using namespace std;

void Line::Update(float DeltaTime) {

    if (isSafe) return;

    if (Objects.size() > 0) {

        if (this->speed > 0 && Objects.back()->GetX() > screenWidth) {
            delete Objects.front();
            Objects.erase(Objects.begin());
        }

        if (this->speed < 0 && Objects.front()->GetX() < -VehicleWidth * 2.0f) {
            delete Objects.front();
            Objects.erase(Objects.begin());
        }

    }

    GenerateObject();

    for (auto &i : Objects) {
        i->Update(DeltaTime);
    }
}

void Line::Draw() {
    if (!texture) DrawRectangleLines(0, y, screenWidth, LaneHeight, GREEN);
    else DrawTexturePro(*texture, { 0, y, LaneWidth, LaneHeight }, {0, y, LaneWidth, LaneHeight}, { 0, 0 }, 0, WHITE);
    //DrawRectangleRec({ 0, y, screenWidth, LineHeight }, GREEN);
    for (auto &i : Objects) {
        i->Draw();
    }
}

bool Line::Collision(Rectangle Player) {
    if (isSafe) return false;
    for (auto &i : Objects) {
        if (CheckCollisionRecs(Player, i->getBoundingBox())) return true;
    }
    return false;
}

void Line::ClearObject() {
    while (!Objects.empty()) {
        delete Objects.back();
        Objects.pop_back();
    }
}

void Line::save(std::ofstream& fout) {
    fout << x << ' ' << y << '\n';
    fout << speed << '\n';
    fout << isSafe << '\n';
    fout << MaxObject << '\n';
    fout << Objects.size() << '\n';
    for (int i = 0; i < (int)Objects.size(); ++i) {
        Objects[i]->save(fout);
    }
}

void Line::load(std::ifstream& fin) {
    fin >> x >> y;
    fin >> speed;
    fin >> isSafe;
    fin >> MaxObject;

    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        int type;
        fin >> type;
        if (type) {
            Vehicle* vehicle = new Vehicle(0, 0, 0, 0);
            vehicle->load(fin);
            Objects.push_back(vehicle);
        }
        else {
            Animal* animal = new Animal(0, 0, 0, 0);
            animal->load(fin);
            Objects.push_back(animal);
        }
    }
}
