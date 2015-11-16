#ifndef FACE_H
#define FACE_H

#include "vertice.h"
#include "vetor.h"


class Face
{
    Vertice vertice1;
    Vertice vertice2;
    Vertice vertice3;
    std::vector<float> normal;
public:

    Face(Vertice vertice1, Vertice vertice2, Vertice vertice3);
    Face(Vertice vertice1, Vertice vertice2, Vertice vertice3, vector<float> normal);
    Vertice getVertice1();
    Vertice getVertice2();
    Vertice getVertice3();
    vector<float> getNormal();
};

#endif // FACE_H
