/********************************************************************************
** Form generated from reading UI file 'frontpanel.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRONTPANEL_H
#define UI_FRONTPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrontPanel
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FrontPanel)
    {
        if (FrontPanel->objectName().isEmpty())
            FrontPanel->setObjectName("FrontPanel");
        FrontPanel->resize(800, 600);
        centralwidget = new QWidget(FrontPanel);
        centralwidget->setObjectName("centralwidget");
        FrontPanel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FrontPanel);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        FrontPanel->setMenuBar(menubar);
        statusbar = new QStatusBar(FrontPanel);
        statusbar->setObjectName("statusbar");
        FrontPanel->setStatusBar(statusbar);

        retranslateUi(FrontPanel);

        QMetaObject::connectSlotsByName(FrontPanel);
    } // setupUi

    void retranslateUi(QMainWindow *FrontPanel)
    {
        FrontPanel->setWindowTitle(QCoreApplication::translate("FrontPanel", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrontPanel: public Ui_FrontPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRONTPANEL_H
