#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(300,200);
    w.setWindowTitle("PlatIoT - Sensor Module");
    w.show();

    return a.exec();
}
