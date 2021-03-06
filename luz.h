#ifndef LUZ_H
#define LUZ_H

#include <vector>

using namespace std;

class Luz
{
    float x, y, z;
    float r, g, b;
    vector<float> posicao;
    vector<float> rgb;
public:
    Luz();
    Luz(float, float, float);
    float getX();
    float getY();
    float getZ();
    float getR();
    float getG();
    float getB();
    vector<float> getPos();
    vector<float> getRGB();
};

#endif // LUZ_H
