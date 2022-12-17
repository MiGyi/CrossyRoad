#include "CLine.h"
#include "CVehicle.h"

class CRoad: public CLine {
    public:
        CRoad(float y, bool isSafe, float speed, int MaxObject);
        void GenerateObject();
        ~CRoad();
};