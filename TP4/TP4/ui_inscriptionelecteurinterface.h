/********************************************************************************
** Form generated from reading UI file 'inscriptionelecteurinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSCRIPTIONELECTEURINTERFACE_H
#define UI_INSCRIPTIONELECTEURINTERFACE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_inscriptionElecteurInterfaceClass
{
public:
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_10;
    QLineEdit *lineEdit_5;
    QComboBox *comboBox;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit;
    QLabel *label_7;
    QLabel *label_11;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_6;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton;
    QLineEdit *lineEdit_4;
    QDateEdit *dateEdit;

    void setupUi(QDialog *inscriptionElecteurInterfaceClass)
    {
        if (inscriptionElecteurInterfaceClass->objectName().isEmpty())
            inscriptionElecteurInterfaceClass->setObjectName(QString::fromUtf8("inscriptionElecteurInterfaceClass"));
        inscriptionElecteurInterfaceClass->resize(449, 545);
        label_4 = new QLabel(inscriptionElecteurInterfaceClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 210, 111, 16));
        label_3 = new QLabel(inscriptionElecteurInterfaceClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 140, 53, 17));
        label_6 = new QLabel(inscriptionElecteurInterfaceClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 320, 81, 17));
        label_10 = new QLabel(inscriptionElecteurInterfaceClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(220, 320, 53, 17));
        lineEdit_5 = new QLineEdit(inscriptionElecteurInterfaceClass);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(280, 310, 113, 27));
        comboBox = new QComboBox(inscriptionElecteurInterfaceClass);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(100, 420, 141, 31));
        lineEdit_7 = new QLineEdit(inscriptionElecteurInterfaceClass);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(290, 360, 113, 27));
        lineEdit = new QLineEdit(inscriptionElecteurInterfaceClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 70, 111, 31));
        label_7 = new QLabel(inscriptionElecteurInterfaceClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 380, 53, 17));
        label_11 = new QLabel(inscriptionElecteurInterfaceClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(70, 10, 291, 61));
        lineEdit_2 = new QLineEdit(inscriptionElecteurInterfaceClass);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(290, 70, 131, 31));
        lineEdit_6 = new QLineEdit(inscriptionElecteurInterfaceClass);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(90, 370, 111, 27));
        label_2 = new QLabel(inscriptionElecteurInterfaceClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 80, 51, 21));
        lineEdit_3 = new QLineEdit(inscriptionElecteurInterfaceClass);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(300, 130, 113, 27));
        label_5 = new QLabel(inscriptionElecteurInterfaceClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 270, 61, 21));
        label = new QLabel(inscriptionElecteurInterfaceClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 70, 61, 31));
        label_8 = new QLabel(inscriptionElecteurInterfaceClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(220, 370, 71, 17));
        label_9 = new QLabel(inscriptionElecteurInterfaceClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 430, 53, 17));
        pushButton = new QPushButton(inscriptionElecteurInterfaceClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 470, 111, 41));
        lineEdit_4 = new QLineEdit(inscriptionElecteurInterfaceClass);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(90, 310, 81, 27));
        dateEdit = new QDateEdit(inscriptionElecteurInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(150, 210, 131, 31));
        dateEdit->setMaximumDate(QDate(7937, 12, 31));
        dateEdit->setMinimumDate(QDate(1770, 1, 1));
        dateEdit->setCalendarPopup(true);

        retranslateUi(inscriptionElecteurInterfaceClass);

        QMetaObject::connectSlotsByName(inscriptionElecteurInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *inscriptionElecteurInterfaceClass)
    {
        inscriptionElecteurInterfaceClass->setWindowTitle(QApplication::translate("inscriptionElecteurInterfaceClass", "inscriptionElecteurInterface", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "Date de Naissance", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "Prenom", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "Numero Civic", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "Rue", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Alberta", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Colombie-Britannique", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Ile-du-Prince-Edouard", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Manitoba", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Nouveau-Brunswick", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Nouvelle-Ecosse", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Nunavut", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Ontario", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Quebec", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Saskatchewan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Terre-Neuve-et-Labrador", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Territoires du Nord-Ouest", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("inscriptionElecteurInterfaceClass", "Yukon", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "Ville", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; text-decoration: underline;\">Inscription d'un Electeur</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "Nom", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" text-decoration: underline;\">Adresse :</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "NAS", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "Code Postal", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "Province", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("inscriptionElecteurInterfaceClass", "Inscrire Electeur", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("inscriptionElecteurInterfaceClass", "dd-MM-yyyy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class inscriptionElecteurInterfaceClass: public Ui_inscriptionElecteurInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSCRIPTIONELECTEURINTERFACE_H
