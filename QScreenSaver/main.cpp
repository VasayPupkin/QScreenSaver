//#include "mainwindow.h"
#include "Mediator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    Mediator m;
    m.Start();

    return a.exec();
}
