#ifndef VERTICE_H
#define VERTICE_H

#include<vector>

using namespace std;

class Vertice
{
    float x;
    float y;
    float z;
    vector <float> posicao;
public:

    Vertice();
    Vertice(float x, float y, float z);

    float getX();
    float getY();
    float getZ();
    vector<float> getPos();
    void setPos(float x, float y, float z);
    void setPos(vector<float> posicao);
};

#endif // VERTICE_H
