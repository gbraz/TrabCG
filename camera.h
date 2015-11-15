#ifndef CAMERA_H
#define CAMERA_H

#include "vertice.h"
#include <vector>

using namespace std;

class Camera
{
    Vertice posicao;
    Vertice lookAt;
    vector<float> i, j, k;

public:

    Camera(Vertice posicao, Vertice lookAt);
    vector<float> getI();
    vector<float> getJ();
    vector<float> getK();
    Vertice getPos();
};

#endif // CAMERA_H
