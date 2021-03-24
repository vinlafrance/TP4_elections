/**
* \file Adresse.h
* \brief ichier qui contient l'interface de la classe Adresse qui sert au maintien et à la manipulation des adresses.
* \author Vincent Lafrance
* \version 1.0
* \date 10/14/2020
*/


#ifndef ADRESSE_H_
#define ADRESSE_H_
#include <string>
#include "ContratException.h"

namespace util
{
/**
 * \class Adresse
 * \brief Cette classe sert au maintien et à la manipulation des adresses.
 *
 *              Cette classe peut aussi servir à prendre les informations d'une adresse et de donner
 *              une version formatee de maniere claire et consise.
 *              <p>
 *             Attributs:   int m_numeroCivic  		Numero de rue
 *             				string m_nomRue			Nom de la rue
 *             				string m_ville			Nom de la ville
 *             				string m_codePostal		Objet de la classe string contenant le code postal
 *             				string m_province		Objet de la classe string contenant la province
*/
class Adresse
{
public:
	Adresse(int p_numeroCivic, const std::string& p_nomRue, const std::string& p_ville,
			const std::string& p_codePostal, const std::string& p_province);
	void asgAdresse(int p_numeroCivic, const std::string& p_nomRue, const std::string& p_ville,
			const std::string& p_codePostal, const std::string& p_province);

	int reqNumeroCivic() const;
	const std::string& reqNomRue() const;
	const std::string& reqVille() const;
	const std::string& reqCodePostal() const;
	const std::string& reqProvince() const;

	bool operator== (const Adresse& p_adresse) const;

	std::string reqAdresseFormate() const;


private:

	int m_numeroCivic;
	std::string m_nomRue;
	std::string m_ville;
	std::string m_codePostal;
	std::string m_province;
	void verifieInvariant() const;

};


} // namespace util


#endif /* ADRESSE_H_ */
