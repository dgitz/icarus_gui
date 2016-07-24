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
    ui->comboBox->addItem("DEBUG");
    ui->comboBox->addItem("INFO");
    ui->comboBox->addItem("NOTICE");
    ui->comboBox->addItem("WARN");
    ui->comboBox->addItem("ERROR");
    ui->comboBox->addItem("FATAL");
    ui->comboBox->setCurrentIndex(1);
    myReceiver.Start();
    connect(&myReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_messageviewer(Diagnostic)));
    connect(ui->bCLOSE,SIGNAL(clicked(bool)),this,SLOT(kill_application(bool)));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(refresh_messageviewer(QString)));
    //connect(&myReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_treeviewer(Diagnostic)));
    //connect(&myReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_nodelist(Diagnostic)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::kill_application(bool value)
{
    qApp->exit();
}
void MainWindow::refresh_messageviewer(QString value)
{
    ui->textBrowser->clear();
}

void MainWindow::update_messageviewer(const Diagnostic &diag)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    if(diag.Level >= ui->comboBox->currentIndex())
    {
        std::string tempstr = dateTime.toString().toStdString() + " Node:" + diag.NodeName + " Level: " + get_level_string(diag.Level) + " " + diag.Description;
        ui->textBrowser->append(QString::fromStdString(tempstr));
    }
}
/*
void MainWindow::update_treeviewer(const Diagnostic &diag)
{
    for( int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i )
    {
        QTreeWidgetItem *item = ui->treeWidget->topLevelItem( i );
    }
}
void MainWindow::update_nodelist(const Diagnostic &diag)
{
    bool add_new_node = true;
    for(int i = 0; i < NodeList.size();i++)
    {
        Node newnode = NodeList.at(i);

        if(newnode.NodeName == diag.NodeName) { add_new_node = false; break; }
    }
    if(add_new_node == true)
    {
        Node newNode;
        newNode.NodeName = diag.NodeName;
        NodeList.push_back(newNode);
    }
}
*/


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
