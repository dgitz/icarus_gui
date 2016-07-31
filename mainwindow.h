#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDateTime>
#include <QTimer>
#include <QProcess>
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
    void stop_system(const bool);
    void launch_system(const bool);
    void refresh_messageviewer(const QString);
    void update_devicelist(const Diagnostic &diag);
    void update_devicelist(const Device &device);
    void update_devicelist();
    void update_devicelistviewer();

signals:
    void new_diagnosticmessage(Diagnostic);
    void new_devicemessage(Device);

private:
    Ui::MainWindow *ui;
    Receiver myReceiver;


    std::vector<Device> DeviceList;

};

#endif // MAINWINDOW_H
