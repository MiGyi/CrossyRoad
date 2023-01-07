#include "Line.h"
#include "Animal.h"
#include <fstream>

class Forest: public Line {
    private:
        int type;
    public:
        Forest(float y, bool isSafe, float speed, int MaxObject);
        Forest(Texture2D *texture, int type, float y, bool isSafe, float speed, int MaxObject);
        void GenerateObject();
        ~Forest();

        void save(std::ofstream& fout);
        void load(std::ifstream& fin, Texture2D* texture, int type);
};
