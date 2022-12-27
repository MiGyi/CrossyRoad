#include "Line.h"
#include "Vehicle.h"

class Road: public Line {
    public:
        Road(float y, bool isSafe, float speed, int MaxObject);
        void GenerateObject();
        ~Road();
};