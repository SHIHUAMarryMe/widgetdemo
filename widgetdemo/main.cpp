#include <QObject>
#include <QString>



#include "./mainwindow/mainwindow.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CommonHelper::setStyle(":/style/style1.qss");


    MainWindow m{800, 600};
    m.setTitle(QString{"QFrame"});
    m.setLogo(QString{":/img/appbar.smiley.tounge.png"});
//    m.setNavigationIcons(QList<QString>{
//                             QString{":/img/appbar.home.png"},
//                             QString{":/img/appbar.message.smiley.png"},
//                             QString{":/img/appbar.tree.leaf.three.png"},
//                             QString{":/img/appbar.graph.line.png"}
//                         });
    m.show();


    return a.exec();
}
