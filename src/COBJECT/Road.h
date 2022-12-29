#include "Line.h"
#include "Vehicle.h"
#include "TrafficLight.h"

class Road: public Line {
    private:
        TrafficLight *Trafficlight = nullptr;
    public:
        Road(float y, bool isSafe, float speed, int MaxObject);
        Road(Texture2D *texture, float y, bool isSafe, float speed, int MaxObject);
        void Draw();
        void GenerateObject();
        ~Road();
};