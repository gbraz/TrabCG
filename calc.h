#ifndef CALC_H
#define CALC_H

#include <math.h>
#include <vector>
#include "face.h"
#include "vertice.h"
#include "camera.h"

using namespace std;

class Calc
{
public:
    Calc();
    vector<float> verticesParaVetor(Vertice, Vertice);
    vector<float> produtoVetorial(vector<float>, vector<float>);
    void transVetUnitario(vector<float>& u);
    vector<float> coordMundoParaCam(Camera, Vertice);
    vector<float> coordCamParaMundo(Camera, Vertice);
    float produtoEscalar(vector<float>, vector<float>);
    vector<float> produtoMatrizVetor(vector<vector<float> >, vector<float>);
    vector<float> pontoIntersecao(vector<float>, Face);
    bool interceptaFace(vector<float>, Face);

};

#endif // MATRIZ_H
