/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *le_user;
    QLineEdit *le_incomingcallinfo;
    QPushButton *pb_call;
    QPushButton *pb_hungup;
    QPushButton *pb_call_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(409, 271);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 30, 61, 21));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 158, 131, 21));
        label_2->setFont(font);
        le_user = new QLineEdit(centralwidget);
        le_user->setObjectName(QStringLiteral("le_user"));
        le_user->setGeometry(QRect(140, 30, 171, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        le_user->setFont(font1);
        le_incomingcallinfo = new QLineEdit(centralwidget);
        le_incomingcallinfo->setObjectName(QStringLiteral("le_incomingcallinfo"));
        le_incomingcallinfo->setGeometry(QRect(190, 158, 171, 21));
        le_incomingcallinfo->setFont(font1);
        pb_call = new QPushButton(centralwidget);
        pb_call->setObjectName(QStringLiteral("pb_call"));
        pb_call->setGeometry(QRect(88, 86, 80, 22));
        pb_call->setFont(font);
        pb_hungup = new QPushButton(centralwidget);
        pb_hungup->setObjectName(QStringLiteral("pb_hungup"));
        pb_hungup->setGeometry(QRect(178, 86, 80, 22));
        pb_hungup->setFont(font);
        pb_call_2 = new QPushButton(centralwidget);
        pb_call_2->setObjectName(QStringLiteral("pb_call_2"));
        pb_call_2->setGeometry(QRect(130, 120, 80, 22));
        pb_call_2->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 409, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Voice Call", nullptr));
        label->setText(QApplication::translate("MainWindow", "User", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Incoming call Info", nullptr));
        pb_call->setText(QApplication::translate("MainWindow", "Call", nullptr));
        pb_hungup->setText(QApplication::translate("MainWindow", "Hungup", nullptr));
        pb_call_2->setText(QApplication::translate("MainWindow", "record", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
