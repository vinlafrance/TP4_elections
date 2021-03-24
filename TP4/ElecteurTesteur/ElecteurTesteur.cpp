/**
 * \file ElecteurTesteur.cpp
 * \brief Testeur de la classe Electeur
 * \author etudiant
 * \version 1.0
 * \date 2020-11-25
 *  A tester:
 *         Electeur(const string& p_nas, const string& p_prenom, const string& p_nom, const util::Date& p_dateNaissance, const util::Adresse& p_adresse);
 *         string reqPersonneFormate() const;
 *         Personne* clone() const;
 */
#include <gtest/gtest.h>
#include <sstream>

#include "Electeur.h"

using namespace elections;
using namespace util;

/**
 * \brief Test du constructeur Electeur(const string& p_nas, const string& p_prenom,
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
TEST(Electeur, ConstructeurElecteurValide)
{
	Electeur unElecteur("000 000 000", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"));
	ASSERT_EQ("000 000 000", unElecteur.reqNas());
	ASSERT_EQ("prenom", unElecteur.reqPrenom());
	ASSERT_EQ("nom", unElecteur.reqNom());
	ASSERT_EQ(Date(01, 01, 2000), unElecteur.reqDateNaissance());
	ASSERT_EQ(Adresse(1, "rue", "ville", "cp", "province"), unElecteur.reqAdresse());
}
TEST(Electeur, ConstructeurNasInvalide)
{
	ASSERT_THROW(Electeur unElecteur("123 456 789", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province")),ContratException)
	      << "Un electeur ne doit pas accepter de nas invalide";
}
TEST(Electeur, ConstructeurPrenomInvalide)
{
	ASSERT_THROW(Electeur unElecteur("000 000 000", "", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province")),ContratException)
	      << "Un electeur ne doit pas accepter de prenom vide";
}
TEST(Electeur, ConstructeurNomInvalide)
{
	ASSERT_THROW(Electeur unElecteur("000 000 000", "prenom", "", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province")),ContratException)
	      << "Un electeur ne doit pas accepter de nom vide";
}
TEST(Electeur, ConstructeurDateInvalide)
{
	ASSERT_THROW(Electeur unElecteur("000 000 000", "prenom", "nom", Date(42, 01, 2000), Adresse(1, "rue", "ville", "cp", "province")),ContratException)
	      << "Un electeur ne doit pas accepter de date invalide";
}
TEST(Electeur, ConstructeurAdresseInvalide)
{
	ASSERT_THROW(Electeur unElecteur("000 000 000", "prenom", "nom", Date(01, 01, 2000), Adresse(-1, "rue", "ville", "cp", "province")),ContratException)
	      << "Un electeur ne doit pas accepter d'adresse invalide";
}
/**
 * \brief Test fixture pour les méthodes de la classe Electeur.
 */
class ElecteurValide: public ::testing::Test
{
public:
	ElecteurValide() :
		ElecteurVal("000 000 000", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"))
    {
	}
	Electeur ElecteurVal;
};
/**
 * \brief Test de la méthode string reqPersonneFormate() const.
 *     Cas valide: verifier le retour de la personne formatee.
 *     Cas invalide: aucun.
 */
TEST_F(ElecteurValide, reqPersonneFormate)
{
	std::ostringstream os;
	os << "\nElecteur"
			<< "\n----------------------------------------------"
			<< "\nNAS			: 000 000 000"
			<< "\nPrenom			: prenom"
			<< "\nNom			: nom"
			<< "\nDate de naissance	: Samedi le 01 janvier 2000"
			<< "\nAdresse			: 1, rue, ville, cp, province";
	ASSERT_EQ(os.str(), ElecteurVal.reqPersonneFormate());
}
/**
 * \brief Test de la méthode Personne* clone() const.
 *     Cas valide: vérifier si le clone est egale.
 *     Cas invalide: aucun.
 */
TEST_F(ElecteurValide, clone)
{
	ASSERT_EQ(ElecteurVal,*ElecteurVal.clone());
}
