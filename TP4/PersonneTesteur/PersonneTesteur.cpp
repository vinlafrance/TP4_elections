/**
 * \file PersonneTesteur.cpp
 * \brief Testeur de la classe Personne
 * \author etudiant
 * \version 1.0
 * \date 2020-11-25
 *  A tester:
 *         Personne(const string& p_nas, const string& p_prenom, const string& p_nom,
 *         const util::Date& p_dateNaissance, const util::Adresse& p_adresse)
 *         void asgAdresse(const util::Adresse& p_adresse);
 *         const string& reqNas() const;
 *         const string& reqPrenom() const;
 *         const string& reqNom() const;
 *         const Date& reqDateNaissance() const;
 *         const Adresse& reqAdresse() const;
 *         string reqPersonneFormate() const;
 *         bool operator==(const Personne& p_personne) const;
 */
#include <gtest/gtest.h>
#include <sstream>

#include "Personne.h"

using namespace elections;
using namespace util;
using namespace std;

/**
 * \class PersonneDeTest
 * \brief classe de test permettant de tester la classe abstraite Personne
 */
class PersonneDeTest: public Personne
{
public:
	PersonneDeTest(const string& p_nas, const string& p_prenom, const string& p_nom,
			const Date& p_dateNaissance, const Adresse& p_adresse) :
		Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse)
	{
	}
	;
	virtual Personne* clone() const
	{
		return 0;
	}
	;
	virtual std::string reqPersonneFormate() const
	{
		return Personne::reqPersonneFormate();
	}
	;
};

/**
 * \class UnePersonne
 * \brief Fixture  UnePersonne pour la création d'un objet Personne pour les tests
 */
