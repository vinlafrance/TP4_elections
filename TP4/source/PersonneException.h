/*
 * PersonneException.h
 *
 *  Created on: 2020-12-07
 *      Author: etudiant
 */

#ifndef PERSONNEEXCEPTION_H_
#define PERSONNEEXCEPTION_H_

#include <stdexcept>
#include <string>
/**
 * \class PersonneException
 * \brief Cette classe sert a creer des exceptions de type PersonneException et herite de runtime_error.
 */
class PersonneException: public std::runtime_error
{
public:
	PersonneException (const std::string& p_raison);
};
/**
 * \class PersonneDejaPresenteException
 * \brief Cette classe sert a creer des exceptions de type PersonneException et herite de PersonneException.
 */
class PersonneDejaPresenteException : public PersonneException
{
public:
	PersonneDejaPresenteException (const std::string& p_raison);
};
/**
 * \class PersonneAbsenteException
 * \brief Cette classe sert a creer des exceptions de type PersonneException et herite de PersonneException.
 */
class PersonneAbsenteException : public PersonneException
{
public:
	PersonneAbsenteException(const std::string& p_raison);
};


#endif /* PERSONNEEXCEPTION_H_ */
