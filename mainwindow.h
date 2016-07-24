#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
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
    void kill_application(const bool);
    void refresh_messageviewer(const QString);
    void update_deviceviewer(const Device &device);
    void update_nodeviewer(const Diagnostic &diag);
   // void update_treeviewer(const Diagnostic &diag);
   // void update_nodelist(const Diagnostic &diag);

signals:
    void new_diagnosticmessage(Diagnostic);
    void new_devicemessage(Device);

private:
    Ui::MainWindow *ui;
    Receiver myReceiver;
    std::vector<Node> NodeList;
};

#endif // MAINWINDOW_H
