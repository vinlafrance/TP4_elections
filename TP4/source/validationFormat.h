/**
* \file validationFormat.h
* \brief Fichier qui contient l'interface des fonctions de validation du format d'une liste electorale
* \author Vincent Lafrance
* \version 1.0
* \date 10/14/2020
*/


#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

namespace util
{

bool validerNas(const std::string& p_nas);
bool validerFormatFichier(std::istream& p_is);
long saisiePartiPolitique(long partiPolitique);
long * saisieDate();
std::string * saisieAdresse();
std::string saisieNom();
std::string saisiePrenom();
std::string saisieNas();

} // namespace util

#endif /* VALIDATIONFORMAT_H_ */
