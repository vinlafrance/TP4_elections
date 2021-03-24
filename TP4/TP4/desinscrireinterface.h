#ifndef DESINSCRIREINTERFACE_H
#define DESINSCRIREINTERFACE_H

#include <QtGui/QDialog>
#include "ui_desinscrireinterface.h"

class desinscrireInterface : public QDialog
{
    Q_OBJECT

public:
	desinscrireInterface(QWidget *parent = 0);
    ~desinscrireInterface();
    QString reqNas() const;

private slots:
	void validerDesinscription();

private:
    Ui::desinscrireInterfaceClass ui;
};

#endif // DESINSCRIREINTERFACE_H

