#include "tp4.h"
#include "inscriptioncandidatinterface.h"
#include "inscriptionelecteurinterface.h"
#include "desinscrireinterface.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>
#include <iostream>
#include <vector>

using namespace std;
using namespace util;
using namespace elections;

TP4::TP4(QWidget *parent)
    : QMainWindow(parent), m_circonscription("Circonscription1", Candidat("000 000 000", "prenom", "nom",
    		Date(01, 01, 2000), Adresse(123, "rue", "ville", "codePostal", "province"), 0))
{
	ui.setupUi(this);
	ui.textBrowser->setText(m_circonscription.reqCirconscriptionFormate().c_str());
	QObject::connect(ui.actionInscrire_Candidat, SIGNAL(triggered()), this, SLOT(dialogInscriptionCandidat()));
	QObject::connect(ui.actionInscrire_Electeur, SIGNAL(triggered()), this, SLOT(dialogInscriptionElecteur()));
	QObject::connect(ui.actionDesinscription, SIGNAL(triggered()), this, SLOT(dialogDesinscription()));
}

TP4::~TP4()
{

}
void TP4::dialogInscriptionCandidat()
{
	inscriptionCandidatInterface saisieCandidat(this);
	if (saisieCandidat.exec())
	{
		inscriptionCandidat(saisieCandidat.reqNas().toStdString(), saisieCandidat.reqPrenom().toStdString(),
				saisieCandidat.reqNom().toStdString(), saisieCandidat.reqDateNaissance(),
				Adresse(saisieCandidat.reqNumeroCivic(), saisieCandidat.reqNomRue().toStdString(), saisieCandidat.reqVille().toStdString(),
						saisieCandidat.reqCodePostal().toStdString(), saisieCandidat.reqProvince().toStdString()), saisieCandidat.reqPartiPolitique());
	}
}
void TP4::dialogInscriptionElecteur()
{
	inscriptionElecteurInterface saisieElecteur(this);
	if (saisieElecteur.exec())
	{
		inscriptionElecteur(saisieElecteur.reqNas().toStdString(), saisieElecteur.reqPrenom().toStdString(),
					saisieElecteur.reqNom().toStdString(), saisieElecteur.reqDateNaissance(),
					Adresse(saisieElecteur.reqNumeroCivic(), saisieElecteur.reqNomRue().toStdString(), saisieElecteur.reqVille().toStdString(),
							saisieElecteur.reqCodePostal().toStdString(), saisieElecteur.reqProvince().toStdString()));
	}
}
void TP4::dialogDesinscription()
{
	desinscrireInterface saisieDesinscrire(this);
	if (saisieDesinscrire.exec())
	{
	desinscription(saisieDesinscrire.reqNas().toStdString());
	}
}

void TP4::inscriptionCandidat(const string& p_nas, const string& p_prenom, const string& p_nom,
			const Date& p_dateNaissance, const Adresse& p_adresse, int p_partiPolitique)
{
	try{
		elections::Candidat candidat(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse, p_partiPolitique);
		m_circonscription.inscrire(candidat);
		ui.textBrowser->setText(m_circonscription.reqCirconscriptionFormate().c_str());
	} catch (PersonneDejaPresenteException& erreur) {
		QString message = (erreur.what());
		QMessageBox::information(this, "ERREUR : CANDIDAT DEJA INSCRIT", message);
	}
}
void TP4::inscriptionElecteur(const string& p_nas, const string& p_prenom, const string& p_nom,
			const Date& p_dateNaissance, const Adresse& p_adresse)
{
	try{
			elections::Electeur electeur(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse);
			m_circonscription.inscrire(electeur);
			ui.textBrowser->setText(m_circonscription.reqCirconscriptionFormate().c_str());
	} catch (PersonneDejaPresenteException& erreur) {
		QString message = (erreur.what());
		QMessageBox::information(this, "ERREUR : ELECTEUR DEJA INSCRIT", message);
	}
}
void TP4::desinscription(const string& p_nas)
{
	try{
			m_circonscription.desinscrire(p_nas);
			ui.textBrowser->setText(m_circonscription.reqCirconscriptionFormate().c_str());
	} catch (PersonneAbsenteException& erreur) {
		QString message = (erreur.what());
		QMessageBox::information(this, "ERREUR : PERSONNE ABSENTE", message);
	}
}
