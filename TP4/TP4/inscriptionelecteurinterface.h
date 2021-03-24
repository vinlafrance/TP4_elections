#ifndef INSCRIPTIONELECTEURINTERFACE_H
#define INSCRIPTIONELECTEURINTERFACE_H

#include <QtGui/QDialog>
#include "ui_inscriptionelecteurinterface.h"
#include "Date.h"

class inscriptionElecteurInterface : public QDialog
{
    Q_OBJECT

public:
    inscriptionElecteurInterface(QWidget *parent = 0);
    ~inscriptionElecteurInterface();
    QString reqNas() const;
	QString reqNom() const;
	QString reqPrenom() const;
	util::Date reqDateNaissance() const;
	int reqNumeroCivic() const;
	QString reqNomRue() const;
	QString reqVille() const;
	QString reqCodePostal() const;
	QString reqProvince() const;


private slots:
	void validerInscription();

private:
    Ui::inscriptionElecteurInterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // INSCRIPTIONELECTEURINTERFACE_H
