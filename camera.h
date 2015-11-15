#ifndef CAMERA_H
#define CAMERA_H

#include "vertice.h"
#include <vector>

using namespace std;

class Camera
{
    float x, y, z;
    Vertice lookAt;
    vector<float> posicao;
    vector<float> i, j, k;

public:

    Camera(Vertice posicao, Vertice lookAt);
    Camera(vector<float> posicao, Vertice lookAt);
    float getX();
    float getY();
    float getZ();
    vector<float> getI();
    vector<float> getJ();
    vector<float> getK();
    vector<float> getPos();
};

#endif // CAMERA_H
