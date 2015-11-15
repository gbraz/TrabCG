#include "mainwindow.h"
#include "camera.h"
#include "calc.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Vertice lAt(-1, 0, 0), pos(0, 0, 0), vert1(2, 2, 2);
    Calc calc;


    Camera cam(pos, lAt);

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

    calc.coordMundoParaCam(cam, vert1);*/
    vert1.setPos(calc.coordMundoParaCam(cam, vert1));
    vert1.setPos(calc.coordCamParaMundo(cam, vert1));

    return a.exec();
}
