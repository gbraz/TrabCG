#include "luz.h"

Luz::Luz()
{
    x = 0;
    y = 0;
    z = 0;

    posicao.push_back(x);
    posicao.push_back(y);
    posicao.push_back(z);
    posicao.push_back(0);

    r = 1;
    g = 1;
    b = 1;

    rgb.push_back(r);
    rgb.push_back(g);
    rgb.push_back(b);
}

float Luz::getX(){
    return x;
}

float Luz::getY(){
    return y;
}

float Luz::getZ(){
    return z;
}

float Luz::getR(){
    return r;
}

float Luz::getG(){
    return g;
}

float Luz::getB(){
    return b;
}

vector<float> Luz::getPos(){
    return posicao;
}
vector<float> Luz::getRGB(){
    return rgb;
}
