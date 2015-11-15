#include "vertice.h"

using namespace std;

Vertice::Vertice()
{
    posicao.push_back(0);
    posicao.push_back(0);
    posicao.push_back(0);
    posicao.push_back(0);
}

Vertice::Vertice(float x, float y, float z)
{
    setPos(x, y, z);
}


float Vertice::getX(){
    return x;
}

float Vertice::getY(){
    return y;
}

float Vertice::getZ(){
    return z;
}

vector<float> Vertice::getPos(){
    return posicao;
}

void Vertice::setPos(float x, float y, float z)
{
    vector<float> pos;

    this->x = x;
    this->y = y;
    this->z = z;

    pos.push_back(x);
    pos.push_back(y);
    pos.push_back(z);
    pos.push_back(0);

    posicao = pos;
}

void Vertice::setPos(vector<float> vetor)
{
    this->x = vetor[0];
    this->y = vetor[1];
    this->z = vetor[2];

    posicao = vetor;
}
