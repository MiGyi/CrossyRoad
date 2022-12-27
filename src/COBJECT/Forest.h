#include "Line.h"
#include "Animal.h"

class Forest: public Line {
    public:
        Forest(float y, bool isSafe, float speed, int MaxObject);
        void GenerateObject();
        ~Forest();
};