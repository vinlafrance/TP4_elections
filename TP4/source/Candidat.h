/*
 * Candidat.h
 *
 *  Created on: 2020-11-23
 *      Author: etudiant
 */

#ifndef CANDIDAT_H_
#define CANDIDAT_H_

#include "Personne.h"

namespace elections
{
/**
 * \class Candidat
 * \brief Cette classe sert au maintien et à la manipulation des candidats et herite de la classe Personne.
 *
 *              Cette classe peut aussi servir à prendre les informations d'un candidat et de donner
 *              une version formatee de maniere claire et consise.
 *              <p>
 *             Attributs:   int m_partiPolitique	entier representant le parti politique
 */
class Candidat:public Personne
{
public:
	Candidat(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
				const util::Date& p_dateNaissance, const util::Adresse& p_adresse, int p_partiPolitique);

	int reqPartiPolitique() const;
	virtual std::string reqPersonneFormate() const;
	virtual Personne* clone() const;

private:

	int m_partiPolitique;
	enum PartisPolitiques {BLOC_QUEBECOIS, CONSERVATEUR, INDEPENDANT, LIBERAL,
	NOUVEAU_PARTI_DEMOCRATIQUE};
	void verifieInvariant() const;
};

}// namespace elections



#endif /* CANDIDAT_H_ */
