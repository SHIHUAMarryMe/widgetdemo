

#include "./mainwindow/mainwindow.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    CommonHelper::setStyle(":/style/style1.qss");


    MainWindow m{800, 600};
    m.show();




    return a.exec();
}
