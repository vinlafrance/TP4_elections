#include "inscriptioncandidatinterface.h"
#include "validationFormat.h"
#include <string>
#include <iostream>
#include <sstream>
#include <QMessageBox>

inscriptionCandidatInterface::inscriptionCandidatInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.dateEdit->setDate(QDate::currentDate());
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(validerInscription()));
}

inscriptionCandidatInterface::~inscriptionCandidatInterface()
{

}
QString inscriptionCandidatInterface::reqNas() const{
	return ui.lineEdit->text();
}
QString inscriptionCandidatInterface::reqNom() const{
	return ui.lineEdit_2->text();
}
QString inscriptionCandidatInterface::reqPrenom() const{
	return ui.lineEdit_3->text();
}
util::Date inscriptionCandidatInterface::reqDateNaissance() const{
	return m_dateNaissance;
}
int inscriptionCandidatInterface::reqNumeroCivic() const{
	std::string noCivic = ui.lineEdit_4->text().toStdString();
	return std::stoi(noCivic);
}
QString inscriptionCandidatInterface::reqNomRue() const{
	return ui.lineEdit_5->text();
}
QString inscriptionCandidatInterface::reqVille() const{
	return ui.lineEdit_6->text();
}
QString inscriptionCandidatInterface::reqCodePostal() const{
	return ui.lineEdit_7->text();
}
QString inscriptionCandidatInterface::reqProvince() const{
	return ui.comboBox->currentText();
}
int inscriptionCandidatInterface::reqPartiPolitique() const{
	std::string parti = ui.comboBox_2->currentText().toStdString();
	int numero;
	if(parti == "BLOC_QUEBECOIS")
	{
		numero = 0;
	}
	if(parti == "CONSERVATEUR")
	{
		numero = 1;
	}
	if(parti == "INDEPENDANT")
	{
		numero = 2;
	}
	if(parti == "LIBERAL")
	{
		numero = 3;
	}
	if(parti == "NOUVEAU_PARTI_DEMOCRATIQUE")
	{
		numero = 4;
	}
	return numero;
}

void inscriptionCandidatInterface::validerInscription(){
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
	}
	if(ui.comboBox_2->currentText().isEmpty()){
		QString message("Le parti politique ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}else{
		m_dateNaissance.asgDate(ui.dateEdit->date().day(), ui.dateEdit->date().month(),
				ui.dateEdit->date().year());
		accept();
	}
}
