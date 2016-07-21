#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <receiver.h>
#include "/home/robot/catkin_ws/devel/include/icarus_rover_v2/Definitions.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
