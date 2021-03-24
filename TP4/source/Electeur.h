/*
 * Electeur.h
 *
 *  Created on: 2020-11-23
 *      Author: etudiant
 */

#ifndef ELECTEUR_H_
#define ELECTEUR_H_

#include "Personne.h"

namespace elections
{
/**
 * \class Personne
 * \brief Cette classe sert au maintien et à la manipulation des electeurs et herite de la classe Personne.
 *
 *              Cette classe peut aussi servir à prendre les informations d'un electeur et de donner
 *              une version formatee de maniere claire et consise.
 *              <p>
 *             Attributs:   aucuns
 */
class Electeur: public Personne
{
public:

	Electeur(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
					const util::Date& p_dateNaissance, const util::Adresse& p_adresse);
	virtual std::string reqPersonneFormate() const;
	virtual Personne* clone() const;

private:
	void verifieInvariant() const;
};




}// namespace elections



#endif /* ELECTEUR_H_ */
