#include "pixel.h"

Pixel::Pixel()
{

}

void Pixel::setPos(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;

    vector<float> pos;
    pos.push_back(x);
    pos.push_back(y);
    pos.push_back(z);
    this->pos = pos;
}

void Pixel::setRGB(float r, float g, float b){
    this->r = r;
    this->g = g;
    this->b = b;

    vector<float> rgb;
    rgb.push_back(x);
    rgb.push_back(y);
    rgb.push_back(z);
    this->rgb = rgb;
}

vector<float> Pixel::getPos(){
    return this->pos;
}

vector<float> Pixel::getRGB(){
    return this->rgb;
}

float Pixel::getR(){
    return this->r;
}

float Pixel::getG(){
    return this->g;
}

float Pixel::getB(){
    return this->b;
}
