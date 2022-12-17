#include "CLine.h"
#include "CAnimal.h"

class CForest: public CLine {
    public:
        CForest(float y, bool isSafe, float speed, int MaxObject);
        void GenerateObject();
        ~CForest();
};