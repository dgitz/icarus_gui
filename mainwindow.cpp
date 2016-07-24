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
     ui->tableAvailableDevices->setRowCount(1);
    ui->tableAvailableDevices->setColumnCount(3);
    QStringList table_device_header;
    table_device_header<<"#"<<"Device" <<"Status";
    ui->tableAvailableDevices->setHorizontalHeaderLabels(table_device_header);
    ui->tableAvailableDevices->verticalHeader()->setVisible(false);
    ui->tableAvailableDevices->setItem(0,0,new QTableWidgetItem(""));
    ui->tableAvailableDevices->setItem(0,1,new QTableWidgetItem(""));
    ui->tableAvailableDevices->setItem(0,2,new QTableWidgetItem(""));
     ui->tableAvailableDevices->horizontalHeader()->setStretchLastSection(true);
     ui->tableAvailableDevices->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

     ui->tableAvailableNodes->setRowCount(1);
    ui->tableAvailableNodes->setColumnCount(3);
    QStringList table_node_header;
    table_node_header<<"#"<<"Node" <<"Status";
    ui->tableAvailableNodes->setHorizontalHeaderLabels(table_node_header);
    ui->tableAvailableNodes->verticalHeader()->setVisible(false);
    ui->tableAvailableNodes->setItem(0,0,new QTableWidgetItem(""));
    ui->tableAvailableNodes->setItem(0,1,new QTableWidgetItem(""));
    ui->tableAvailableNodes->setItem(0,2,new QTableWidgetItem(""));
     ui->tableAvailableNodes->horizontalHeader()->setStretchLastSection(true);
     ui->tableAvailableNodes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    myReceiver.Start();
    connect(&myReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_messageviewer(Diagnostic)));
    connect(ui->bCLOSE,SIGNAL(clicked(bool)),this,SLOT(kill_application(bool)));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(refresh_messageviewer(QString)));
    connect(&myReceiver,SIGNAL(new_devicemessage(Device)),this,SLOT(update_deviceviewer(Device)));
   connect(&myReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_nodeviewer(Diagnostic)));
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
void MainWindow::update_nodeviewer(const Diagnostic &diag)
{
    bool add_new_entry = true;
    for(int i = 0; i < ui->tableAvailableNodes->rowCount();i++)
    {
        QTableWidgetItem *item = ui->tableAvailableNodes->item(i,1);
         if(item->text() == "")
         {
            ui->tableAvailableNodes->setItem(i,0,new QTableWidgetItem("1"));
            ui->tableAvailableNodes->setItem(i,1,new QTableWidgetItem(QString::fromStdString(diag.NodeName)));
            if(diag.Level > INFO)
            {
                ui->tableAvailableNodes->setItem(i,2,new QTableWidgetItem(QString::fromStdString(get_level_string(diag.Level))));
            }
            else
            {
                ui->tableAvailableNodes->setItem(i,2,new QTableWidgetItem("OK"));
            }
            add_new_entry = false;
         }
         else if(item->text() == QString::fromStdString(diag.NodeName))
         {
             if(diag.Level > INFO)
             {
                 ui->tableAvailableNodes->setItem(i,2,new QTableWidgetItem(QString::fromStdString(get_level_string(diag.Level))));
             }
             else
             {
                 ui->tableAvailableNodes->setItem(i,2,new QTableWidgetItem("OK"));
             }
             add_new_entry = false;
         }
    }
    if(add_new_entry == true)
    {

         int newindex = ui->tableAvailableNodes->rowCount();
         ui->tableAvailableNodes->insertRow(newindex);
         ui->tableAvailableNodes->setItem(newindex,0,new QTableWidgetItem(QString::number(newindex+1)));
         ui->tableAvailableNodes->setItem(newindex,1,new QTableWidgetItem(QString::fromStdString(diag.NodeName)));
         if(diag.Level > INFO)
         {
             ui->tableAvailableNodes->setItem(newindex,2,new QTableWidgetItem(QString::fromStdString(get_level_string(diag.Level))));
         }
         else
         {
             ui->tableAvailableNodes->setItem(newindex,2,new QTableWidgetItem("OK"));
         }
         ui->tableAvailableNodes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    }
}

void MainWindow::update_deviceviewer(const Device &dev)
{
   bool add_new_entry = true;
   for(int i = 0; i < ui->tableAvailableDevices->rowCount();i++)
   {
       QTableWidgetItem *item = ui->tableAvailableDevices->item(i,1);
        if(item->text() == "")
        {
           ui->tableAvailableDevices->setItem(i,0,new QTableWidgetItem("1"));
           ui->tableAvailableDevices->setItem(i,1,new QTableWidgetItem(QString::fromStdString(dev.DeviceName)));
           ui->tableAvailableDevices->setItem(i,2,new QTableWidgetItem("N/A"));
           add_new_entry = false;
        }
        else if(item->text() == QString::fromStdString(dev.DeviceName))
        {
            add_new_entry = false;
        }
   }
   if(add_new_entry == true)
   {
        int newindex = ui->tableAvailableDevices->rowCount();
        ui->tableAvailableDevices->insertRow(newindex);
        ui->tableAvailableDevices->setItem(newindex,0,new QTableWidgetItem(QString::number(newindex+1)));
        ui->tableAvailableDevices->setItem(newindex,1,new QTableWidgetItem(QString::fromStdString(dev.DeviceName)));
        ui->tableAvailableDevices->setItem(newindex,2,new QTableWidgetItem("N/A"));
        ui->tableAvailableDevices->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   }
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
