#ifndef CALC_H
#define CALC_H

#include <math.h>
#include <vector>
#include "face.h"
#include "vertice.h"
#include "camera.h"
#include "luz.h"
#include "objeto.h"

using namespace std;

class Calc
{
public:
    Calc();
    vector<float> subtracaoVetores(vector<float>, vector<float>);
    vector<float> verticesParaVetor(Vertice, Vertice);
    vector<float> produtoVetorial(vector<float>, vector<float>);
    void transVetUnitario(vector<float>& u);
    vector<float> coordMundoParaCam(Camera, Vertice);
    vector<float> coordCamParaMundo(Camera, Vertice);
    float produtoEscalar(vector<float>, vector<float>);
    vector<float> produtoMatrizVetor(vector<vector<float> >, vector<float>);
    vector<float> pontoIntersecao(vector<float>, Face);
    bool interceptaFace(vector<float>, Face);
    vector<float> getPixel(vector<float>, vector<Face>, Luz);
    vector< vector< vector<float> > > gerarImagem(int xPixels, int yPixels, float width, float height, float dist, vector<Face> listaFace, Luz luz);
};

#endif // MATRIZ_H
