#include <QApplication>
#include <QFile>


#include "mainwindow.h"



struct CommonHelper
{
    static void setStyle(const QString &style)
    {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CommonHelper::setStyle(":/styles/style.qss");


    MainWindow m{800, 600};
    m.show();


    return a.exec();
}
