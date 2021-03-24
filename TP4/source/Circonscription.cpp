/*
 * Circonscription.cpp
 *
 *  Created on: 2020-11-23
 *      Author: etudiant
 */

#include "Circonscription.h"
#include <sstream>

using namespace std;

namespace elections
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Circonscription à partir de valeurs passées en paramètres.
 * \param[in] p_nomCirconscription est un string qui représente le nom de la circonscription
 * \param[in] p_deputeElu est un Candidat qui représente le depute sortant
 */
Circonscription::Circonscription(const std::string& p_nomCirconscription, const Candidat& p_deputeElu):
		m_nomCirconscription(p_nomCirconscription), m_deputeElu(p_deputeElu)
{
	PRECONDITION(!reqNomCirconscription().empty());
	POSTCONDITION (reqNomCirconscription() == p_nomCirconscription);
	POSTCONDITION (reqDeputeElu() == p_deputeElu);
	INVARIANTS();
}
/**
 * \brief constructeur copie avec paramètres
 * 		  On construit une copie d'un objet Circonscription à partir de valeurs passées en paramètres.
 * \param[in] p_circonscription est une Circonscription qui représente la circonscription que l'on veut copier
 */
Circonscription::Circonscription(Circonscription const& p_circonscription): m_nomCirconscription(p_circonscription.m_nomCirconscription),
		m_deputeElu(p_circonscription.m_deputeElu)
{
	PRECONDITION(!reqNomCirconscription().empty());
	for (std::vector<Personne*>::const_iterator iter = p_circonscription.m_vInscrits.begin(); iter != p_circonscription.m_vInscrits.end(); iter++)
		{
			inscrire(*(*iter));
		}
	POSTCONDITION (reqNomCirconscription() == p_circonscription.m_nomCirconscription);
	POSTCONDITION (reqDeputeElu() == p_circonscription.m_deputeElu);
	POSTCONDITION (reqCirconscriptionFormate() == p_circonscription.reqCirconscriptionFormate());
	INVARIANTS();
}
/**
 * \brief destructeur
 * 		  On detruit chaque element pointes par le vecteur m_vInscrits puis on libere le vecteur
 */
Circonscription::~ Circonscription ()
{
	for (std::vector<Personne*>::const_iterator iter = m_vInscrits.begin(); iter != m_vInscrits.end(); iter++)
	{
		delete(*iter);
	}
	m_vInscrits.clear();
}
/**
 * \brief retourne le nom de la circonscription
 * \return un string qui représente le nom de la circonscription
 */
const string& Circonscription::reqNomCirconscription() const
{
	return m_nomCirconscription;
}
/**
 * \brief retourne le depute sortant
 * \return un string qui représente le depute sortant
 */
const Candidat& Circonscription::reqDeputeElu() const
{
	return m_deputeElu;
}
/**
 * \brief retourne les informations de la personne
 * \return un string qui représente les informations de la personne
 */
string Circonscription::reqCirconscriptionFormate() const
{
	ostringstream circonscriptionFormatee;

	circonscriptionFormatee << "\ncirconscription : " << m_nomCirconscription << "\nDepute sortant :"
			<< m_deputeElu.reqPersonneFormate() << "\n\nListe des inscrits :";
	for (std::vector<Personne*>::const_iterator iter = m_vInscrits.begin(); iter != m_vInscrits.end(); iter++)
	{
		circonscriptionFormatee << (*iter)->reqPersonneFormate() << "\n";
	}

	return circonscriptionFormatee.str();
}
/**
 * \brief inscrit un objet Candidat ou Electeur dans le vecteur d'un objet Circonscription
 * \throw une exception PersonneDejaPresenteException si l'objet est deja dans Circonscription
 */
void Circonscription::inscrire(const Personne& p_nouvelInscrit)
{
	if(personneEstDejaPresente(p_nouvelInscrit.reqNas()))
	{
		throw PersonneDejaPresenteException(p_nouvelInscrit.reqPersonneFormate());
	}
	unsigned int m_sizeAvant = m_vInscrits.size();
	m_vInscrits.push_back(p_nouvelInscrit.clone());
	POSTCONDITION (m_sizeAvant + 1 == m_vInscrits.size());
	INVARIANTS();
}
/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_circonscription qui est une circonscription valide
 * \return un booléen indiquant si les deux circonscriptions sont égales ou pas
 */
Circonscription& Circonscription::operator=(const Circonscription& p_circonscription)
{
	if (this != &p_circonscription)
	{
		m_nomCirconscription = p_circonscription.m_nomCirconscription;
		m_deputeElu = p_circonscription.m_deputeElu;
		for (std::vector<Personne*>::const_iterator iter = p_circonscription.m_vInscrits.begin(); iter != p_circonscription.m_vInscrits.end(); iter++)
		{
			delete(*iter);
		}
		m_vInscrits.clear();
		for (std::vector<Personne*>::const_iterator iter = p_circonscription.m_vInscrits.begin(); iter != p_circonscription.m_vInscrits.end(); iter++)
		{
			inscrire(*(*iter));
		}
	}
	POSTCONDITION (reqNomCirconscription() == p_circonscription.reqNomCirconscription());
	POSTCONDITION (reqDeputeElu() == p_circonscription.reqDeputeElu());
	POSTCONDITION (reqCirconscriptionFormate() == p_circonscription.reqCirconscriptionFormate());
	INVARIANTS();
	return *this;
}
/**
 * \brief retourne si le nas est deja dans la circonscription
 * \param[in] p_nas qui est un nas valide
 * \return un booléen indiquant si le nas est inscrit ou pas
 */
bool Circonscription::personneEstDejaPresente(const string& p_nas) const
{
	PRECONDITION(util::validerNas(p_nas));
	for (std::vector<Personne*>::const_iterator iter = m_vInscrits.begin(); iter != m_vInscrits.end(); iter++)
	{
		if (p_nas == (*iter)->reqNas())
		{
			return true;
		}
	}
	return false;
}
/**
 * \brief desinscrit une personne de la circonscription apartir d'un nas
 * \param[in] p_nas qui est un nas valide
 * \throw une exception PersonneAbsenteException si la personne n'est pas dans la circonscription
 */
void Circonscription::desinscrire(const std::string& p_nas)
{
	PRECONDITION(util::validerNas(p_nas));
	if(!personneEstDejaPresente(p_nas))
	{
		throw PersonneAbsenteException(reqCirconscriptionFormate());
	}
	bool desinscrit = false;
	for (std::vector<Personne*>::const_iterator iter = m_vInscrits.begin(); !desinscrit; iter++)
	{
		if (p_nas == (*iter)->reqNas())
		{
			delete(*iter);
			m_vInscrits.erase(iter);
			desinscrit = true;
		}
	}
	POSTCONDITION(!personneEstDejaPresente(p_nas));
	INVARIANTS();
}
/**
 * \brief implante les invariants de la classe Circonscription
 * \return rien
 */
void Circonscription::verifieInvariant() const
{
	INVARIANT(!reqNomCirconscription().empty());
}
}// namespace elections
