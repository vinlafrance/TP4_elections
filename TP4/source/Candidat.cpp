/*
 * Candidat.cpp
 *
 *  Created on: 2020-11-23
 *      Author: etudiant
 */
#include "Candidat.h"
#include <sstream>

using namespace std;

namespace elections
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Candidat à partir de valeurs passées en paramètres.
 * \param[in] p_nas est un string qui représente le numero d'assurance sociale
 * \param[in] p_prenom est un string qui représente le prenom
 * \param[in] p_nom est un string qui représente le nom
 * \param[in] p_dateNaissance est un string qui représente la date de naissance
 * \param[in] p_adresse est un string qui représente l'adresse
 * \param[in] p_partiPolitique est un int qui représente le parti politique
 */
Candidat::Candidat(const string& p_nas, const string& p_prenom, const string& p_nom,
		const util::Date& p_dateNaissance, const util::Adresse& p_adresse, int p_partiPolitique):
				Personne(p_nas,p_prenom,p_nom,p_dateNaissance,p_adresse), m_partiPolitique(p_partiPolitique)
{
	PRECONDITION(reqPartiPolitique() >= 0 and reqPartiPolitique() <= 4);
	POSTCONDITION (reqPartiPolitique() == p_partiPolitique);
	INVARIANTS();
}
/**
 * \brief retourne le parti politique
 * \return un int qui représente le parti politique
 */
int Candidat::reqPartiPolitique() const
{
	return m_partiPolitique;
}
/**
 * \brief retourne les informations de la personne
 * \return un string qui représente les informations de la personne
 */
string Candidat::reqPersonneFormate() const
{
	string parti;
	switch(m_partiPolitique)
	{
	case 0:
		parti = "BLOC_QUEBECOIS";
		break;
	case 1:
		parti = "CONSERVATEUR";
		break;
	case 2:
		parti = "INDEPENDANT";
		break;
	case 3:
		parti = "LIBERAL";
		break;
	case 4:
		parti = "NOUVEAU_PARTI_DEMOCRATIQUE";
		break;
	default:
		break;
	}
	ostringstream personneFormatee;

	personneFormatee << "\nCandidat\n----------------------------------------------\n" << Personne::reqPersonneFormate() <<
			"\nParti politique		: " << parti;
	return personneFormatee.str();
}
/**
 * \brief retourne un nouvel objet de la classe Candidat egale a celui utilise pour appeller la fonction
 * \return return un clone
 */
Personne* Candidat::clone() const
{
	return new Candidat(*this);
}
/**
 * \brief implante les invariants de la classe Candidat
 * \return rien
 */
void Candidat::verifieInvariant() const
{
	INVARIANT(reqPartiPolitique() >= 0 and reqPartiPolitique() <= 4);
}
}// namespace elections
