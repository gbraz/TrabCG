#include "face.h"
#include "calc.h"


Face::Face(Vertice vertice1, Vertice vertice2, Vertice vertice3)
{
    Calc calc;

    this->vertice1 = vertice1;
    this->vertice2 = vertice2;
    this->vertice3 = vertice3;

    normal = calc.produtoVetorial(calc.verticesParaVetor(vertice3, vertice1),
                         calc.verticesParaVetor(vertice2, vertice1));

}

Face::Face(Vertice vertice1, Vertice vertice2, Vertice vertice3, vector<float> normal)
{
    this->vertice1 = vertice1;
    this->vertice2 = vertice2;
    this->vertice3 = vertice3;
    this->normal = normal;
}

Vertice Face::getVertice1(){
    return vertice1;
}

Vertice Face::getVertice2(){
    return vertice2;
}

Vertice Face::getVertice3(){
    return vertice3;
}

vector<float> Face::getNormal(){
    return normal;
}
