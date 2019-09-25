#include "mainwindow.h"
#include "makewindows.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    if(w.CheckStatus()==100)
        w.show();
    else
        return 0;


    return a.exec();
}
