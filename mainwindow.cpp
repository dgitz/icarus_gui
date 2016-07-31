#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("DEBUG");
    ui->comboBox->addItem("INFO");
    ui->comboBox->addItem("NOTICE");
    ui->comboBox->addItem("WARN");
    ui->comboBox->addItem("ERROR");
    ui->comboBox->addItem("FATAL");
    ui->comboBox->setCurrentIndex(2);

     ui->treeDeviceList->setColumnCount(3);
     ui->treeDeviceList->setHeaderLabels(QStringList() << "Node" << "Status" << "dt");

    myReceiver.Start();
    connect(&myReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_messageviewer(Diagnostic)));
    connect(ui->bCLOSE,SIGNAL(clicked(bool)),this,SLOT(kill_application(bool)));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(refresh_messageviewer(QString)));
    connect(ui->bLaunchSystem,SIGNAL(clicked(bool)),this,SLOT(launch_system(bool)));
    connect(ui->bStopSystem,SIGNAL(clicked(bool)),this,SLOT(stop_system(bool)));

    connect(&myReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_devicelist(Diagnostic)));
    connect(&myReceiver,SIGNAL(new_devicemessage(Device)),this,SLOT(update_devicelist(Device)));
    QTimer *timer_10ms = new QTimer(this);
    connect(timer_10ms,SIGNAL(timeout()),this,SLOT(update_devicelist()));
    timer_10ms->start(10);

    QTimer *timer_100ms = new QTimer(this);
    connect(timer_100ms,SIGNAL(timeout()),this,SLOT(update_devicelistviewer()));
    timer_100ms->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::stop_system(bool value)
{
   // QProcess::execute("ssh robot@dgitzrosmaster & ./scripts/stopSystem & exit");
   // system("ssh robot@dgitzrosmaster & ./scripts/stopSystem & exit");
}
void MainWindow::launch_system(bool value)
{
   // QProcess::execute("ssh robot@dgitzrosmaster & ./scripts/stopSystem & exit");
}

void MainWindow::kill_application(bool value)
{
    qApp->exit();
}
void MainWindow::refresh_messageviewer(QString value)
{
    ui->textBrowser->clear();
}
void MainWindow::update_devicelist()
{
    for(int i = 0; i < DeviceList.size();i++)
    {
        for(int j = 0; j < DeviceList.at(i).Nodes.size();j++)
        {
            DeviceList.at(i).Nodes.at(j).time_delta_ms += 10;
        }
    }
}

void MainWindow::update_devicelist(const Device &device)
{
    bool add_new_device = true;
    for(int i = 0; i < DeviceList.size();i++)
    {
        Device dev = DeviceList.at(i);
        if(dev.DeviceName == device.DeviceName)
        {
            add_new_device = false;
            break;
        }

    }
    if(add_new_device == true)
    {
        DeviceList.push_back(device);
    }
}

