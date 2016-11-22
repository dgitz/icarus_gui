#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    std::string default_ROSCORE = "10.0.0.111";
    armdisarm_command = ARMEDCOMMAND_DISARM;
    armdisarm_state = ARMEDSTATUS_DISARMED_CANNOTARM;
    /*chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    */
    //ResourceChart->legend()->hide();
    //ResourceChart->setTitle("Resources Used");
    //ResourceChartView = new QChartView(ResourceChart);
    //ResourceChartView->setRenderHint(QPainter::Antialiasing);
    ui->setupUi(this);
    ui->bArmDisarm->setText("UNDEFINED");
    ui->comboBox->addItem("DEBUG");
    ui->comboBox->addItem("INFO");
    ui->comboBox->addItem("NOTICE");
    ui->comboBox->addItem("WARN");
    ui->comboBox->addItem("ERROR");
    ui->comboBox->addItem("FATAL");
    ui->comboBox->setCurrentIndex(2);

    ui->cArmChooser->addItem("Left Arm");
    ui->cArmChooser->addItem("Right Arm");
   //QMainWindow window;
  // window.setCentralWidget(ResourceChartView);
   //window.resize(400,300);
   //window.show();
    messageviewer_filter = "";
     ui->treeDeviceList->setColumnCount(3);
     ui->treeDeviceList->setHeaderLabels(QStringList() << "Node" << "Status" << "dt");
     ui->tRCServer->setText(QString::fromStdString(default_ROSCORE));
     myTransmitter.set_RC_server(QString::fromStdString(default_ROSCORE));

    myReceiver.Start();
    connect(&myReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_messageviewer(Diagnostic)));
    connect(&myReceiver,SIGNAL(new_armedstatusmessage(int)),this,SLOT(update_armeddisarmed_text(int)));
    connect(ui->bCLOSE,SIGNAL(clicked(bool)),this,SLOT(kill_application(bool)));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(clear_messageviewer(QString)));
    connect(ui->treeDeviceList,SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,SLOT(changefilter_messageviewer()));
    connect(ui->bLaunchSystem,SIGNAL(clicked(bool)),this,SLOT(launch_system(bool)));
    connect(ui->bStopSystem,SIGNAL(clicked(bool)),this,SLOT(stop_system(bool)));
    connect(ui->bClearFilter,SIGNAL(clicked(bool)),this,SLOT(clearfilter_messageviewer()));

    connect(&myReceiver,SIGNAL(new_diagnosticmessage(Diagnostic)),this,SLOT(update_devicelist(Diagnostic)));
    connect(&myReceiver,SIGNAL(new_devicemessage(Device)),this,SLOT(update_devicelist(Device)));
    connect(ui->bSetRCServer,SIGNAL(clicked(bool)),this,SLOT(change_RC_Server(bool)));
    QTimer *timer_10ms = new QTimer(this);
    connect(timer_10ms,SIGNAL(timeout()),this,SLOT(update_devicelist()));
    timer_10ms->start(10);

    QTimer *timer_100ms = new QTimer(this);
    connect(timer_100ms,SIGNAL(timeout()),this,SLOT(update_devicelistviewer()));
    timer_100ms->start(100);

    connect(ui->dial_1,SIGNAL(valueChanged(int)),this,SLOT(send_RC_message(int)));
    connect(ui->dial_1_horz_slider,SIGNAL(valueChanged(int)),this,SLOT(send_RC_message(int)));
    connect(ui->dial_1_vert_slider,SIGNAL(valueChanged(int)),this,SLOT(send_RC_message(int)));
    connect(ui->dial_2,SIGNAL(valueChanged(int)),this,SLOT(send_RC_message(int)));
    connect(ui->dial_2_horz_slider,SIGNAL(valueChanged(int)),this,SLOT(send_RC_message(int)));
    connect(ui->dial_2_vert_slider,SIGNAL(valueChanged(int)),this,SLOT(send_RC_message(int)));
    connect(ui->dial_3,SIGNAL(valueChanged(int)),this,SLOT(send_RC_message(int)));
    connect(ui->dial_4,SIGNAL(valueChanged(int)),this,SLOT(send_RC_message(int)));
    for(int i = 0; i < 4; i++) { buttons.push_back(0); }
    connect(ui->b1,SIGNAL(pressed()),this,SLOT(b1_pressed()));
    connect(ui->b2,SIGNAL(pressed()),this,SLOT(b2_pressed()));
    connect(ui->b3,SIGNAL(pressed()),this,SLOT(b3_pressed()));
    connect(ui->b4,SIGNAL(pressed()),this,SLOT(b4_pressed()));
    connect(ui->bArmDisarm,SIGNAL(pressed()),this,SLOT(bArmDisarm_pressed()));

    connect(ui->armslider1,SIGNAL(valueChanged(int)),this,SLOT(send_ArmControl_message(int)));
    connect(ui->armslider2,SIGNAL(valueChanged(int)),this,SLOT(send_ArmControl_message(int)));
    connect(ui->armslider3,SIGNAL(valueChanged(int)),this,SLOT(send_ArmControl_message(int)));
    connect(ui->armslider4,SIGNAL(valueChanged(int)),this,SLOT(send_ArmControl_message(int)));
    connect(ui->armslider5,SIGNAL(valueChanged(int)),this,SLOT(send_ArmControl_message(int)));
    connect(ui->armslider6,SIGNAL(valueChanged(int)),this,SLOT(send_ArmControl_message(int)));

    connect(ui->bRTH,SIGNAL(pressed()),this,SLOT(bRTH_pressed()));


}
void MainWindow::bRTH_pressed()
{
    ui->armslider1->setValue(0);
    ui->armslider2->setValue(0);
    ui->armslider3->setValue(0);
    ui->armslider4->setValue(0);
    ui->armslider5->setValue(0);
    ui->armslider6->setValue(0);
}
void MainWindow::bArmDisarm_pressed()
{
    if(armdisarm_command == ARMEDCOMMAND_DISARM) { armdisarm_command = ARMEDCOMMAND_ARM; }
    else { armdisarm_command = ARMEDCOMMAND_DISARM; }
    send_Arm_Command_message(armdisarm_command);
}

