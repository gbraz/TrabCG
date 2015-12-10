#include "objeto.h"
#include <QDebug>

Objeto::Objeto()
{
    lerFaces();
}


vector<Face> Objeto::getFaces(){
    return faces;
}

//ler vertices
vector<Face> Objeto::lerFaces(){
    vector<Face> listaFace;
    vector<Vertice> listaVertice;
    vector< vector<float> > listaNormal;
    fstream file("./cubo.obj");

    string str;

    float x, y, z;
    int i, j, k, n;

    if (file.is_open()){

        getline(file, str);
        getline(file, str);
        getline(file, str);
        getline(file, str);
        getline(file, str);
        qDebug() << QString::fromStdString(str);

        while(!file.eof()){
            file >> str;
            if(!str.compare("v")){
                file >> x >> y >> z;
                Vertice vertice(x, y, z);
                listaVertice.push_back(vertice);
                qDebug() << QString::fromStdString(str) << x << y << z;
            }
            else if (!str.compare("vn")){
                file >> x >> y >> z;
                vector<float> normal;
                normal.push_back(x);
                normal.push_back(y);
                normal.push_back(z);
                normal.push_back(0);

                listaNormal.push_back(normal);
                qDebug() << QString::fromStdString(str) << x << y << z;
            }
            else if(!str.compare("f")){
                file >> i >> str >> j >> str >> k >> str;
                str = str.substr(2);
                n = QString::fromStdString(str).toInt();

                Face face(listaVertice[i-1], listaVertice[j-1], listaVertice[k-1], listaNormal[n-1]);

                qDebug() << QString::fromStdString(str) << i << j << k;
            }

        }
    }
