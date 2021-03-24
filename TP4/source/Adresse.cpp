/**
* \file Adresse.cpp
* \brief Implantation de la classe Adresse
* \author Vincent Lafrance
* \version 1.0
* \date 10/14/2020
*/
/**/

#include "Adresse.h"
#include <sstream>

using namespace std;

namespace util
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Adresse à partir de valeurs passées en paramètres.
 * \param[in] p_numeroCivic est un int qui représente le numero de rue
 * \param[in] p_nomRue est un string qui représente le nom de la rue
 * \param[in] p_ville est un string qui représente le nom de la ville
 * \param[in] p_codePostal est un string qui représente le code postal
 * \param[in] p_province est un string qui représente la province
 */
Adresse::Adresse(int p_numeroCivic, const string& p_nomRue, const string& p_ville, const string& p_codePostal, const string& p_province)
: m_numeroCivic(p_numeroCivic), m_nomRue(p_nomRue), m_ville(p_ville), m_codePostal(p_codePostal), m_province(p_province)
{
	PRECONDITION(p_numeroCivic > 0);
	PRECONDITION(!p_nomRue.empty());
	PRECONDITION(!p_ville.empty());
	PRECONDITION(!p_codePostal.empty());
	PRECONDITION(!p_province.empty());

	POSTCONDITION(reqNumeroCivic() == p_numeroCivic);
	POSTCONDITION(reqNomRue() == p_nomRue);
	POSTCONDITION(reqVille() == p_ville);
	POSTCONDITION(reqCodePostal() == p_codePostal);
	POSTCONDITION(reqProvince() == p_province);

	INVARIANTS();
}
/**
 * \brief Assigne une adresse à l'objet courant
 * \param[in] p_numeroCivic est un int qui représente le numero de rue
 * \param[in] p_nomRue est un string qui représente le nom de la rue
 * \param[in] p_ville est un string qui représente le nom de la ville
 * \param[in] p_codePostal est un string qui représente le code postal
 * \param[in] p_province est un string qui représente la province
 */
void Adresse::asgAdresse(int p_numeroCivic, const string& p_nomRue, const string& p_ville, const string& p_codePostal, const string& p_province)
{
	PRECONDITION(p_numeroCivic > 0);
	PRECONDITION(!p_nomRue.empty());
	PRECONDITION(!p_ville.empty());
	PRECONDITION(!p_codePostal.empty());
	PRECONDITION(!p_province.empty());

	m_numeroCivic = p_numeroCivic;
	m_nomRue = p_nomRue;
	m_ville = p_ville;
	m_codePostal = p_codePostal;
	m_province = p_province;

	POSTCONDITION(reqNumeroCivic() == p_numeroCivic);
	POSTCONDITION(reqNomRue() == p_nomRue);
	POSTCONDITION(reqVille() == p_ville);
	POSTCONDITION(reqCodePostal() == p_codePostal);
	POSTCONDITION(reqProvince() == p_province);

	INVARIANTS();

}
/**
 * \brief retourne le numero de rue
 * \return un int qui représente le numero de rue
 */
int Adresse::reqNumeroCivic() const
{
	return m_numeroCivic;
}
/**
 * \brief retourne le nom de rue
 * \return un string qui représente le nom de rue
 */
const string& Adresse::reqNomRue() const
{
	return m_nomRue;
}
/**
 * \brief retourne le nom de la ville
 * \return un string qui représente le nom de la ville
 */
const string& Adresse::reqVille() const
{
	return m_ville;
}
/**
 * \brief retourne le code postal
 * \return un string qui représente le code postal
 */
const string& Adresse::reqCodePostal() const
{
	return m_codePostal;
}
/**
 * \brief retourne la province
 * \return un string qui représente la province
 */
const string& Adresse::reqProvince() const
{
	return m_province;
}
/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_adresse qui est une adresse valide
 * \return un booléen indiquant si les deux adresses sont égales ou pas
 */
bool Adresse::operator==(const Adresse& p_adresse) const
{
	return (m_numeroCivic == p_adresse.m_numeroCivic and m_nomRue == p_adresse.m_nomRue and
			m_ville == p_adresse.m_ville and m_codePostal == p_adresse.m_codePostal and
			m_province == p_adresse.m_province);
}
/**
 * \brief retourne les informations de l'adresse
 * \return un string qui représente les informations de l'adresse
 */
string Adresse::reqAdresseFormate() const
{
	ostringstream adresseFormatee;

	adresseFormatee << m_numeroCivic << ", " << m_nomRue << ", " <<
			m_ville << ", " << m_codePostal << ", " << m_province;
	return adresseFormatee.str();
}
/**
 * \brief implante les invariants de la classe Adresse
 * \return rien
 */
void Adresse::verifieInvariant() const
{
	INVARIANT(reqNumeroCivic() > 0);
	INVARIANT(!reqNomRue().empty());
	INVARIANT(!reqVille().empty());
	INVARIANT(!reqCodePostal().empty());
	INVARIANT(!reqProvince().empty());
}
} // namespace util


