#include "Line.h"
#include "Vehicle.h"
#include "TrafficLight.h"

class Road: public Line {
    public:
        Road(float y, bool isSafe, float speed, int MaxObject);
        Road(Texture2D *texture, float y, bool isSafe, float speed, int MaxObject);
        void GenerateObject();
        ~Road();
};