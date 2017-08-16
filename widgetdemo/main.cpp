#include <QObject>
#include <QString>



#include "./mainwindow/mainwindow.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    CommonHelper::setStyle(":/style/style1.qss");


    MainWindow m{0, 0};
    m.setMinimumSize(1000, 800);
    m.setTitle(QString{"QFrame"});
    m.setLogo(QString{":/img/appbar.smiley.tounge.png"});
    m.show();


    return a.exec();
}
