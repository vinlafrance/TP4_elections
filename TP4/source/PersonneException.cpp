/*
 * PersonneException.cpp
 *
 *  Created on: 2020-12-07
 *      Author: etudiant
 */
#include "PersonneException.h"

using namespace std;
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet PersonneException à partir de valeurs passées en paramètres.
 * \param[in] p_raison est un string qui représente la raison de l'exception
 */
PersonneException::PersonneException (const string& p_raison)
: runtime_error(p_raison)
{
}
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet PersonneDejaPresenteException à partir de valeurs passées en paramètres.
 * \param[in] p_raison est un string qui représente la raison de l'exception
 */
PersonneDejaPresenteException::PersonneDejaPresenteException (const string& p_raison)
: PersonneException(p_raison)
{
}
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet PersonneAbsenteException à partir de valeurs passées en paramètres.
 * \param[in] p_raison est un string qui représente la raison de l'exception
 */
PersonneAbsenteException::PersonneAbsenteException(const string& p_raison)
: PersonneException(p_raison)
{
}


