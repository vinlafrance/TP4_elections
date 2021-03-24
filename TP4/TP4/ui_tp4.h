/********************************************************************************
** Form generated from reading UI file 'tp4.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TP4_H
#define UI_TP4_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TP4Class
{
public:
    QAction *actionInscrire_Candidat;
    QAction *actionInscrire_Electeur;
    QAction *actionDesinscription;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menuOperations;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TP4Class)
    {
        if (TP4Class->objectName().isEmpty())
            TP4Class->setObjectName(QString::fromUtf8("TP4Class"));
        TP4Class->resize(800, 600);
        actionInscrire_Candidat = new QAction(TP4Class);
        actionInscrire_Candidat->setObjectName(QString::fromUtf8("actionInscrire_Candidat"));
        actionInscrire_Electeur = new QAction(TP4Class);
        actionInscrire_Electeur->setObjectName(QString::fromUtf8("actionInscrire_Electeur"));
        actionDesinscription = new QAction(TP4Class);
        actionDesinscription->setObjectName(QString::fromUtf8("actionDesinscription"));
        actionQuitter = new QAction(TP4Class);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(TP4Class);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(240, 10, 541, 521));
        TP4Class->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TP4Class);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuOperations = new QMenu(menubar);
        menuOperations->setObjectName(QString::fromUtf8("menuOperations"));
        TP4Class->setMenuBar(menubar);
        statusbar = new QStatusBar(TP4Class);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TP4Class->setStatusBar(statusbar);

        menubar->addAction(menuOperations->menuAction());
        menuOperations->addAction(actionInscrire_Candidat);
        menuOperations->addSeparator();
        menuOperations->addAction(actionInscrire_Electeur);
        menuOperations->addSeparator();
        menuOperations->addAction(actionDesinscription);
        menuOperations->addSeparator();
        menuOperations->addAction(actionQuitter);

        retranslateUi(TP4Class);
        QObject::connect(actionQuitter, SIGNAL(triggered()), TP4Class, SLOT(close()));

        QMetaObject::connectSlotsByName(TP4Class);
    } // setupUi

    void retranslateUi(QMainWindow *TP4Class)
    {
        TP4Class->setWindowTitle(QApplication::translate("TP4Class", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionInscrire_Candidat->setText(QApplication::translate("TP4Class", "Inscrire Candidat", 0, QApplication::UnicodeUTF8));
        actionInscrire_Electeur->setText(QApplication::translate("TP4Class", "Inscrire Electeur", 0, QApplication::UnicodeUTF8));
        actionDesinscription->setText(QApplication::translate("TP4Class", "Desinscription", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("TP4Class", "Quitter", 0, QApplication::UnicodeUTF8));
        menuOperations->setTitle(QApplication::translate("TP4Class", "Operations", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TP4Class: public Ui_TP4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TP4_H
