#ifndef OBJETO_H
#define OBJETO_H

#include "calc.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

class Objeto
{
    vector<Face> faces;
    vector<Face> lerFaces();
public:
    Objeto();
    vector<Face> getFaces();
};

#endif // OBJETO_H
