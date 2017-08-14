#include <QApplication>

#include "./mainwindow/mainwindow.h"
#include "./titlebar/titlebar.h"





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    CommonHelper::setStyle(":/styles/style.qss");


//    MainWindow m{800, 600};
//    m.show();

    TitleBar bar{600, 50};
    bar.show();


    return a.exec();
}
