#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(addentry(Diagnostic)));
    //connect(this,SIGNAL(newentry(Diagnostic)),this,SLOT(addentry(Diag nostic)));
    //connect(Receiver,SIGNAL())
    myReceiver.Start();
    connect(&myReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_messageviewer(Diagnostic)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update_messageviewer(const Diagnostic &diag)
{

   // QString nodename = QString::fromStdString(diag.NodeName);
    std::string tempstr = "Node:" + diag.NodeName + " Level: " + get_level_string(diag.Level);
    ui->textBrowser->append(QString::fromStdString(tempstr));
}
std::string MainWindow::get_level_string(int value)
{
    switch (value)
    {
        case DEBUG: return "DEBUG"; break;
        case INFO: return "INFO"; break;
        case NOTICE: return "NOTICE"; break;
        case WARN: return "WARN"; break;
        case ERROR: return "ERROR"; break;
        case FATAL: return "FATAL"; break;
        default: return ""; break;
    }
}
