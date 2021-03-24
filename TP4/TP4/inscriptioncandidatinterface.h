#ifndef INSCRIPTIONCANDIDATINTERFACE_H
#define INSCRIPTIONCANDIDATINTERFACE_H

#include <QtGui/QDialog>
#include "ui_inscriptioncandidatinterface.h"
#include "Date.h"

class inscriptionCandidatInterface : public QDialog
{
    Q_OBJECT

public:
    inscriptionCandidatInterface(QWidget *parent = 0);
    ~inscriptionCandidatInterface();
    QString reqNas() const;
	QString reqNom() const;
	QString reqPrenom() const;
	util::Date reqDateNaissance() const;
	int reqNumeroCivic() const;
	QString reqNomRue() const;
	QString reqVille() const;
	QString reqCodePostal() const;
	QString reqProvince() const;
	int reqPartiPolitique() const;

private slots:
	void validerInscription();

private:
    Ui::inscriptionCandidatInterfaceClass ui;
    util::Date m_dateNaissance;
    enum PartisPolitiques {BLOC_QUEBECOIS, CONSERVATEUR, INDEPENDANT, LIBERAL,
    	NOUVEAU_PARTI_DEMOCRATIQUE};
};

#endif // INSCRIPTIONCANDIDATINTERFACE_H
