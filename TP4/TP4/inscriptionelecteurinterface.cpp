#include "inscriptionelecteurinterface.h"
#include "validationFormat.h"
#include <string>
#include <iostream>
#include <sstream>
#include <QMessageBox>

inscriptionElecteurInterface::inscriptionElecteurInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.dateEdit->setDate(QDate::currentDate());
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(validerInscription()));
}

inscriptionElecteurInterface::~inscriptionElecteurInterface()
{

}
QString inscriptionElecteurInterface::reqNas() const{
	return ui.lineEdit->text();
}
QString inscriptionElecteurInterface::reqNom() const{
	return ui.lineEdit_2->text();
}
QString inscriptionElecteurInterface::reqPrenom() const{
	return ui.lineEdit_3->text();
}
util::Date inscriptionElecteurInterface::reqDateNaissance() const{
	return m_dateNaissance;
}
int inscriptionElecteurInterface::reqNumeroCivic() const{
	std::string noCivic = ui.lineEdit->text().toStdString();
	return std::stoi(noCivic);
}
QString inscriptionElecteurInterface::reqNomRue() const{
	return ui.lineEdit_5->text();
}
QString inscriptionElecteurInterface::reqVille() const{
	return ui.lineEdit_6->text();
}
QString inscriptionElecteurInterface::reqCodePostal() const{
	return ui.lineEdit_7->text();
}
QString inscriptionElecteurInterface::reqProvince() const{
	return ui.comboBox->currentText();
}

void inscriptionElecteurInterface::validerInscription(){
	std::string nas = ui.lineEdit->text().toStdString();
	if (!util::validerNas(nas)){
		QString message("Le nas doit etre valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_2->text().isEmpty()){
		QString message("Le nom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_3->text().isEmpty()){
		QString message("Le prenom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	QDate qDate = QDate::currentDate();
	if(ui.dateEdit->date() >= qDate){
		QString message("La date de naissance n'est pas valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	std::string noCivic = ui.lineEdit_4->text().toStdString();
	try{
		if(stoi(noCivic) < 0){
			QString message("Le numero civic ne doit pas etre negatif");
			QMessageBox::information(this, "ERREUR", message);
			return;
		}
	} catch(...) {
		QString message("Le numero civic doit etre un nombre");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_5->text().isEmpty()){
		QString message("Le nom de la rue ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_6->text().isEmpty()){
		QString message("La ville ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_7->text().isEmpty()){
		QString message("Le code postal ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.comboBox->currentText().isEmpty()){
		QString message("La province ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	} else{
		m_dateNaissance.asgDate(ui.dateEdit->date().day(), ui.dateEdit->date().month(),
				ui.dateEdit->date().year());
		accept();
	}
}
