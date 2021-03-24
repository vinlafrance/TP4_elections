/********************************************************************************
** Form generated from reading UI file 'desinscrireinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESINSCRIREINTERFACE_H
#define UI_DESINSCRIREINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_desinscrireInterfaceClass
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_11;

    void setupUi(QDialog *desinscrireInterfaceClass)
    {
        if (desinscrireInterfaceClass->objectName().isEmpty())
            desinscrireInterfaceClass->setObjectName(QString::fromUtf8("desinscrireInterfaceClass"));
        desinscrireInterfaceClass->resize(400, 300);
        pushButton = new QPushButton(desinscrireInterfaceClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(118, 210, 151, 41));
        label = new QLabel(desinscrireInterfaceClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(88, 140, 53, 17));
        lineEdit = new QLineEdit(desinscrireInterfaceClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 130, 141, 31));
        label_11 = new QLabel(desinscrireInterfaceClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(68, 20, 291, 61));

        retranslateUi(desinscrireInterfaceClass);

        QMetaObject::connectSlotsByName(desinscrireInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *desinscrireInterfaceClass)
    {
        desinscrireInterfaceClass->setWindowTitle(QApplication::translate("desinscrireInterfaceClass", "desinscrireInterface", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("desinscrireInterfaceClass", "Desinscrire personne", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("desinscrireInterfaceClass", "NAS", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("desinscrireInterfaceClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; text-decoration: underline;\">Desinscrire une personne</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class desinscrireInterfaceClass: public Ui_desinscrireInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESINSCRIREINTERFACE_H
