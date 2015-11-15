#include "vertice.h"

using namespace std;

Vertice::Vertice()
{
    vetor.push_back(0);
    vetor.push_back(0);
    vetor.push_back(0);
    vetor.push_back(0);
}

Vertice::Vertice(float x, float y, float z)
{
    setPos(x, y, z);
}

void Vertice::setPos(float x, float y, float z)
{
    vector<float> vetor;

    this->x = x;
    this->y = y;
    this->z = z;

    vetor.push_back(x);
    vetor.push_back(y);
    vetor.push_back(z);
    vetor.push_back(0);

    this->vetor = vetor;
}

void Vertice::setPos(vector<float> vetor)
{
    this->x = vetor[0];
    this->y = vetor[1];
    this->z = vetor[2];

    this->vetor = vetor;
}
