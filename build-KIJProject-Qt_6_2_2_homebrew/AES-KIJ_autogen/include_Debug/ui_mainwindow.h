/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *actionPushBtn;
    QLabel *label_pic;
    QLabel *encryptedPic;
    QLabel *leftLabel;
    QLabel *rightLabel;
    QPushButton *senderPushBtn;
    QPushButton *recieverPushBtn;
    QLabel *leftLabel_2;
    QLabel *leftLabel_3;
    QLabel *leftLabel_4;
    QLabel *leftLabel_5;
    QLabel *performanceNON;
    QLabel *leftLabel_7;
    QLabel *CertStatus;
    QLineEdit *passwordInput;
    QLabel *leftLabel_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1109, 579);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        actionPushBtn = new QPushButton(centralWidget);
        actionPushBtn->setObjectName(QString::fromUtf8("actionPushBtn"));
        actionPushBtn->setGeometry(QRect(10, 430, 75, 23));
        label_pic = new QLabel(centralWidget);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setGeometry(QRect(10, 50, 431, 241));
        encryptedPic = new QLabel(centralWidget);
        encryptedPic->setObjectName(QString::fromUtf8("encryptedPic"));
        encryptedPic->setGeometry(QRect(550, 60, 461, 241));
        leftLabel = new QLabel(centralWidget);
        leftLabel->setObjectName(QString::fromUtf8("leftLabel"));
        leftLabel->setGeometry(QRect(10, 20, 131, 16));
        rightLabel = new QLabel(centralWidget);
        rightLabel->setObjectName(QString::fromUtf8("rightLabel"));
        rightLabel->setGeometry(QRect(550, 20, 131, 16));
        senderPushBtn = new QPushButton(centralWidget);
        senderPushBtn->setObjectName(QString::fromUtf8("senderPushBtn"));
        senderPushBtn->setGeometry(QRect(10, 370, 80, 24));
        recieverPushBtn = new QPushButton(centralWidget);
        recieverPushBtn->setObjectName(QString::fromUtf8("recieverPushBtn"));
        recieverPushBtn->setGeometry(QRect(110, 370, 80, 24));
        leftLabel_2 = new QLabel(centralWidget);
        leftLabel_2->setObjectName(QString::fromUtf8("leftLabel_2"));
        leftLabel_2->setGeometry(QRect(10, 340, 131, 16));
        leftLabel_3 = new QLabel(centralWidget);
        leftLabel_3->setObjectName(QString::fromUtf8("leftLabel_3"));
        leftLabel_3->setGeometry(QRect(470, 340, 181, 16));
        leftLabel_4 = new QLabel(centralWidget);
        leftLabel_4->setObjectName(QString::fromUtf8("leftLabel_4"));
        leftLabel_4->setGeometry(QRect(470, 370, 131, 16));
        leftLabel_5 = new QLabel(centralWidget);
        leftLabel_5->setObjectName(QString::fromUtf8("leftLabel_5"));
        leftLabel_5->setGeometry(QRect(620, 370, 131, 16));
        performanceNON = new QLabel(centralWidget);
        performanceNON->setObjectName(QString::fromUtf8("performanceNON"));
        performanceNON->setGeometry(QRect(470, 400, 131, 16));
        leftLabel_7 = new QLabel(centralWidget);
        leftLabel_7->setObjectName(QString::fromUtf8("leftLabel_7"));
        leftLabel_7->setGeometry(QRect(620, 400, 131, 16));
        CertStatus = new QLabel(centralWidget);
        CertStatus->setObjectName(QString::fromUtf8("CertStatus"));
        CertStatus->setGeometry(QRect(20, 400, 181, 16));
        passwordInput = new QLineEdit(centralWidget);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setGeometry(QRect(240, 370, 113, 24));
        leftLabel_6 = new QLabel(centralWidget);
        leftLabel_6->setObjectName(QString::fromUtf8("leftLabel_6"));
        leftLabel_6->setGeometry(QRect(240, 340, 131, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1109, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionPushBtn->setText(QCoreApplication::translate("MainWindow", "ROLE", nullptr));
        label_pic->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        encryptedPic->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        leftLabel->setText(QCoreApplication::translate("MainWindow", "NULL", nullptr));
        rightLabel->setText(QCoreApplication::translate("MainWindow", "NULL", nullptr));
        senderPushBtn->setText(QCoreApplication::translate("MainWindow", "Sender", nullptr));
        recieverPushBtn->setText(QCoreApplication::translate("MainWindow", "Reciever", nullptr));
        leftLabel_2->setText(QCoreApplication::translate("MainWindow", "Select Role", nullptr));
        leftLabel_3->setText(QCoreApplication::translate("MainWindow", "Performance In Mb/s", nullptr));
        leftLabel_4->setText(QCoreApplication::translate("MainWindow", "Non OPENSSL", nullptr));
        leftLabel_5->setText(QCoreApplication::translate("MainWindow", "WithOpenSSL", nullptr));
        performanceNON->setText(QCoreApplication::translate("MainWindow", "NULL", nullptr));
        leftLabel_7->setText(QCoreApplication::translate("MainWindow", "NULL", nullptr));
        CertStatus->setText(QCoreApplication::translate("MainWindow", "Certificate Status", nullptr));
        leftLabel_6->setText(QCoreApplication::translate("MainWindow", "Set password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
