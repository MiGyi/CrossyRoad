#include "Map.h"

using namespace std;
 
Map::Map() { // Default constructor for testing, will be removed later, default speed is 100.0f
    int y = 0;
    int RandLineSafety[NumberOfLine - 1]; // 1: safe, 0: unsafe
    for (int i = 0; i < NumberOfLine - 4; i++) RandLineSafety[i] = 0;
    for (int i = NumberOfLine - 4; i < NumberOfLine - 1; i++) RandLineSafety[i] = 1;
    shuffle(RandLineSafety, RandLineSafety + NumberOfLine - 1, default_random_engine(time(NULL)));
    for (int i = 0; i < NumberOfLine - 1; i++) {
        int getRand = GetRandomValue(0, 1); // 0: Vehicle from right to left, 1: Vehicle from left to right
        int getRandType = GetRandomValue(0, 1); //0: Forest, 1: Road
        getRand += getRand;
        if (getRandType) Lines.push_back(new Road(y, RandLineSafety[i], 50.0f * (getRand - 1.0f), 5));
            else Lines.push_back(new Forest(y, RandLineSafety[i], 50.0f * (getRand - 1.0f), 5));
        y += LineHeight;
    }
    Lines.push_back(new Forest(y, true, 0, 0)); // first line is always safe
}

Map::Map(float Speed, int NumOfLines, int NumOfVehicles, int NumOfAnimals) {
    float y = 0;
    int NumOfSafeLine = NumOfLines / 3 * 2 - 1; // 2/3 of lines are safe, first line is always safe
    int *RandLineSafety = new int [NumOfLines - 1]; // 1: safe, 0: unsafe
    for (int i = 0; i < NumOfLines; i++) RandLineSafety[i] = 1;
    for (int i = 0; i < NumOfSafeLine; i++) RandLineSafety[i] = 0;
    shuffle(RandLineSafety, RandLineSafety + NumOfLines - 1, default_random_engine(time(NULL)));
    for (int i = 0; i < NumOfLines - 1; i++) {
        int getRand = GetRandomValue(0, 1); // 0: Vehicle from right to left, 1: Vehicle from left to right
        int getRandType = GetRandomValue(0, 1); //0: Forest, 1: Road
        getRand += getRand;
        if (getRandType) Lines.push_back(new Road(y, RandLineSafety[i], Speed * (getRand - 1.0f), NumOfVehicles));
            else Lines.push_back(new Forest(y, RandLineSafety[i], Speed * (getRand - 1.0f), NumOfAnimals));
        y += (screenHeight * 1.0f) / (NumOfLines * 1.0f);
    }
    delete [] RandLineSafety;
    Lines.push_back(new Forest(y, true, 0, 0)); // first line is always safe
}

bool Map::Collision(Rectangle Player) {
    for (auto &i : Lines) {
        if (i->Collision(Player)) return true;
    }
    return false;
}

void Map::Update(float DeltaTime) {

    for (auto &i : Lines) {
        i->Update(DeltaTime);
    }

}

void Map::Draw() {
    for (auto &i : Lines) {
        i->Draw();
    }
}

Map::~Map() {
    while (!Lines.empty()) {
        delete Lines.back();
        Lines.pop_back();
    }
}