#ifndef LUZ_H
#define LUZ_H


class Luz
{
    float x, y, z;
    float r, g, b;
    vector<float> posicao;
    vector<float> rgb;
public:
    Luz();
    float getX();
    float getY();
    float getZ();
    float getR();
    float getG();
    float getB();
    vector<float> getPos();
    vector<float> getRGB();
};

#endif // LUZ_H