class UnePersonne: public ::testing::Test
{
public:
	UnePersonne() :
		t_personne("000 000 000", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"))
	{
	}
	;

	PersonneDeTest t_personne;
};

/**
 * \brief Test du constructeur Personne(const string& p_nas, const string& p_prenom,
 * 										const string& p_nom, const util::Date& p_dateNaissance, const util::Adresse& p_adresse);
 *
 *     Cas valide: 		nas doit etre valide;
 *     					prenom ne doit pas etre vide;
 *     					nom ne doit pas etre vide;
 *     					dateNaissance doit etre valide;
 *     					adresse doit etre valide.
 *
 *     Cas invalide:	nas est invalide;
 *     					prenom est vide;
 *     					nom est vide;
 *     					dateNaissance est invalide;
 *     					adresse est invalide.
 */
TEST(Personne, ConstructeurPersonneValide)
{
	PersonneDeTest unePersonne("000 000 000", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"));
	ASSERT_EQ("000 000 000", unePersonne.reqNas());
	ASSERT_EQ("prenom", unePersonne.reqPrenom());
	ASSERT_EQ("nom", unePersonne.reqNom());
	ASSERT_EQ(Date(01, 01, 2000), unePersonne.reqDateNaissance());
	ASSERT_EQ(Adresse(1, "rue", "ville", "cp", "province"), unePersonne.reqAdresse());
}
TEST(Personne, ConstructeurNasInvalide)
{
	ASSERT_THROW(PersonneDeTest unePersonne("123 456 789", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province")),ContratException)
	      << "Une personne ne doit pas accepter de nas invalide";
}
TEST(Personne, ConstructeurPrenomInvalide)
{
	ASSERT_THROW(PersonneDeTest unePersonne("000 000 000", "", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province")),ContratException)
	      << "Une personne ne doit pas accepter de prenom vide";
}
TEST(Personne, ConstructeurNomInvalide)
{
	ASSERT_THROW(PersonneDeTest unePersonne("000 000 000", "prenom", "", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province")),ContratException)
	      << "Une personne ne doit pas accepter de nom vide";
}
TEST(Personne, ConstructeurDateInvalide)
{
	ASSERT_THROW(PersonneDeTest unePersonne("000 000 000", "prenom", "nom", Date(42, 01, 2000), Adresse(1, "rue", "ville", "cp", "province")),ContratException)
	      << "Une personne ne doit pas accepter de date invalide";
}
TEST(Personne, ConstructeurAdresseInvalide)
{
	ASSERT_THROW(PersonneDeTest unePersonne("000 000 000", "prenom", "nom", Date(01, 01, 2000), Adresse(-1, "rue", "ville", "cp", "province")),ContratException)
	      << "Une personne ne doit pas accepter d'adresse invalide";
}
/**
 * \brief Test de la méthode void asgAdresse(const util::Adresse& p_adresse).
 *
 *     Cas valide: 		nouvelle adresse doit etre valide.
 *
 *     Cas invalide:	nouvelle adresse est invalide.
 */
TEST_F(UnePersonne,asgAdresseValide)
{
	t_personne.asgAdresse(Adresse(2, "newRue", "newVille", "newCp", "newProvince"));
	ASSERT_EQ(Adresse(2, "newRue", "newVille", "newCp", "newProvince"), t_personne.reqAdresse());
}
TEST_F(UnePersonne,asgAdresseInvalide)
{
	ASSERT_THROW(t_personne.asgAdresse(Adresse(-2, "newRue", "newVille", "newCp", "newProvince")),ContratException)
          << "Une personne ne doit pas accepter d'adresse invalide";
}
/**
 * \brief Test de la méthode const string& reqNas() const.
 *
 *     Cas valide: 		verifier le retour du nas.
 *
 *     Cas invalide:	aucun.
 */
TEST_F(UnePersonne,reqNas)
{
	ASSERT_EQ("000 000 000", t_personne.reqNas());
}
/**
 * \brief Test de la méthode const string& reqPrenom() const.
 *
 *     Cas valide: 		verifier le retour du prenom.
 *
 *     Cas invalide:	aucun.
 */
TEST_F(UnePersonne,reqPrenom)
{
	ASSERT_EQ("prenom", t_personne.reqPrenom());
}
/**
 * \brief Test de la méthode const string& reqNom() const.
 *
 *     Cas valide: 		verifier le retour du nom.
 *
 *     Cas invalide:	aucun.
 */
TEST_F(UnePersonne,reqNom)
{
	ASSERT_EQ("nom", t_personne.reqNom());
}
/**
 * \brief Test de la méthode const Date& reqDateNaissance() const.
 *
 *     Cas valide: 		verifier le retour de la date de naissance.
 *
 *     Cas invalide:	aucun.
 */
TEST_F(UnePersonne,reqDateNaissance)
{
	ASSERT_EQ(Date(01, 01, 2000), t_personne.reqDateNaissance());
}
/**
 * \brief Test de la méthode const Adresse& reqAdresse() const.
 *
 *     Cas valide: 		verifier le retour de l'adresse.
 *
 *     Cas invalide:	aucun.
 */
TEST_F(UnePersonne,reqAdresse)
{
	ASSERT_EQ(Adresse(1, "rue", "ville", "cp", "province"), t_personne.reqAdresse());
}
/**
 * \brief Test de la méthode string reqPersonneFormate() const.
 *
 *     Cas valide: 		verifier le retour de la personne formatee.
 *
 *     Cas invalide:	aucun.
 */
TEST_F(UnePersonne,reqPersonneFormate)
{
	std::ostringstream os;
	os << "NAS			: 000 000 000"
			<< "\nPrenom			: prenom"
			<< "\nNom			: nom"
			<< "\nDate de naissance	: Samedi le 01 janvier 2000"
			<< "\nAdresse			: 1, rue, ville, cp, province";
	ASSERT_EQ(os.str(), t_personne.reqPersonneFormate());
}
/**
 * \brief Test de la méthode bool operator==(const Personne& p_personne) const.
 *
 *     Cas valide: 		verifier le retour de l'adresse.
 *
 *     Cas invalide:	aucun.
 */
TEST_F(UnePersonne,operatorEgalite)
{
	ASSERT_EQ(true, t_personne.reqNas() == t_personne.reqNas() and t_personne.reqPrenom() == t_personne.reqPrenom() and
			t_personne.reqDateNaissance() == t_personne.reqDateNaissance() and t_personne.reqAdresse() == t_personne.reqAdresse());
}
