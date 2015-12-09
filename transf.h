#ifndef TRANSF_H
#define TRANSF_H

#include "calc.h"

class Transf
{
public:
    Transf();
    vector< vector<float> > translacao();
    vector< vector<float> > rotacao();
    vector< vector<float> > cisalhamento();
    vector< vector<float> > espelho();
};

#endif // TRANSF_H
