/**
* \file Personne.cpp
* \brief Implantation de la classe Personne
* \author Vincent Lafrance
* \version 1.0
* \date 10/14/2020
*/

#include "Personne.h"
#include <sstream>

using namespace std;


namespace elections
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Personne à partir de valeurs passées en paramètres.
 * \param[in] p_nas est un string qui représente le numero d'assurance sociale
 * \param[in] p_prenom est un string qui représente le prenom
 * \param[in] p_nom est un string qui représente le nom
 * \param[in] p_dateNaissance est un string qui représente la date de naissance
 * \param[in] p_adresse est un string qui représente l'adresse
 */
Personne::Personne(const string& p_nas, const string& p_prenom, const string& p_nom,
		const util::Date& p_dateNaissance, const util::Adresse& p_adresse): m_nas(p_nas),
				m_prenom(p_prenom), m_nom(p_nom), m_dateNaissance(p_dateNaissance), m_adresse(p_adresse)
{
	PRECONDITION (util::validerNas(p_nas));
	PRECONDITION (!p_prenom.empty());
	PRECONDITION (!p_nom.empty());

	POSTCONDITION (reqNas() == p_nas);
	POSTCONDITION (reqPrenom() == p_prenom);
	POSTCONDITION (reqNom() == p_nom);
	POSTCONDITION (reqDateNaissance() == p_dateNaissance);
	POSTCONDITION (reqAdresse() == p_adresse);
	INVARIANTS();
}
/**
 * \brief destructeur
 * 		  On detruit une personne
 */
Personne::~Personne()
{
}
/**
 * \brief Assigne une adresse à l'objet courant
 * \param[in] p_numeroCivic est un int qui représente le numero de rue
 * \param[in] p_nomRue est un string qui représente le nom de la rue
 * \param[in] p_ville est un string qui représente le nom de la ville
 * \param[in] p_codePostal est un string qui représente le code postal
 * \param[in] p_province est un string qui représente la province
 */
void Personne::asgAdresse(const util::Adresse& p_adresse)
{
	m_adresse = p_adresse;
	POSTCONDITION (reqAdresse() == p_adresse);
	INVARIANTS();
}
/**
 * \brief retourne le NAS
 * \return un string qui représente le NAS
 */
const string& Personne::reqNas() const
{
	return m_nas;
}
/**
 * \brief retourne le prenom
 * \return un string qui représente le prenom
 */
const string& Personne::reqPrenom() const
{
	return m_prenom;
}
/**
 * \brief retourne le nom
 * \return un string qui représente lenom
 */
const string& Personne::reqNom() const
{
	return m_nom;
}
/**
 * \brief retourne la date de naissance
 * \return un objet date qui représente la date de naissance
 */
const util::Date& Personne::reqDateNaissance() const
{
	return m_dateNaissance;
}
/**
 * \brief retourne l'adresse
 * \return un objet adresse qui représente l'adresse
 */
const util::Adresse& Personne::reqAdresse() const
{
	return m_adresse;
}
/**
 * \brief retourne les informations de la personne
 * \return un string qui représente les informations de la personne
 */
string Personne::reqPersonneFormate() const
{
	ostringstream personneFormatee;

	personneFormatee << "NAS			: " << m_nas << "\nPrenom			: " <<
			m_prenom << "\nNom			: " << m_nom << "\nDate de naissance	: " <<
			m_dateNaissance.reqDateFormatee() << "\nAdresse			: "
			<< m_adresse.reqAdresseFormate();
	return personneFormatee.str();
}
/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_personne qui est une personne valide
 * \return un booléen indiquant si les deux personnes sont égales ou pas
 */
bool Personne::operator==(const Personne& p_personne) const
{
	return (m_nas == p_personne.m_nas and m_prenom == p_personne.m_prenom and
			m_nom == p_personne.m_nom and m_dateNaissance == p_personne.m_dateNaissance and
			m_adresse == p_personne.m_adresse);
}
/**
 * \brief implante les invariants de la classe Personne
 * \return rien
 */
void Personne::verifieInvariant() const
{
	INVARIANT(util::validerNas(reqNas()));
	INVARIANT(!reqPrenom().empty());
	INVARIANT(!reqNom().empty());
}
} // namespace elections




