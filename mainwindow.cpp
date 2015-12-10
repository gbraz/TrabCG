#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calc.h"
#include <QtGui>
#include "QGraphicsPixmapItem"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Objeto obj;
    Luz luz(0, 5, 0);
    Calc calc;
    vector< vector< vector<float> > > imagem;

    /* Teste */
    QImage image(300, 300, QImage::Format_RGB32);
    QRgb value;

    //Preenche imagem com branco
    value = qRgb(255, 255, 255);
    image.fill(value);

    imagem = calc.gerarImagem(150, 150, 10, 10, 1, obj.getFaces(), luz);

    for(int i = 0; i < imagem.size(); i++)
        for(int j = 0; j < imagem[0].size(); j++){

            value = qRgb(imagem[i][j][0]*254, imagem[i][j][1]*254, imagem[i][j][2]*254);
            image.setPixel(i, j, value);
        }

    QPixmap item(QPixmap::fromImage(image));
    QGraphicsScene* scene = new QGraphicsScene();
    scene->addPixmap(item);

    ui->graphicsView11->setScene(scene);

    /*Teste */


}

QImage MainWindow::processarImagem(){

    Calc calc;
    Luz luz(0, 4, -4);
    Vertice lAt(-1, 0, 0), pos(0, 0, 0);
    Camera cam(pos, lAt);

    Vertice vert1(0, 0, -3), vert2(1, 2, -4), vert3(-1, 2, -4);
    Face face(vert1, vert2, vert3);


//    calc.getPixel(, face, luz)


    /*vector< vector<float> > m;
    vector<float> v2;
    v2.push_back(1);
    v2.push_back(2);

    m.push_back(v2);
    m.push_back(v2);

    vector<float> v1;
    v1.push_back(1);
    v1.push_back(0);

    v1 = calc.produtoMatrizVetor(m, v1);

    calc.coordMundoParaCam(cam, vert1);
    vert1.setPos(calc.coordMundoParaCam(cam, vert1));
    vert1.setPos(calc.coordCamParaMundo(cam, vert1));*/

}

MainWindow::~MainWindow()
{
    delete ui;
}


