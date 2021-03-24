/*
 * Circonscription.h
 *
 *  Created on: 2020-11-23
 *      Author: etudiant
 */

#ifndef CIRCONSCRIPTION_H_
#define CIRCONSCRIPTION_H_

#include "Personne.h"
#include "Candidat.h"
#include "Electeur.h"
#include "ContratException.h"
#include "PersonneException.h"
#include <vector>

namespace elections
{
/**
 * \class Circonscription
 * \brief Cette classe sert au maintien et à la manipulation des circonscriptions.
 *
 *              Cette classe peut aussi servir à prendre les informations d'une circonscription et de donner
 *              une version formatee de maniere claire et consise.
 *              <p>
 *             Attributs:   string m_nomCirconscription   	Objet de la classe string representant le nom de la circonscription
 *             				Candidat m_deputeElu			Objet de la classe Candidat representant le depute sortant
 */
class Circonscription
{
public:

	Circonscription(const std::string& p_nomCirconscription, const Candidat& p_deputeElu);
	Circonscription(Circonscription const& p_circonscription);
	std::string reqCirconscriptionFormate() const;

	~ Circonscription ();

	const std::string& reqNomCirconscription() const;
	const Candidat& reqDeputeElu() const;

	void inscrire(const Personne& p_nouvelInscrit);
	void desinscrire(const std::string& p_nas);

	Circonscription& operator=(const Circonscription& p_circonscription);

private:

	std::string m_nomCirconscription;
	Candidat m_deputeElu;
	std::vector<Personne*> m_vInscrits;
	void verifieInvariant() const;
	bool personneEstDejaPresente(const std::string& p_nas) const;
};





}// namespace elections



#endif /* CIRCONSCRIPTION_H_ */
