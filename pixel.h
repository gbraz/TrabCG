#ifndef PIXEL_H
#define PIXEL_H

#include <vector>

using namespace std;

class Pixel
{
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    vector<float> pos;
    vector<float> rgb;

public:
    Pixel();

    float getR();
    float getG();
    float getB();
    vector<float> getPos();
    vector<float> getRGB();
    void setPos(float x, float y, float z);
    void setRGB(float r, float g, float b);
};

#endif // PIXEL_H
