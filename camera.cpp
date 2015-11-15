#include "camera.h"
#include "calc.h"
#include <math.h>


Camera::Camera(Vertice posicao, Vertice lookAt)
{
    vector<float> vUp;
    Vertice viewUp(lookAt.x, lookAt.y + 1, lookAt.z);
    Calc m;

    this->posicao = posicao;
    this->lookAt = lookAt;

    vUp = m.verticesParaVetor(viewUp, posicao);

    this->k = m.verticesParaVetor(posicao, lookAt);
    m.transVetUnitario(this->k);

    this->i = m.produtoVetorial(vUp, this->k);
    m.transVetUnitario(this->i);

    this->j = m.produtoVetorial(this->k, this->i);

}

Vertice Camera::getPos(){
    return this->posicao;
}

vector<float> Camera::getI(){
    return i;
}

vector<float> Camera::getJ(){
    return j;
}

vector<float> Camera::getK(){
    return k;
}

