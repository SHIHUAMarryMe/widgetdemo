#include <QApplication>
#include <QFile>


#include "mainwindow.h"


class CommonHelper
{
public:
    static void setStyle(const QString &style)noexcept
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
