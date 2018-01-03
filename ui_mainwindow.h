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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
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
    QLabel *lNodeDescription;
    QLabel *lNodeVersion;
    QWidget *tabResources;
    QWidget *tab_2;
    QComboBox *cArmChooser;
    QScrollBar *armslider1;
    QScrollBar *armslider2;
    QScrollBar *armslider3;
    QScrollBar *armslider5;
    QScrollBar *armslider6;
    QScrollBar *armslider4;
    QPushButton *bRTH;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *bLaunchSystem;
    QLineEdit *tRCServer;
    QPushButton *bSetRCServer;
    QPushButton *bArmDisarm;
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
        tabWidget->setEnabled(true);
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
        treeDeviceList->setGeometry(QRect(500, 40, 400, 275));
        treeDeviceList->setMinimumSize(QSize(400, 275));
        treeDeviceList->setMaximumSize(QSize(300, 275));
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

        lNodeDescription = new QLabel(tabDiagnostics);
        lNodeDescription->setObjectName(QStringLiteral("lNodeDescription"));
        lNodeDescription->setGeometry(QRect(500, 320, 391, 31));
        lNodeDescription->setFrameShape(QFrame::Box);
        lNodeVersion = new QLabel(tabDiagnostics);
        lNodeVersion->setObjectName(QStringLiteral("lNodeVersion"));
        lNodeVersion->setGeometry(QRect(500, 360, 391, 31));
        lNodeVersion->setFrameShape(QFrame::Box);
        tabWidget->addTab(tabDiagnostics, QString());
        tabResources = new QWidget();
        tabResources->setObjectName(QStringLiteral("tabResources"));
        tabResources->setEnabled(false);
        tabWidget->addTab(tabResources, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setEnabled(false);
        cArmChooser = new QComboBox(tab_2);
        cArmChooser->setObjectName(QStringLiteral("cArmChooser"));
        cArmChooser->setGeometry(QRect(10, 20, 231, 23));
        armslider1 = new QScrollBar(tab_2);
        armslider1->setObjectName(QStringLiteral("armslider1"));
        armslider1->setGeometry(QRect(30, 100, 81, 261));
        armslider1->setMinimum(-32768);
        armslider1->setMaximum(32767);
        armslider1->setOrientation(Qt::Vertical);
        armslider2 = new QScrollBar(tab_2);
        armslider2->setObjectName(QStringLiteral("armslider2"));
        armslider2->setGeometry(QRect(120, 100, 81, 261));
        armslider2->setMinimum(-32768);
        armslider2->setMaximum(32767);
        armslider2->setOrientation(Qt::Vertical);
        armslider3 = new QScrollBar(tab_2);
        armslider3->setObjectName(QStringLiteral("armslider3"));
        armslider3->setGeometry(QRect(210, 100, 81, 261));
        armslider3->setMinimum(-32768);
        armslider3->setMaximum(32767);
        armslider3->setOrientation(Qt::Vertical);
        armslider5 = new QScrollBar(tab_2);
        armslider5->setObjectName(QStringLiteral("armslider5"));
        armslider5->setGeometry(QRect(390, 100, 81, 261));
        armslider5->setMinimum(-32768);
        armslider5->setMaximum(32767);
        armslider5->setOrientation(Qt::Vertical);
        armslider6 = new QScrollBar(tab_2);
        armslider6->setObjectName(QStringLiteral("armslider6"));
        armslider6->setGeometry(QRect(480, 100, 81, 261));
        armslider6->setMinimum(-32768);
        armslider6->setMaximum(32767);
        armslider6->setOrientation(Qt::Vertical);
        armslider4 = new QScrollBar(tab_2);
        armslider4->setObjectName(QStringLiteral("armslider4"));
        armslider4->setGeometry(QRect(300, 100, 81, 261));
        armslider4->setMinimum(-32768);
        armslider4->setMaximum(32767);
        armslider4->setOrientation(Qt::Vertical);
        bRTH = new QPushButton(tab_2);
        bRTH->setObjectName(QStringLiteral("bRTH"));
        bRTH->setGeometry(QRect(270, 20, 181, 23));
        tabWidget->addTab(tab_2, QString());
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

        tRCServer = new QLineEdit(horizontalLayoutWidget);
        tRCServer->setObjectName(QStringLiteral("tRCServer"));
        tRCServer->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(tRCServer);

        bSetRCServer = new QPushButton(horizontalLayoutWidget);
        bSetRCServer->setObjectName(QStringLiteral("bSetRCServer"));
        bSetRCServer->setMaximumSize(QSize(50, 16777215));
        QFont font2;
        font2.setPointSize(12);
        bSetRCServer->setFont(font2);

        horizontalLayout->addWidget(bSetRCServer);

        bArmDisarm = new QPushButton(horizontalLayoutWidget);
        bArmDisarm->setObjectName(QStringLiteral("bArmDisarm"));
        bArmDisarm->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(bArmDisarm);

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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_2->setText(QApplication::translate("MainWindow", "AVAILABLE NODES", 0));
        bClearFilter->setText(QApplication::translate("MainWindow", "Clear Filter", 0));
        lNodeDescription->setText(QApplication::translate("MainWindow", "Node Description", 0));
        lNodeVersion->setText(QApplication::translate("MainWindow", "Node Version", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabDiagnostics), QApplication::translate("MainWindow", "Diagnostics", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabResources), QApplication::translate("MainWindow", "Resources", 0));
        bRTH->setText(QApplication::translate("MainWindow", "Return To Home", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Arm", 0));
        bLaunchSystem->setText(QApplication::translate("MainWindow", "Launch System", 0));
        bSetRCServer->setText(QApplication::translate("MainWindow", "SET", 0));
        bArmDisarm->setText(QApplication::translate("MainWindow", "UNDEFINED", 0));
        bStopSystem->setText(QApplication::translate("MainWindow", "Stop System", 0));
        bCLOSE->setText(QApplication::translate("MainWindow", "CLOSE", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
