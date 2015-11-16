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
    vector<float> verticesParaVetor(Vertice a, Vertice b);
    vector<float> produtoVetorial(vector<float> u, vector<float> v);
    void transVetUnitario(vector<float>& u);
    vector<float> coordMundoParaCam(Camera camera, Vertice vertice);
    vector<float> coordCamParaMundo(Camera camera, Vertice vertice);
    float produtoEscalar(vector<float>, vector<float>);
    vector<float> produtoMatrizVetor(vector<vector<float> >, vector<float>);
    vector<float> pontoIntersecao(vector<float>, Face);
};

#endif // MATRIZ_H
