#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDateTime>
#include <QTimer>
#include <QProcess>
#include <QTreeWidget>
#include <QtCharts>
#include <QLineSeries>
#include <receiver.h>
#include <transmitter.h>
#include <QTouchEvent>



using namespace QtCharts;
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
    void clear_messageviewer(const QString);
    void changefilter_messageviewer();
    void clearfilter_messageviewer();
    void update_devicelist(const Diagnostic &diag);
    void update_devicelist(const Device &device);
    void update_devicelist();
    void update_devicelistviewer();
    void change_RC_Server(bool set);

    void send_RC_message(int);
    void send_ArmControl_message(int);
    void b1_pressed();
    void b2_pressed();
    void b3_pressed();
    void b4_pressed();

    void bRTH_pressed();

signals:
    void new_diagnosticmessage(Diagnostic);
    void new_devicemessage(Device);

private:
    Ui::MainWindow *ui;
    Receiver myReceiver;
    Transmitter myTransmitter;
   // QChart *ResourceChart;
    //QChartView *ResourceChartView;

    std::vector<Device> DeviceList;
    std::vector<int> buttons;
    QString messageviewer_filter;
};

#endif // MAINWINDOW_H
