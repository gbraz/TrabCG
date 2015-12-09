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

    return a.exec();
}
