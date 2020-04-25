/********************************************************************************
** Form generated from reading UI file 'practic1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTIC1_H
#define UI_PRACTIC1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_practic1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *practic1Class)
    {
        if (practic1Class->objectName().isEmpty())
            practic1Class->setObjectName(QString::fromUtf8("practic1Class"));
        practic1Class->resize(600, 400);
        menuBar = new QMenuBar(practic1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        practic1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(practic1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        practic1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(practic1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        practic1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(practic1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        practic1Class->setStatusBar(statusBar);

        retranslateUi(practic1Class);

        QMetaObject::connectSlotsByName(practic1Class);
    } // setupUi

    void retranslateUi(QMainWindow *practic1Class)
    {
        practic1Class->setWindowTitle(QApplication::translate("practic1Class", "practic1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class practic1Class: public Ui_practic1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTIC1_H
