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
    std::string get_level_string(int);

public slots:
    void update_messageviewer(const Diagnostic &diag);

signals:
    void new_diagnosticmessage(Diagnostic);

private:
    Ui::MainWindow *ui;
    Receiver myReceiver;
};

#endif // MAINWINDOW_H
