#include <iostream>
#include <iomanip>


#include "mainwindow.h"
#include "calculator.h"





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CommonHelper::setStyle(":/styles/style.qss");


    MainWindow m{800, 600};
    m.show();


    return a.exec();
}
