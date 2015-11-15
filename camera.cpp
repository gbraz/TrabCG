#include "camera.h"
#include "calc.h"
#include <math.h>


Camera::Camera(Vertice posicao, Vertice lookAt)
{
    vector<float> vUp;
    Vertice viewUp(lookAt.getX(), lookAt.getY() + 1, lookAt.getZ());
    Calc m;

    this->posicao = posicao.getPos();
    this->lookAt = lookAt;

    vUp = m.verticesParaVetor(viewUp, posicao);

    this->k = m.verticesParaVetor(posicao, lookAt);
    m.transVetUnitario(this->k);

    this->i = m.produtoVetorial(vUp, this->k);
    m.transVetUnitario(this->i);

    this->j = m.produtoVetorial(this->k, this->i);

}

vector<float> Camera::getPos(){
    return posicao;
}

float Camera::getX(){
    return x;
}

float Camera::getY(){
    return y;
}

float Camera::getZ(){
    return z;
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

