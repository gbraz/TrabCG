#include "calc.h"


Calc::Calc()
{

}

vector<float> Calc::subtracaoVetores(vector<float> u, vector<float> v){
    for(int i = 0; i < 4; i++)
        u[i] = u[i] - v[i];

    return u;
}

vector<float> Calc::verticesParaVetor(Vertice a, Vertice b){
    vector<float> u;

    u.push_back(a.getX() - b.getX());
    u.push_back(a.getY() - b.getY());
    u.push_back(a.getZ() - b.getZ());
    u.push_back(0);

    return u;
}

vector<float> Calc::produtoVetorial(vector<float> u, vector<float> v){
    vector<float> w;

    w.push_back(u[1]*v[2] - u[2]*v[1]);
    w.push_back(u[2]*v[0] - u[0]*v[2]);
    w.push_back(u[0]*v[1] - u[1]*v[0]);
    w.push_back(0);

    return w;
}

void Calc::transVetUnitario(vector<float>& u){
    float modulo;
    float x = u[0];
    float y = u[1];
    float z = u[2];

    modulo = sqrt(x*x + y*y + z*z);

    u[0] = x/modulo;
    u[1] = y/modulo;
    u[2] = z/modulo;


}

vector<float> Calc::coordMundoParaCam(Camera camera, Vertice vertice){
    vector < vector<float> > mat;

    mat.resize(4);
    for(int i = 0; i < 4; i++)
        mat[i].resize(4);

    for(int i = 0; i < 4; i++){
        switch(i){
        case(0):
            mat[i][0] = camera.getI()[0];
            mat[i][1] = camera.getI()[1];
            mat[i][2] = camera.getI()[2];
            mat[i][3] = (-1)*produtoEscalar(camera.getI(), camera.getPos());
            break;
        case(1):
            mat[i][0] = camera.getJ()[0];
            mat[i][1] = camera.getJ()[1];
            mat[i][2] = camera.getJ()[2];
            mat[i][3] = (-1)*produtoEscalar(camera.getJ(), camera.getPos());
            break;
        case(2):
            mat[i][0] = camera.getK()[0];
            mat[i][1] = camera.getK()[1];
            mat[i][2] = camera.getK()[2];
            mat[i][3] = (-1)*produtoEscalar(camera.getK(), camera.getPos());
            break;
        default:
            mat[i][0] = 0;
            mat[i][1] = 0;
            mat[i][2] = 0;
            mat[i][3] = 1;
            break;
        }
    }

    return produtoMatrizVetor(mat, vertice.getPos());
}

vector<float> Calc::coordCamParaMundo(Camera camera, Vertice vertice){
    vector < vector<float> > mat;

    mat.resize(4);
    for(int i = 0; i < 4; i++)
        mat[i].resize(4);

    for(int i = 0; i < 4; i++){
        mat[i][0] = camera.getI()[i];
        mat[i][1] = camera.getJ()[i];
        mat[i][2] = camera.getK()[i];

        if(i == 0)
            mat[i][3] = camera.getX();
        else if(i == 1)
            mat[i][3] = camera.getY();
        else if(i ==2)
            mat[i][3] = camera.getZ();
        else
            mat[i][0] = 1;
     }

    return produtoMatrizVetor(mat, vertice.getPos());
}

float Calc::produtoEscalar(vector<float> u, vector<float> v) {
    float soma = 0;

    for(int i = 0; i < u.size(); i++)
        soma = u[i]*v[i] + soma;

    return soma;
}

vector<float> Calc::produtoMatrizVetor(vector<vector<float> > matriz, vector<float> vetor){
    vector<float> resultado(4, 0);

    for(int i = 0; i < matriz.size(); i++)
        for(int j = 0; j < vetor.size(); j++)
            resultado[i] = matriz[i][j]*vetor[j] + resultado[i];

    return resultado;
}

vector<float> Calc::pontoIntersecao(vector<float> raioProjecao, Face face){
    float t;
    vector<float> normal = face.getNormal();

    t = produtoEscalar(normal, face.getVertice1().getPos());
    t = t/produtoEscalar(normal, raioProjecao);

    for(int i = 0; i < 4; i++)
        raioProjecao[i] = raioProjecao[i]*t;

    return raioProjecao;
}

bool Calc::interceptaFace(vector<float> pontoInter, Face face){
    vector<float> aresta1, aresta2, aresta3;
    vector<float> normal1, normal2, normal3;

    aresta1 =  face.getVertice1().getPos();
    aresta2 =  face.getVertice2().getPos();
    aresta3 =  face.getVertice3().getPos();

    normal1 = produtoVetorial(aresta2, aresta1);
    normal2 = produtoVetorial(aresta3, aresta2);
    normal3 = produtoVetorial(aresta1, aresta3);

    if((produtoEscalar(pontoInter, normal1) < 0) ||
            (produtoEscalar(pontoInter, normal2) < 0) ||
            (produtoEscalar(pontoInter, normal3) < 0))
        return false;

    return true;
}

vector<float> Calc::getPixel(vector<float> raioIntersecao, vector<Face> listaFace, Luz luz){

    vector<float> pixel(3, 0);
    vector<float> l(3, 0);

    for(int i = 0; i < listaFace.size(); i++){
        if(interceptaFace(pontoIntersecao(raioIntersecao, listaFace[i]), listaFace[i])){
            pixel = l;
            return pixel;
        }
        else
            pixel = luz.getRGB();
    }

    return pixel;
}

//TODO: Fazer funçao que pega todas as faces
vector< vector< vector<float> > > Calc::gerarImagem(int xPixels, int yPixels, float width, float height, float dist, vector<Face> listaFace, Luz luz){
    vector< vector< vector<float> > > vport;
    vector<float> pixel;

    vport.resize(xPixels);
    for(int i = 0; i < xPixels; i++)
        vport[i].resize(yPixels);

    //QImage image(xPixels, yPixels, QImage::Format_RGB32);

    //Preenche imagem com branco
    //value = qRgb(255, 255, 255);
    //image.fill(value);

    float alt, lar;
    vector<float> vetorPixel;

    for(int i = 0; i < xPixels; i++){
        for(int j = 0; j < yPixels; j++){

            lar = width/(2*xPixels) + i*width/(2*xPixels);
            alt = height/(2*yPixels) + j*height/(2*yPixels);

            vetorPixel.push_back(lar);
            vetorPixel.push_back(alt);
            vetorPixel.push_back(dist);
            vetorPixel.push_back(0);

            transVetUnitario(vetorPixel);

            pixel = getPixel(vetorPixel, listaFace, luz);
            vport[xPixels][yPixels] = pixel;

            //value = qRgb(pixel[0]*254, pixel[0]*254, pixel[0]*254);

            //image.setPixel(i, j, value);
        }
    }

    return vport;
}

//Matr
