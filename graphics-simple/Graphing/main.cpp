#include "mainwindow.h"
#include "downloader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //w.

    //download data


    Downloader cDown;

    cDown.connectTcp();

    return a.exec();

    return a.exec();
}
