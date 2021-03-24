/*
 * Electeur.cpp
 *
 *  Created on: 2020-11-23
 *      Author: etudiant
 */

#include "Electeur.h"
#include <sstream>

using namespace std;

namespace elections
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Electeur à partir de valeurs passées en paramètres.
 * \param[in] p_nas est un string qui représente le numero d'assurance sociale
 * \param[in] p_prenom est un string qui représente le prenom
 * \param[in] p_nom est un string qui représente le nom
 * \param[in] p_dateNaissance est un string qui représente la date de naissance
 * \param[in] p_adresse est un string qui représente l'adresse
 */
Electeur::Electeur(const string& p_nas, const string& p_prenom, const string& p_nom,
		const util::Date& p_dateNaissance, const util::Adresse& p_adresse):
				Personne(p_nas,p_prenom,p_nom,p_dateNaissance,p_adresse)
{
	INVARIANTS();
}
/**
 * \brief retourne les informations de la personne
 * \return un string qui représente les informations de la personne
 */
string Electeur::reqPersonneFormate() const
{
	ostringstream personneFormatee;

	personneFormatee << "\nElecteur\n----------------------------------------------\n" << Personne::reqPersonneFormate();
	return personneFormatee.str();
}
/**
 * \brief retourne un nouvel objet de la classe Electeur egale a celui utilise pour appeller la fonction
 * \return return un clone
 */
Personne* Electeur::clone() const
{
	return new Electeur(*this);
}
void Electeur::verifieInvariant() const
{
}


}// namespace elections