void MainWindow::b1_pressed()
{
    if(buttons.at(0) == 0) { buttons.at(0) = 1; }
    else { buttons.at(0) = 0; }
     send_RC_message(0);
}
void MainWindow::b2_pressed()
{
    if(buttons.at(1) == 0) { buttons.at(1) = 1; }
    else { buttons.at(1) = 0; }
    send_RC_message(0);
}
void MainWindow::b3_pressed()
{
    if(buttons.at(2) == 0) { buttons.at(2) = 1; }
    else { buttons.at(2) = 0; }
    send_RC_message(0);
}
void MainWindow::b4_pressed()
{
    if(buttons.at(3) == 0) { buttons.at(3) = 1; }
    else { buttons.at(3) = 0; }
    send_RC_message(0);
}

void MainWindow::change_RC_Server(bool set)
{
    myTransmitter.set_RC_server(ui->tRCServer->text());
}
void MainWindow::send_ArmControl_message(int a)
{
    myTransmitter.send_ArmControl_0xAB26(0,
                                         ui->armslider1->value(),
                                         ui->armslider2->value(),
                                         ui->armslider3->value(),
                                         ui->armslider4->value(),
                                         ui->armslider5->value(),
                                         ui->armslider6->value(),
                                         0,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0);
}
void MainWindow::send_RC_message(int a)
{
    myTransmitter.send_RemoteControl_0xAB10(ui->dial_1->value(),
                                            ui->dial_1_horz_slider->value(),
                                            ui->dial_1_vert_slider->value(),
                                            ui->dial_2->value(),
                                            ui->dial_2_horz_slider->value(),
                                            ui->dial_2_vert_slider->value(),
                                            ui->dial_3->value(),
                                            ui->dial_4->value(),
                                            buttons.at(0),buttons.at(1),buttons.at(2),buttons.at(3),0,0,0,0);
}
void MainWindow::send_Arm_Command_message(int a)
{
    myTransmitter.send_ArmCommand_0xab27(armdisarm_command);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::stop_system(bool value)
{
    std::string tempstr = "ssh robot@" + ui->tRCServer->text().toStdString() + " 'cd /home/robot/; ./scripts/stopSystem -a; exit'";
    qDebug() << QString::fromStdString(tempstr);
    system(tempstr.c_str());
}
void MainWindow::launch_system(bool value)
{
   //std::string tempstr = "ssh robot@" + ui->tRCServer->text().toStdString() + " 'cd /home/robot/; ./scripts/launchSystem; exit'";
    std::string tempstr = "ssh robot@" + ui->tRCServer->text().toStdString() + " 'cd /home/robot/; touch abcd; exit'";
   qDebug() << QString::fromStdString(tempstr);
   system(tempstr.c_str());
}

void MainWindow::kill_application(bool value)
{
    qApp->exit();
}
void MainWindow::changefilter_messageviewer()
{
    QString item = ui->treeDeviceList->currentItem()->text(0);
    messageviewer_filter = item;
    ui->textBrowser->clear();
    qDebug() << "changing filter to: " << item;

   // qDebug() << " new: " << newitem.text(0);
}

void MainWindow::clear_messageviewer(QString value)
{
    ui->textBrowser->clear();
}
void MainWindow::clearfilter_messageviewer()
{
    messageviewer_filter = "";
    ui->textBrowser->clear();
}
void MainWindow::update_armeddisarmed_text(int value)
{
    QString tempstr;
     switch (value)
     {
        case ARMEDSTATUS_ARMED: tempstr = "ARMED"; break;
         case ARMEDSTATUS_ARMING: tempstr = "ARMING"; break;
         case ARMEDSTATUS_DISARMED: tempstr = "DISARMING"; break;
         case ARMEDSTATUS_DISARMED_CANNOTARM: tempstr = "DISARMING\nCANNOT ARM"; break;
         case ARMEDSTATUS_DISARMING: tempstr = "DISARMING"; break;
         case ARMEDSTATUS_UNDEFINED: tempstr = "UNDEFINED";
     }
     ui->bArmDisarm->setText(tempstr);
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
                            else if((DeviceList.at(i).Nodes.at(j).time_delta_ms > 1000) && (DeviceList.at(i).Nodes.at(j).time_delta_ms <= 6000))
                            {
                                (*child_it)->setBackground(0,brush_orange);
                            }
                            else if(DeviceList.at(i).Nodes.at(j).time_delta_ms > 6000)
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
                else if((device_time_delta > 1000) && (device_time_delta <= 6000))
                {
                    (*it)->setBackground(0,brush_orange);
                }
                else if(device_time_delta > 6000)
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
    if(messageviewer_filter == "")
    {

        if(diag.Level >= ui->comboBox->currentIndex())
        {
            std::string tempstr = dateTime.toString().toStdString() + " Node:" + diag.NodeName + " Level: " + get_level_string(diag.Level) + " " + diag.Description;
            ui->textBrowser->append(QString::fromStdString(tempstr));
        }
    }
    else
    {
        if(diag.Level >= ui->comboBox->currentIndex())
        {
            std::size_t found = diag.NodeName.find(messageviewer_filter.toStdString());
            if(found != std::string::npos)
            {
                std::string tempstr = dateTime.toString().toStdString() + " Node:" + diag.NodeName + " Level: " + get_level_string(diag.Level) + " " + diag.Description;
                ui->textBrowser->append(QString::fromStdString(tempstr));
            }
        }
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
