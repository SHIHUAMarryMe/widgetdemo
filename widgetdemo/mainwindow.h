#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <new>
#include <memory>


#include <QWidget>

class QListView;
class QRectF;


class MainWindow : public QWidget
{
    Q_OBJECT

    MainWindow(QWidget* parent = nullptr);
    MainWindow(const MainWindow&)=delete;
    MainWindow(MainWindow&&)=delete;

    MainWindow& operator=(const MainWindow&)=delete;
    MainWindow& operator=(MainWindow&&)=delete;


private:
    QListView* m_LeftListView{nullptr};
    QListView* m_TopListView{nullptr};

    std::unique_ptr<QRectF> m_TopRect;
    std::unique_ptr<QRectF> m_LeftRect;
};

#endif // MAINWINDOW_H
