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
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *bClearFilter;
    QWidget *tabResources;

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
        widget = new QWidget(tabDiagnostics);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(500, 0, 449, 33));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(300, 16));
        label_2->setMaximumSize(QSize(300, 16));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        bClearFilter = new QPushButton(widget);
        bClearFilter->setObjectName(QStringLiteral("bClearFilter"));

        horizontalLayout_2->addWidget(bClearFilter);

        tabWidget->addTab(tabDiagnostics, QString());
        layoutWidget->raise();
        label_2->raise();
        treeDeviceList->raise();
        treeDeviceList->raise();
        tabResources = new QWidget();
        tabResources->setObjectName(QStringLiteral("tabResources"));
        tabWidget->addTab(tabResources, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
