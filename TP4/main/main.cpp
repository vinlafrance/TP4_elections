/**
* \file main.cpp
* \brief  Un programme interactif minimaliste qui obtient interactivement avec
* l’usager les données nécessaires pour créer une "Personne" puis qui modifie son adresse
* \author Vincent Lafrance
* \version 1.0
* \date 10/14/2020
*/
#include "Circonscription.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace util;
using namespace elections;

/* yoyo */

int main()
{
	cout << "--------------------------------------------" << endl;
	cout << "Bienvenue a l'outil d'ajout de gestion des listes électorales" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << "Inscription d'un candidat" << endl;
	string nas, prenom, nom, rue, ville, cPostal, province;
	long jour = -1;
	long mois = -1;
	long annee = -1;
	long noCivic = -1;
	long partiPolitique = -1;

	while(partiPolitique < 0 or partiPolitique > 4)
	{
		partiPolitique = saisiePartiPolitique(partiPolitique);
		if (partiPolitique < 0 or partiPolitique > 4)
		{
			cout << "Parti politique invalide.\n" << endl;
		}
	}
	while (!Date::validerDate(jour, mois, annee))
	{
		long *valeurs;
		valeurs = saisieDate();
		jour = *valeurs;
		mois = *(valeurs + 1);
		annee = *(valeurs + 2);
		if (!Date::validerDate(jour, mois, annee))
		{
			cout << "La date de naissance n'est pas valide.\n" << endl;
		}
	}
	while(true)
	{
		string *valeurs;
		valeurs = saisieAdresse();
		noCivic = stoi(*valeurs);
		rue = *(valeurs + 1);
		ville = *(valeurs + 2);
		cPostal = *(valeurs + 3);
		province = *(valeurs + 4);
		if (noCivic < 0 or rue.empty() or ville.empty() or cPostal.empty() or province.empty())
		{
			cout << "L'adresse entree n'est pas valide.\n" << endl;
			continue;
		}
		break;
	}
	while (nom.empty())
	{
		nom = saisieNom();
		if (nom.empty())
		{
			cout << "Le nom est vide.\n" << endl;
		}
	}
	while (prenom.empty())
	{
		prenom = saisiePrenom();
		if (prenom.empty())
		{
			cout << "Le prenom est vide.\n" << endl;
		}
	}
	while (!validerNas(nas))
	{
		nas = saisieNas();
		if (!validerNas(nas))
		{
			cout << "Nas invalide.\n" << endl;
		}
	}

	Candidat candidat(nas, prenom, nom, Date(jour, mois, annee), Adresse(noCivic, rue, ville, cPostal, province), partiPolitique);
	nas = "";
	prenom = "";
	nom = "";
	rue = "";
	ville = "";
	cPostal = "";
	province = "";
	jour = -1;
	mois = -1;
	annee = -1;
	noCivic = -1;
	partiPolitique = -1;
	while (!Date::validerDate(jour, mois, annee))
	{
		long *valeurs;
		valeurs = saisieDate();
		jour = *valeurs;
		mois = *(valeurs + 1);
		annee = *(valeurs + 2);
		if (!Date::validerDate(jour, mois, annee))
		{
			cout << "La date de naissance n'est pas valide.\n" << endl;
		}
	}
	while(true)
	{
		string *valeurs;
		valeurs = saisieAdresse();
		noCivic = stoi(*valeurs);
		rue = *(valeurs + 1);
		ville = *(valeurs + 2);
		cPostal = *(valeurs + 3);
		province = *(valeurs + 4);
		if (noCivic < 0 or rue.empty() or ville.empty() or cPostal.empty() or province.empty())
		{
			cout << "L'adresse entree n'est pas valide.\n" << endl;
			continue;
		}
		break;
	}
	while (nom.empty())
	{
		nom = saisieNom();
		if (nom.empty())
		{
			cout << "Le nom est vide.\n" << endl;
		}
	}
	while (prenom.empty())
	{
		prenom = saisiePrenom();
		if (prenom.empty())
		{
			cout << "Le prenom est vide.\n" << endl;
		}
	}
	while (!validerNas(nas))
	{
		nas = saisieNas();
		if (!validerNas(nas))
		{
			cout << "Nas invalide.\n" << endl;
		}
	}

	Electeur electeur(nas, prenom, nom, Date(jour, mois, annee), Adresse(noCivic, rue, ville, cPostal, province));

	Candidat deputeElu("046 454 286", "inconnu", "inconnu", Date(12, 5, 1979), Adresse(1, "rue inconnue", "inconnue", "G1V 0A7", "QC"), 2);
	Circonscription circonscription("Circonscription n0 1", deputeElu);
	circonscription.Circonscription::inscrire(candidat);
	circonscription.Circonscription::inscrire(electeur);

	cout << circonscription.reqCirconscriptionFormate() << endl;
	cout << "fin du programme";

	return 0;
}



