#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QDial>
#include "ui_mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    QList<QAbstractSlider *> sliders = w.findChildren<QAbstractSlider *>();
    foreach (QAbstractSlider *slider,sliders)
    {
        slider->setAttribute(Qt::WA_AcceptTouchEvents);
    }

    w.showMaximized();

    return a.exec();
}
