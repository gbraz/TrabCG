#ifndef VERTICE_H
#define VERTICE_H

#include<vector>

using namespace std;

class Vertice
{
public:
    float x;
    float y;
    float z;
    vector <float> vetor;

    Vertice();
    Vertice(float x, float y, float z);
    void setPos(float x, float y, float z);
    void setPos(vector<float> vetor);
};

#endif // VERTICE_H
