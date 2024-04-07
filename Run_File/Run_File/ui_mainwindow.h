/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QGroupBox *groupBox;
    QLineEdit *Connection;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QComboBox *BaurdRate;
    QComboBox *ComPort;
    QPushButton *Connect;
    QPushButton *Disconnect;
    QPushButton *Clear;
    QTextEdit *Received_RawData;
    QPushButton *SaveButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 10, 311, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 60, 561, 61));
        Connection = new QLineEdit(groupBox);
        Connection->setObjectName(QString::fromUtf8("Connection"));
        Connection->setGeometry(QRect(10, 20, 143, 20));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(160, 14, 391, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        BaurdRate = new QComboBox(widget);
        BaurdRate->addItem(QString());
        BaurdRate->addItem(QString());
        BaurdRate->addItem(QString());
        BaurdRate->setObjectName(QString::fromUtf8("BaurdRate"));

        horizontalLayout->addWidget(BaurdRate);

        ComPort = new QComboBox(widget);
        ComPort->setObjectName(QString::fromUtf8("ComPort"));

        horizontalLayout->addWidget(ComPort);

        Connect = new QPushButton(widget);
        Connect->setObjectName(QString::fromUtf8("Connect"));

        horizontalLayout->addWidget(Connect);

        Disconnect = new QPushButton(widget);
        Disconnect->setObjectName(QString::fromUtf8("Disconnect"));

        horizontalLayout->addWidget(Disconnect);

        Clear = new QPushButton(widget);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        horizontalLayout->addWidget(Clear);

        Received_RawData = new QTextEdit(centralwidget);
        Received_RawData->setObjectName(QString::fromUtf8("Received_RawData"));
        Received_RawData->setGeometry(QRect(40, 140, 341, 241));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(440, 240, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Serial Communication", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Communication", nullptr));
        BaurdRate->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        BaurdRate->setItemText(1, QCoreApplication::translate("MainWindow", "57600", nullptr));
        BaurdRate->setItemText(2, QCoreApplication::translate("MainWindow", "115200", nullptr));

        Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        Disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        SaveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
