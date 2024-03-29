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
        y += LaneHeight;
    }
    Lines.push_back(new Forest(y, true, 0, 0)); // first line is always safe
}

// Map::Map(float Speed, int NumOfLines, int NumOfVehicles, int NumOfAnimals) {
//     float y = 0;
//     int NumOfSafeLine = NumOfLines / 3 * 2 - 1; // 2/3 of lines are safe, first line is always safe
//     int *RandLineSafety = new int [NumOfLines - 1]; // 1: safe, 0: unsafe
//     for (int i = 0; i < NumOfLines; i++) RandLineSafety[i] = 1;
//     for (int i = 0; i < NumOfSafeLine; i++) RandLineSafety[i] = 0;
//     shuffle(RandLineSafety, RandLineSafety + NumOfLines - 1, default_random_engine(time(NULL)));
//     for (int i = 0; i < NumOfLines - 1; i++) {
//         int getRand = GetRandomValue(0, 1); // 0: Vehicle from right to left, 1: Vehicle from left to right
//         int getRandType = GetRandomValue(0, 1); //0: Forest, 1: Road
//         getRand += getRand;
//         if (getRandType) Lines.push_back(new Road(y, RandLineSafety[i], Speed * (getRand - 1.0f), NumOfVehicles));
//             else Lines.push_back(new Forest(y, RandLineSafety[i], Speed * (getRand - 1.0f), NumOfAnimals));
//         y += (screenHeight * 1.0f) / (NumOfLines * 1.0f);
//     }
//     delete [] RandLineSafety;
//     Lines.push_back(new Forest(y, true, 0, 0)); // first line is always safe
// }

Map::Map(float speed, int NumOfLanes, int NumOfVehicles, int NumOfAnimals) {
    LaneTexture[0] = TextureHolder::GetInstance()->GetForestTextures();
    LaneTexture[1] = TextureHolder::GetInstance()->GetRoadTextures();
    RegenMap(speed, NumOfLanes, NumOfVehicles, NumOfAnimals);
}

void Map::GenLane() {
    float y = 0;
    int NumOfSafeLine = NumOfLanes / 3 * 2 - 1; // 2/3 of lines are safe, first line is always safe
    int *RandLineSafety = new int [NumOfLanes - 1]; // 1: safe, 0: unsafe
    for (int i = 0; i < NumOfLanes; i++) RandLineSafety[i] = 1;
    for (int i = 0; i < NumOfSafeLine; i++) RandLineSafety[i] = 0;
    shuffle(RandLineSafety, RandLineSafety + NumOfLanes - 1, default_random_engine(time(NULL)));
    for (int i = 0; i < NumOfLanes - 1; i++) {
        int getRand = GetRandomValue(0, 1); // 0: Vehicle from right to left, 1: Vehicle from left to right
        int getRandType = GetRandomValue(0, 1); //0: Forest, 1: Road
        getRand += getRand;
        if (getRandType) Lines.push_back(new Road(LaneTexture[getRandType][0], y, RandLineSafety[i], speed * (getRand - 1.0f), NumOfVehicles)); // TODO: add texture constructor for Road
            else {
                int RoadType = GetRandomValue(0, 2);
                Lines.push_back(new Forest(LaneTexture[getRandType][RoadType], RoadType, y, RandLineSafety[i], speed * (getRand - 1.0f), NumOfAnimals));
            }
        y += (screenHeight * 1.0f) / (NumOfLanes * 1.0f);
    }
    delete [] RandLineSafety;
    int RoadType = GetRandomValue(0, 2);
    Lines.push_back(new Forest(LaneTexture[0][RoadType], RoadType, y, true, 0, 0)); // first line is always safe
}

bool Map::Collision(Rectangle Player) {
    for (auto &i : Lines) {
        if (i->Collision(Player)) return true;
    }
    return false;
}

int Map::GetScore(Rectangle Player) {
    int score = 0;
    for (auto &i : Lines) {
        score += i->GetScore(Player);
    }
    return score;
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

void Map::RegenMap(float Speed, int NumOfLines, int NumOfVehicles, int NumOfAnimals) {
    this->speed = Speed;
    this->NumOfLanes = NumOfLines;
    this->NumOfVehicles = NumOfVehicles;
    this->NumOfAnimals = NumOfAnimals;

    for (int i = 0; i < (int)Lines.size(); i++) {
        Lines[i]->ClearObject();
    }
    while (!Lines.empty()) {
        delete Lines.back();
        Lines.pop_back();
    }
    this->GenLane();
}

Map::~Map() {
    while (!Lines.empty()) {
        delete Lines.back();
        Lines.pop_back();
    }
    LaneTexture[0].clear();
    LaneTexture[1].clear();
}

void Map::save(std::ofstream& fout) {
    fout << NumOfLanes << '\n';
    fout << NumOfVehicles << '\n';
    fout << NumOfAnimals << '\n';
    fout << speed << '\n';
    for (int i = 0; i < NumOfLanes; ++i) {
        Lines[i]->save(fout);
    }
}

void Map::load(std::ifstream& fin) {
    fin >> NumOfLanes;
    fin >> NumOfVehicles;
    fin >> NumOfAnimals;
    fin >> speed;

    for (int i = 0; i < (int)Lines.size(); i++) {
        Lines[i]->ClearObject();
    }
    while (!Lines.empty()) {
        delete Lines.back();
        Lines.pop_back();
    }

    //LaneTexture[0] = TextureHolder::GetForestTextures();
    //LaneTexture[1] = TextureHolder::GetRoadTextures();

    for (int i = 0; i < NumOfLanes; ++i) {
        int type;
        fin >> type;
        if (type) {
            Road* road = new Road(0, 0, 0, 0);
            road->load(fin, LaneTexture[1][0]);
            Lines.push_back(road);
        }
        else {
            int type2;
            fin >> type2;
            Forest* forest = new Forest(0, 0, 0, 0);
            forest->load(fin, LaneTexture[0][type2], type2);
            Lines.push_back(forest);
        }
    }
}