void MainWindow::update_devicelist(const Diagnostic &diag)
{
    for(int i = 0; i < DeviceList.size();i++)
    {
        Device dev = DeviceList.at(i);
        std::size_t found = diag.NodeName.find(dev.DeviceName);

        if(found != std::string::npos)
        {
            bool add_new_node = true;
            for(int j = 0; j < dev.Nodes.size();j++)
            {
                if(dev.Nodes.at(j).NodeName == diag.NodeName)
                {
                    DeviceList.at(i).Nodes.at(j).time_delta_ms = 0;
                    DeviceList.at(i).Nodes.at(j).Level = diag.Level;
                    add_new_node = false;
                    break;
                }
            }
            if(add_new_node == true)
            {
                Node newnode;
                newnode.NodeName = diag.NodeName;
                newnode.time_delta_ms = 0;
                DeviceList.at(i).Nodes.push_back(newnode);
            }
        }
    }
}
void MainWindow::update_devicelistviewer()
{

    QBrush brush_red(Qt::red);
    QBrush brush_green(Qt::green);
    QBrush brush_gray(Qt::gray);
    QBrush brush_orange(QColor(255,128,0));
    for(int i = 0; i < DeviceList.size();i++)
    {

        bool add_new_entry = true;
        QTreeWidgetItemIterator it(ui->treeDeviceList);
        while (*it)
        {
            if ((*it)->text(0)==QString::fromStdString(DeviceList.at(i).DeviceName))
            {
                int device_level = DEBUG;
                qint64 device_time_delta = -1;
                add_new_entry = false;
                for(int j = 0; j < DeviceList.at(i).Nodes.size();j++)
                {
                    if(DeviceList.at(i).Nodes.at(j).Level > device_level)
                    {
                        device_level = DeviceList.at(i).Nodes.at(j).Level;
                    }
                    if(DeviceList.at(i).Nodes.at(j).time_delta_ms > device_time_delta)
                    {
                        device_time_delta = DeviceList.at(i).Nodes.at(j).time_delta_ms;
                    }
                    bool add_new_child = true;
                    QTreeWidgetItemIterator child_it(it);
                    while(*child_it)
                    {
                        if ((*child_it)->text(0)==QString::fromStdString(DeviceList.at(i).Nodes.at(j).NodeName))
                        {
                            QString level_string = "";
                            if(DeviceList.at(i).Nodes.at(j).Level <= INFO)
                            {
                                level_string = "OK";
                            }
                            else
                            {
                                level_string = QString::fromStdString(get_level_string(DeviceList.at(i).Nodes.at(j).Level));
                            }

                            if((DeviceList.at(i).Nodes.at(j).time_delta_ms < 500) && (DeviceList.at(i).Nodes.at(j).Level <= INFO))
                            {
                                (*child_it)->setBackground(0,brush_green);
                            }
                            else if((DeviceList.at(i).Nodes.at(j).time_delta_ms > 1000) && (DeviceList.at(i).Nodes.at(j).time_delta_ms <= 2000))
                            {
                                (*child_it)->setBackground(0,brush_orange);
                            }
                            else if(DeviceList.at(i).Nodes.at(j).time_delta_ms > 2000)
                            {
                                (*child_it)->setBackground(0,brush_gray);
                                level_string = "NO COMM";
                            }
                            else if(DeviceList.at(i).Nodes.at(j).Level >= ERROR)
                            {
                                (*child_it)->setBackground(0,brush_red);
                            }
                            (*child_it)->setText(1,level_string);
                            (*child_it)->setText(2,QString::number(DeviceList.at(i).Nodes.at(j).time_delta_ms));
                            add_new_child = false;
                            break;
                        }
                        ++child_it;
                    }
                    if(add_new_child == true)
                    {
                        QTreeWidgetItem *childItem = new QTreeWidgetItem();
                        childItem->setText(0,QString::fromStdString(DeviceList.at(i).Nodes.at(j).NodeName));
                        (*it)->addChild(childItem);
                    }
                }
                QString device_level_string = "";
                if(device_level <= INFO)
                {
                    device_level_string = "OK";
                }
                else
                {
                    device_level_string = QString::fromStdString(get_level_string(device_level));
                }


                if((device_time_delta < 500) && (device_level <= INFO))
                {
                    (*it)->setBackground(0,brush_green);
                }
                else if((device_time_delta > 1000) && (device_time_delta <= 2000))
                {
                    (*it)->setBackground(0,brush_orange);
                }
                else if(device_time_delta > 2000)
                {
                    (*it)->setBackground(0,brush_gray);
                    device_level_string = "NO COMM";
                }
                else if(device_level >= ERROR)
                {
                    (*it)->setBackground(0,brush_red);
                }
                (*it)->setText(1,device_level_string);
                (*it)->setText(2,QString::number(device_time_delta));
                break;
            }

            ++it;
        }
        if(add_new_entry == true)
        {
            QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeDeviceList);
            treeItem->setText(0,QString::fromStdString(DeviceList.at(i).DeviceName));
        }

    }

    for(int i = 0; i < ui->treeDeviceList->columnCount();i++)
    {
        ui->treeDeviceList->resizeColumnToContents(i);
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
