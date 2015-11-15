#ifndef FACE_H
#define FACE_H

#include "vertice.h"


class Face
{
public:

    Vertice vertice1;
    Vertice vertice2;
    Vertice vertice3;
    std::vector<float> normal;
    Face();
};

#endif // FACE_H
