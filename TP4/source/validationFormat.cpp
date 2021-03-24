/**
* \file validationFormat.cpp
* \brief Implantation des fonctions pour valider le format d'une liste electorale
* \author Vincent Lafrance
* \version 1.0
* \date 10/14/2020
*/

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <cctype>
#include <sstream>
#include <fstream>
#include "validationFormat.h"

using namespace std;

namespace util
{
const string& p_mult = "121 212 121";
string partis[5] = {"BLOC_QUEBECOIS",
		"CONSERVATEUR",
		"INDEPENDANT",
		"LIBERAL",
		"NOUVEAU_PARTI_DEMOCRATIQUE"};
/**
 * \brief Vérifie la validité d'un NAS
 * \param[in] p_nas un string représentant le numero d'assurance sociale
 * \return un booléen indiquant si le NAS est valide ou non
 */
bool validerNas(const std::string& p_nas)
{
	int res = 0;
	int tempInt1;
	int tempInt2;
	string tempStr;
	if (p_nas.size() == 11)
	{
		if (isspace(p_nas[3]) and isspace(p_nas[7]))
		{
			for (int i = 0; i < 11; i++)
			{
				if (isdigit(p_nas[i])){
					tempStr = p_nas[i];
					tempInt1 = stoi(tempStr);
					tempStr = p_mult[i];
					tempInt2 = stoi(tempStr);
					if (tempInt1*tempInt2 > 9)
					{
						res = res + (1 + (tempInt1 * tempInt2) % 10);
					}
					else
					{
						res = res + tempInt1 * tempInt2;
					}

				}
			}
			if (res % 10 == 0)
			{
				return true;
			}

		}
	}

	return false;
}
/**
 * \brief Vérifie la nature de la ligne de la fiche electorale
 * \param[in] p_type un string représentant la ligne de la fiche electorale
 * \return un entier int indiquant si la ligne contient un parti, un NAS valide, ou aucun des deux
 */
int validerParti(const std::string& p_type)
{
	for (int i=0;i<5;i++)
		{
			if (p_type == partis[i])
			{
				return 1;
			}
			else if (validerNas(p_type))
			{
				return 2;
			}
		}
	return 0;
}
/**
 * \brief Vérifie la validité du format d'une fiche electorale
 * \param[in] p_is un objet istream représentant le fichier contenant la fiche electorale
 * \return un booléen indiquant si le format du fichier est valide ou non
 */
bool validerFormatFichier(std::istream& p_is)
{
	char buffer[256];
	p_is.getline(buffer, 256);
	if (strcmp(buffer, "") != 0)
	{
		while(p_is.getline(buffer, 256))
		{
			if (validerParti(buffer) == 1)
			{
				p_is.getline(buffer, 256);
				if (validerNas(buffer))
				{
					p_is.getline(buffer, 256);
					if (strcmp(buffer, "") != 0)
					{
						p_is.getline(buffer, 256);
						if (strcmp(buffer, "") != 0)
						{
							p_is.getline(buffer, 256);
							if (isspace(buffer[2]) and isspace(buffer[5]))
							{
								p_is.getline(buffer, 256);
								if (strcmp(buffer, "") != 0)
								{
									continue;
								}
								else
								{
								return false;
								}
							}
							else
							{
							return false;
							}
						}
						else
						{
						return false;
						}
					}
					else
					{
					return false;
					}
				}
				else
				{
				return false;
				}
			}
			else if (validerParti(buffer) == 2)
			{
				p_is.getline(buffer, 256);
				if (strcmp(buffer, "") != 0)
				{
					p_is.getline(buffer, 256);
					if (strcmp(buffer, "") != 0)
					{
						p_is.getline(buffer, 256);
						if (isspace(buffer[2]) and isspace(buffer[5]))
						{
							p_is.getline(buffer, 256);
							if (strcmp(buffer, "") != 0)
							{
								continue;
							}
							else
							{
							return false;
							}
						}
						else
						{
						return false;
						}
					}
					else
					{
					return false;
					}
				}
				else
				{
				return false;
				}
			}
			else
			{
			return false;
			}
		}
		return true;
	}
	else
	{
	return false;
	}
}
long saisiePartiPolitique(long p_partiPolitique)
{
	char buffer[256];
	cout << "Choisissez un parti:" << endl;
	cout << "0:BLOC_QUEBECOIS, 1:CONSERVATEUR,2:INDEPENDANT,3:LIBERAL,4:NOUVEAU_PARTI_DEMOCRATIQUE" << endl;
	cin.getline(buffer, 256);
	return stoi(buffer);
}
long * saisieDate()
{
	char buffer[256];
	static long valeurs[3];
	cout << "\nVeuillez entrer sa date de naissance." << endl;;

	cout << "Le jour [1..31]: ";
	cin.getline(buffer, 256);
	valeurs[0] = stoi(buffer);

	cout << "Le mois [1..12]: ";
	cin.getline(buffer, 256);
	valeurs[1] = stoi(buffer);

	cout << "L'annee [1970..2037]: ";
	cin.getline(buffer, 256);
	valeurs[2] = stoi(buffer);

	return valeurs;
}
string * saisieAdresse()
{
	char buffer[256];
	static string valeurs[5];

	cout << "No de rue : ";
	cin.getline(buffer, 256);
	valeurs[0] = buffer;

	cout << "Rue : ";
	cin.getline(buffer,256);
	valeurs[1] = buffer;

	cout << "Ville : ";
	cin.getline(buffer, 256);
	valeurs[2] = buffer;

	cout << "Code postal : ";
	cin.getline(buffer, 256);
	valeurs[3] = buffer;

	cout << "Province : ";
	cin.getline(buffer, 256);
	valeurs[4] = buffer;

	return valeurs;
}
string saisieNom()
{
	char buffer[256];
	cout << "Entrez le nom : ";
	cin.getline(buffer, 256);
	return buffer;
}
string saisiePrenom()
{
	char buffer[256];
	cout << "Entrez le prenom : ";
	cin.getline(buffer, 256);
	return buffer;
}
string saisieNas()
{
	char buffer[256];
	cout << "Entrez le numéro d’assurance sociale : ";
	cin.getline(buffer, 256);
	return buffer;
}
} // namespace util



