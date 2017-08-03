#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow m{800, 600};
    m.show();


    return a.exec();
}
