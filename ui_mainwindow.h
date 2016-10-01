/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabDiagnostics;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QTextBrowser *textBrowser;
    QTreeWidget *treeDeviceList;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *bClearFilter;
    QWidget *tabResources;
    QWidget *tab;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLCDNumber *lcdNumber_2;
    QLabel *label_4;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout_6;
    QDial *dial_1;
    QSlider *dial_1_vert_slider;
    QHBoxLayout *horizontalLayout_8;
    QSlider *dial_2_vert_slider;
    QDial *dial_2;
    QGridLayout *gridLayout_4;
    QPushButton *b2;
    QDial *dial_4;
    QPushButton *b1;
    QPushButton *b4;
    QGridLayout *gridLayout_10;
    QPushButton *b3;
    QDial *dial_3;
    QSlider *dial_2_horz_slider;
    QSlider *dial_1_horz_slider;
    QPushButton *bSetRCServer;
    QLineEdit *tRCServer;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *bLaunchSystem;
    QPushButton *bStopSystem;
    QPushButton *bCLOSE;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(941, 480);
        MainWindow->setMaximumSize(QSize(975, 480));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 911, 431));
        QFont font;
        font.setPointSize(14);
        tabWidget->setFont(font);
        tabDiagnostics = new QWidget();
        tabDiagnostics->setObjectName(QStringLiteral("tabDiagnostics"));
        layoutWidget = new QWidget(tabDiagnostics);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 493, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(330, 0));
        comboBox->setMaximumSize(QSize(330, 50));
        QFont font1;
        font1.setPointSize(24);
        comboBox->setFont(font1);

        verticalLayout->addWidget(comboBox);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMinimumSize(QSize(491, 280));
        textBrowser->setMaximumSize(QSize(491, 280));

        verticalLayout->addWidget(textBrowser);

        treeDeviceList = new QTreeWidget(tabDiagnostics);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeDeviceList->setHeaderItem(__qtreewidgetitem);
        treeDeviceList->setObjectName(QStringLiteral("treeDeviceList"));
        treeDeviceList->setGeometry(QRect(499, 29, 451, 340));
        treeDeviceList->setMinimumSize(QSize(451, 340));
        treeDeviceList->setMaximumSize(QSize(451, 340));
        layoutWidget1 = new QWidget(tabDiagnostics);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(500, 0, 449, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(200, 16));
        label_2->setMaximumSize(QSize(200, 16));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        bClearFilter = new QPushButton(layoutWidget1);
        bClearFilter->setObjectName(QStringLiteral("bClearFilter"));

        horizontalLayout_2->addWidget(bClearFilter);

        tabWidget->addTab(tabDiagnostics, QString());
        tabResources = new QWidget();
        tabResources->setObjectName(QStringLiteral("tabResources"));
        tabWidget->addTab(tabResources, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        lcdNumber_2 = new QLCDNumber(tab);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        horizontalLayout_3->addWidget(lcdNumber_2);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        lcdNumber = new QLCDNumber(tab);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout_3->addWidget(lcdNumber);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        dial_1 = new QDial(tab);
        dial_1->setObjectName(QStringLiteral("dial_1"));
        dial_1->setMinimum(-32768);
        dial_1->setMaximum(32767);
        dial_1->setSingleStep(10);
        dial_1->setNotchTarget(10);
        dial_1->setNotchesVisible(true);

        horizontalLayout_6->addWidget(dial_1);

        dial_1_vert_slider = new QSlider(tab);
        dial_1_vert_slider->setObjectName(QStringLiteral("dial_1_vert_slider"));
        dial_1_vert_slider->setMinimum(-32768);
        dial_1_vert_slider->setMaximum(32767);
        dial_1_vert_slider->setOrientation(Qt::Vertical);
        dial_1_vert_slider->setTickPosition(QSlider::TicksBothSides);
        dial_1_vert_slider->setTickInterval(6550);

        horizontalLayout_6->addWidget(dial_1_vert_slider);


        gridLayout_2->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        dial_2_vert_slider = new QSlider(tab);
        dial_2_vert_slider->setObjectName(QStringLiteral("dial_2_vert_slider"));
        dial_2_vert_slider->setMinimum(-32768);
        dial_2_vert_slider->setMaximum(32767);
        dial_2_vert_slider->setOrientation(Qt::Vertical);
        dial_2_vert_slider->setTickPosition(QSlider::TicksBothSides);
        dial_2_vert_slider->setTickInterval(6550);

        horizontalLayout_8->addWidget(dial_2_vert_slider);

        dial_2 = new QDial(tab);
        dial_2->setObjectName(QStringLiteral("dial_2"));
        dial_2->setMinimum(-32768);
        dial_2->setMaximum(32767);
        dial_2->setSingleStep(10);
        dial_2->setNotchTarget(10);
        dial_2->setNotchesVisible(true);

        horizontalLayout_8->addWidget(dial_2);


        gridLayout_2->addLayout(horizontalLayout_8, 1, 2, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        b2 = new QPushButton(tab);
        b2->setObjectName(QStringLiteral("b2"));
        b2->setMinimumSize(QSize(0, 75));

        gridLayout_4->addWidget(b2, 2, 1, 1, 1);

        dial_4 = new QDial(tab);
        dial_4->setObjectName(QStringLiteral("dial_4"));
        dial_4->setMaximumSize(QSize(16777215, 120));
        dial_4->setMinimum(-32768);
        dial_4->setMaximum(32767);
        dial_4->setSingleStep(10);
        dial_4->setNotchTarget(10);
        dial_4->setNotchesVisible(true);

        gridLayout_4->addWidget(dial_4, 6, 1, 1, 1);

        b1 = new QPushButton(tab);
        b1->setObjectName(QStringLiteral("b1"));
        b1->setMinimumSize(QSize(0, 75));

        gridLayout_4->addWidget(b1, 2, 0, 1, 1);

        b4 = new QPushButton(tab);
        b4->setObjectName(QStringLiteral("b4"));
        b4->setMinimumSize(QSize(0, 75));

        gridLayout_4->addWidget(b4, 3, 1, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        b3 = new QPushButton(tab);
        b3->setObjectName(QStringLiteral("b3"));
        b3->setMinimumSize(QSize(0, 75));

        gridLayout_10->addWidget(b3, 2, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_10, 3, 0, 1, 1);

        dial_3 = new QDial(tab);
        dial_3->setObjectName(QStringLiteral("dial_3"));
        dial_3->setMaximumSize(QSize(16777215, 120));
        dial_3->setMinimum(-32768);
        dial_3->setMaximum(32767);
        dial_3->setSingleStep(10);
        dial_3->setNotchTarget(10);
        dial_3->setNotchesVisible(true);

        gridLayout_4->addWidget(dial_3, 6, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 1, 1, 1, 1);

        dial_2_horz_slider = new QSlider(tab);
        dial_2_horz_slider->setObjectName(QStringLiteral("dial_2_horz_slider"));
        dial_2_horz_slider->setMinimum(-32768);
        dial_2_horz_slider->setMaximum(32767);
        dial_2_horz_slider->setOrientation(Qt::Horizontal);
        dial_2_horz_slider->setTickPosition(QSlider::TicksBothSides);
        dial_2_horz_slider->setTickInterval(6550);

        gridLayout_2->addWidget(dial_2_horz_slider, 0, 2, 1, 1);

        dial_1_horz_slider = new QSlider(tab);
        dial_1_horz_slider->setObjectName(QStringLiteral("dial_1_horz_slider"));
        dial_1_horz_slider->setMinimum(-32768);
        dial_1_horz_slider->setMaximum(32767);
        dial_1_horz_slider->setSingleStep(10);
        dial_1_horz_slider->setPageStep(0);
        dial_1_horz_slider->setOrientation(Qt::Horizontal);
        dial_1_horz_slider->setTickPosition(QSlider::TicksBothSides);
        dial_1_horz_slider->setTickInterval(6550);

        gridLayout_2->addWidget(dial_1_horz_slider, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 5);

        bSetRCServer = new QPushButton(tab);
        bSetRCServer->setObjectName(QStringLiteral("bSetRCServer"));
        bSetRCServer->setMaximumSize(QSize(50, 16777215));
        QFont font2;
        font2.setPointSize(12);
        bSetRCServer->setFont(font2);

        gridLayout->addWidget(bSetRCServer, 0, 3, 1, 1);

        tRCServer = new QLineEdit(tab);
        tRCServer->setObjectName(QStringLiteral("tRCServer"));
        tRCServer->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(tRCServer, 0, 2, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(120, 16777215));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 440, 911, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        bLaunchSystem = new QPushButton(horizontalLayoutWidget);
        bLaunchSystem->setObjectName(QStringLiteral("bLaunchSystem"));
        bLaunchSystem->setMinimumSize(QSize(150, 30));
        bLaunchSystem->setMaximumSize(QSize(110, 30));

        horizontalLayout->addWidget(bLaunchSystem);

        bStopSystem = new QPushButton(horizontalLayoutWidget);
        bStopSystem->setObjectName(QStringLiteral("bStopSystem"));
        bStopSystem->setMinimumSize(QSize(110, 30));
        bStopSystem->setMaximumSize(QSize(110, 30));

        horizontalLayout->addWidget(bStopSystem);

        bCLOSE = new QPushButton(horizontalLayoutWidget);
        bCLOSE->setObjectName(QStringLiteral("bCLOSE"));
        bCLOSE->setMinimumSize(QSize(110, 30));
        bCLOSE->setMaximumSize(QSize(110, 30));
        QFont font3;
        font3.setPointSize(16);
        bCLOSE->setFont(font3);

        horizontalLayout->addWidget(bCLOSE);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_2->setText(QApplication::translate("MainWindow", "AVAILABLE NODES", 0));
        bClearFilter->setText(QApplication::translate("MainWindow", "Clear Filter", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabDiagnostics), QApplication::translate("MainWindow", "Diagnostics", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabResources), QApplication::translate("MainWindow", "Resources", 0));
        label_3->setText(QApplication::translate("MainWindow", "V:", 0));
        label_4->setText(QApplication::translate("MainWindow", "A:", 0));
        b2->setText(QApplication::translate("MainWindow", "B2", 0));
        b1->setText(QApplication::translate("MainWindow", "B1", 0));
        b4->setText(QApplication::translate("MainWindow", "B4", 0));
        b3->setText(QApplication::translate("MainWindow", "B3", 0));
        bSetRCServer->setText(QApplication::translate("MainWindow", "SET", 0));
        label->setText(QApplication::translate("MainWindow", "ROS Core:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Remote Control", 0));
        bLaunchSystem->setText(QApplication::translate("MainWindow", "Launch System", 0));
        bStopSystem->setText(QApplication::translate("MainWindow", "Stop System", 0));
        bCLOSE->setText(QApplication::translate("MainWindow", "CLOSE", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
