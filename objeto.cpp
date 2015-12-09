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
    fstream file("cubo.obj");
    string str;

    float x, y, z;

    file >> str;
    file >> str;
    file >> str;
    file >> str;

    file >> str >> x >> y >> z;
    while(!str.compare("v")){
        Vertice vertice(x, y, z);
        listaVertice.push_back(vertice);

        file >> str >> x >> y >> z;
        qDebug() << QString::fromStdString(str);
    }

    /*
    FILE *file;
    file = fopen("cubo.obj", "r");

    if(!file){

        vector< vector<int> > v;

        int numVertices;
        float x, y, z;

        fscanf(file, "v %f %f %f", &x, &y, &z);



        int x, y, z;
        int i = 1;

        while(!file.eof()){

            file >> x >> y >> z;

            v[i][1] = x;
            v[i][2] = y;
            v[i][3] = z;

            cout << v[i][1] << " " << v[i][2] << " " << v[i][3] << endl;
            i++;
        }


        fclose(file);

        return v;*/

    return listaFace;
}

/*
//ler tabela de arestas
vector<vector<int> > ManArquivos::lerArestas(){
    ifstream file("data/arestas");
    file.open("data/arestas");

    if(file.is_open()){

        int numArestas;

        file >> numArestas;

        vector<vector<int> > a(numArestas, vector<int>(2));

        int vertInicial, vertFinal;
        int i = 1;

        while(!file.eof()){

            file >> vertInicial >> vertFinal;

            a[i][1] = vertInicial;
            a[i][2] = vertFinal;

            cout << a[i][1] << " " << a[i][2] << endl;
            i++;
        }

        file.close();

        return a;
    }

}

//ler faces
vector<vector<int> > ManArquivos::lerFaces(){
    ifstream file("data/faces");
    file.open("data/faces");

    if(file.is_open()){

        int numFaces;

        file >> numFaces;

        vector<vector<int> > f(numFaces, vector<int>(3));

        int aresta1, aresta2, aresta3;
        int i = 1;

        while(!file.eof()){

            file >> aresta1 >> aresta2 >> aresta3;

            f[i][1] = aresta1;
            f[i][2] = aresta2;
            f[i][3] = aresta3;

            cout << f[i][1] << " " << f[i][2] << " " << f[i][3] << endl;
            i++;
        }

        file.close();

        return f;
    }

}
*/
