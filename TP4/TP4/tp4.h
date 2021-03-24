#ifndef TP4_H
#define TP4_H

#include <QtGui/QMainWindow>
#include "ui_tp4.h"
#include <string>
#include "Circonscription.h"

class TP4 : public QMainWindow
{
    Q_OBJECT

public:
    TP4(QWidget *parent = 0);
    ~TP4();
    void inscriptionCandidat(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
			const util::Date& p_dateNaissance, const util::Adresse& p_adresse, int p_partiPolitique);
    void inscriptionElecteur(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
			const util::Date& p_dateNaissance, const util::Adresse& p_adresse);
    void desinscription(const std::string& p_nas);

public slots :
	void dialogInscriptionCandidat();
	void dialogInscriptionElecteur();
	void dialogDesinscription();

private:
    Ui::TP4Class ui;
    elections::Circonscription m_circonscription;
};

#endif // TP4_H
