/**
* \file Personne.h
* \brief Fichier qui contient l'interface de la classe Personne qui sert au maintien et à la manipulation des personnes.
* \author Vincent Lafrance
* \version 1.0
* \date 10/14/2020
*/

#ifndef PERSONNE_H_
#define PERSONNE_H_
#include "Date.h"
#include "Adresse.h"
#include "validationFormat.h"


namespace elections
{
/**
 * \class Personne
 * \brief Cette classe sert au maintien et à la manipulation des personnes.
 *
 *              Cette classe peut aussi servir à prendre les informations d'une personne et de donner
 *              une version formatee de maniere claire et consise.
 *              <p>
 *             Attributs:   string m_nas   			Numero d'assurance sociale de la personne
 *             				string m_prenom			Prenom de la personne
 *             				string m_nom			Nom de la personne
 *             				Date m_dateNaissance	Objet de la classe Date contenant la date de naissance de la personne
 *             				Adresse m_adresse		Objet de la classe Adresse contenant l'Adresse de la personne
 */
class Personne
{
public:
	Personne(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
			const util::Date& p_dateNaissance, const util::Adresse& p_adresse);
	virtual ~Personne();
	virtual Personne* clone() const = 0;
	void asgAdresse(const util::Adresse& p_adresse);

	const std::string& reqNas() const;
	const std::string& reqPrenom() const;
	const std::string& reqNom() const;
	const util::Date& reqDateNaissance() const;
	const util::Adresse& reqAdresse() const;

	virtual std::string reqPersonneFormate() const = 0;

	bool operator==(const Personne& p_personne) const;

private:

	std::string m_nas;
	std::string m_prenom;
	std::string m_nom;
	util::Date m_dateNaissance;
	util::Adresse m_adresse;
	void verifieInvariant() const;
};


} // namespace elections




#endif /* PERSONNE_H_ */
