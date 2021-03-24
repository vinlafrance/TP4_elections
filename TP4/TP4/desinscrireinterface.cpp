#include "desinscrireinterface.h"
#include "validationFormat.h"
#include <string>
#include <iostream>
#include <sstream>
#include <QMessageBox>

desinscrireInterface::desinscrireInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(validerDesinscription()));
}

desinscrireInterface::~desinscrireInterface()
{

}
QString desinscrireInterface::reqNas() const{
	return ui.lineEdit->text();
}

void desinscrireInterface::validerDesinscription(){
	std::string nas = ui.lineEdit->text().toStdString();
	if (!util::validerNas(nas)){
		QString message("Le nas doit etre valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}else{
		accept();
	}
}
