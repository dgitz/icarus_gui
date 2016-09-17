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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *bCLOSE;
    QPushButton *bLaunchSystem;
    QPushButton *bStopSystem;
    QTabWidget *tabWidget;
    QWidget *tabDiagnostics;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QTextBrowser *textBrowser;
    QTreeWidget *treeDeviceList;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *bClearFilter;
    QWidget *tabResources;
    QWidget *tab;
    QGridLayout *gridLayout;
    QDial *dial_8;
    QLineEdit *tRCServer;
    QDial *dial_5;
    QDial *dial_3;
    QDial *dial_7;
    QDial *dial_2;
    QDial *dial_4;
    QDial *dial_6;
    QPushButton *bSetRCServer;
    QLabel *label;
    QDial *dial_1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(975, 480);
        MainWindow->setMaximumSize(QSize(975, 480));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 420, 344, 57));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        bCLOSE = new QPushButton(layoutWidget);
        bCLOSE->setObjectName(QStringLiteral("bCLOSE"));
        bCLOSE->setMinimumSize(QSize(110, 55));
        bCLOSE->setMaximumSize(QSize(110, 55));
        QFont font;
        font.setPointSize(22);
        bCLOSE->setFont(font);

        horizontalLayout->addWidget(bCLOSE);

        bLaunchSystem = new QPushButton(layoutWidget);
        bLaunchSystem->setObjectName(QStringLiteral("bLaunchSystem"));
        bLaunchSystem->setMinimumSize(QSize(110, 55));
        bLaunchSystem->setMaximumSize(QSize(110, 55));

        horizontalLayout->addWidget(bLaunchSystem);

        bStopSystem = new QPushButton(layoutWidget);
        bStopSystem->setObjectName(QStringLiteral("bStopSystem"));
        bStopSystem->setMinimumSize(QSize(110, 55));
        bStopSystem->setMaximumSize(QSize(110, 55));

        horizontalLayout->addWidget(bStopSystem);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 961, 411));
        QFont font1;
        font1.setPointSize(14);
        tabWidget->setFont(font1);
        tabDiagnostics = new QWidget();
        tabDiagnostics->setObjectName(QStringLiteral("tabDiagnostics"));
        layoutWidget1 = new QWidget(tabDiagnostics);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 493, 391));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(330, 0));
        comboBox->setMaximumSize(QSize(330, 50));
        QFont font2;
        font2.setPointSize(24);
        comboBox->setFont(font2);

        verticalLayout->addWidget(comboBox);

        textBrowser = new QTextBrowser(layoutWidget1);
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
        layoutWidget2 = new QWidget(tabDiagnostics);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(500, 0, 449, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(300, 16));
        label_2->setMaximumSize(QSize(300, 16));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        bClearFilter = new QPushButton(layoutWidget2);
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
        dial_8 = new QDial(tab);
        dial_8->setObjectName(QStringLiteral("dial_8"));
        dial_8->setMinimum(-32768);
        dial_8->setMaximum(32787);
        dial_8->setSingleStep(10);
        dial_8->setNotchesVisible(true);

        gridLayout->addWidget(dial_8, 4, 3, 1, 1);

        tRCServer = new QLineEdit(tab);
        tRCServer->setObjectName(QStringLiteral("tRCServer"));
        tRCServer->setMaximumSize(QSize(300, 30));

        gridLayout->addWidget(tRCServer, 1, 1, 1, 1);

        dial_5 = new QDial(tab);
        dial_5->setObjectName(QStringLiteral("dial_5"));
        dial_5->setMinimum(-32768);
        dial_5->setMaximum(32787);
        dial_5->setSingleStep(10);
        dial_5->setNotchesVisible(true);

        gridLayout->addWidget(dial_5, 4, 0, 1, 1);

        dial_3 = new QDial(tab);
        dial_3->setObjectName(QStringLiteral("dial_3"));
        dial_3->setMinimum(-32768);
        dial_3->setMaximum(32787);
        dial_3->setSingleStep(10);
        dial_3->setNotchesVisible(true);

        gridLayout->addWidget(dial_3, 2, 2, 1, 1);

        dial_7 = new QDial(tab);
        dial_7->setObjectName(QStringLiteral("dial_7"));
        dial_7->setMinimum(-32768);
        dial_7->setMaximum(32787);
        dial_7->setSingleStep(10);
        dial_7->setNotchesVisible(true);

        gridLayout->addWidget(dial_7, 4, 2, 1, 1);

        dial_2 = new QDial(tab);
        dial_2->setObjectName(QStringLiteral("dial_2"));
        dial_2->setMinimum(-32768);
        dial_2->setMaximum(32787);
        dial_2->setSingleStep(10);
        dial_2->setNotchesVisible(true);

        gridLayout->addWidget(dial_2, 2, 1, 1, 1);

        dial_4 = new QDial(tab);
        dial_4->setObjectName(QStringLiteral("dial_4"));
        dial_4->setMinimum(-32768);
        dial_4->setMaximum(32787);
        dial_4->setSingleStep(10);
        dial_4->setNotchesVisible(true);

        gridLayout->addWidget(dial_4, 2, 3, 1, 1);

        dial_6 = new QDial(tab);
        dial_6->setObjectName(QStringLiteral("dial_6"));
        dial_6->setMinimum(-32768);
        dial_6->setMaximum(32787);
        dial_6->setSingleStep(10);
        dial_6->setNotchesVisible(true);

        gridLayout->addWidget(dial_6, 4, 1, 1, 1);

        bSetRCServer = new QPushButton(tab);
        bSetRCServer->setObjectName(QStringLiteral("bSetRCServer"));
        bSetRCServer->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(bSetRCServer, 1, 2, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        dial_1 = new QDial(tab);
        dial_1->setObjectName(QStringLiteral("dial_1"));
        dial_1->setMinimum(-32768);
        dial_1->setMaximum(32787);
        dial_1->setSingleStep(10);
        dial_1->setNotchesVisible(true);

        gridLayout->addWidget(dial_1, 2, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        bCLOSE->setText(QApplication::translate("MainWindow", "CLOSE", 0));
        bLaunchSystem->setText(QApplication::translate("MainWindow", "Launch\n"
"System", 0));
        bStopSystem->setText(QApplication::translate("MainWindow", "Stop\n"
"System", 0));
        label_2->setText(QApplication::translate("MainWindow", "AVAILABLE NODES", 0));
        bClearFilter->setText(QApplication::translate("MainWindow", "Clear Filter", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabDiagnostics), QApplication::translate("MainWindow", "Diagnostics", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabResources), QApplication::translate("MainWindow", "Resources", 0));
        bSetRCServer->setText(QApplication::translate("MainWindow", "SET", 0));
        label->setText(QApplication::translate("MainWindow", "ROSCORE:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Remote Control", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
