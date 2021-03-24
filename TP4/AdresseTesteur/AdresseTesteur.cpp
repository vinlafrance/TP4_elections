/**
 * \file AdresseTesteur.cpp
 * \brief Testeur de la classe Adresse
 * \author etudiant
 * \version 1.0
 * \date 2020-11-24
 *  A tester:
 *         Adresse(int p_numeroCivic, const string& p_nomRue, const string& p_ville, const string& p_codePostal, const string& p_province);
 *         void asgAdresse(int p_numeroCivic, const string& p_nomRue, const string& p_ville, const string& p_codePostal, const string& p_province);
 *         int reqNumeroCivic() const;
 *         const string& reqNomRue() const;
 *         const string& reqVille() const;
 *         const string& reqCodePostal() const;
 *         const string& reqProvince() const;
 *         bool operator==(const Adresse& p_adresse) const;
 *         string reqAdresseFormate() const;
 */
#include <gtest/gtest.h>

#include "Adresse.h"


using namespace util;

/**
 * \brief Test du constructeur Adresse(int p_numeroCivic, const string& p_nomRue, const string& p_ville, const string& p_codePostal, const string& p_province).
 *
 *     Cas valide: 		numeroCivic doit etre positif;
 *     					nomRue ne doit pas etre vide;
 *     					ville ne doit pas etre vide;
 *     					codePostal ne doit pas etre vide;
 *     					province ne doit pas etre vide.
 *
 *     Cas invalide:	numeroCivic < 0;
 *     					nomRue est vide;
 *     					ville est vide;
 *     					codePostal est vide;
 *     					province est vide.
 */
TEST(Adresse, ConstructeurAdresseValide)
{
	Adresse uneAdresse(1, "rue", "ville", "cp", "province");
	ASSERT_EQ(1, uneAdresse.reqNumeroCivic());
	ASSERT_EQ("rue", uneAdresse.reqNomRue());
	ASSERT_EQ("ville", uneAdresse.reqVille());
	ASSERT_EQ("cp", uneAdresse.reqCodePostal());
	ASSERT_EQ("province", uneAdresse.reqProvince());
}
TEST(Adresse, ConstructeurNumeroCivicInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(-1, "rue", "ville", "cp", "province"),ContratException)
	      << "Une adresse ne doit pas accepter de numero civic negatif";
}
TEST(Adresse, ConstructeurNomRueInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(1, "", "ville", "cp", "province"),ContratException)
		      << "Une adresse ne doit pas accepter de nom de rue vide";
}
TEST(Adresse, ConstructeurVilleInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(1, "rue", "", "cp", "province"),ContratException)
			      << "Une adresse ne doit pas accepter de ville vide";
}
TEST(Adresse, ConstructeurCodePostalInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(1, "rue", "ville", "", "province"),ContratException)
			      << "Une adresse ne doit pas accepter de code postal vide";
}
TEST(Adresse, ConstructeurProvinceInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(1, "rue", "ville", "cp", ""),ContratException)
			      << "Une adresse ne doit pas accepter de province vide";
}

/**
 * \brief Test fixture pour les méthodes de la classe Adresse.
 */
class AdresseValide: public ::testing::Test
{
public:
	AdresseValide() :
		AdresseVal(1, "rue", "ville", "cp", "province")
    {
	}
	Adresse AdresseVal;
};

/**
 * \brief Test de la méthode void asgAdresse(int p_numeroCivic, const string& p_nomRue, const string& p_ville, const string& p_codePostal, const string& p_province).
 *
 *     Cas valide: 		nouveau numeroCivic doit etre positif;
 *     					nouveau nomRue ne doit pas etre vide;
 *     					nouvelle ville ne doit pas etre vide;
 *     					nouveau codePostal ne doit pas etre vide;
 *     					nouvelle province ne doit pas etre vide.
 *
 *     Cas invalide:	nouveau numeroCivic < 0;
 *     					nouveau nomRue est vide;
 *     					nouvelle ville est vide;
 *     					nouveau codePostal est vide;
 *     					nouvelle province est vide.
 */
TEST_F(AdresseValide,asgAdresseValide)
{
	AdresseVal.asgAdresse(2, "newRue", "newVille", "newCp", "newProvince");
	ASSERT_EQ(2, AdresseVal.reqNumeroCivic());
	ASSERT_EQ("newRue", AdresseVal.reqNomRue());
	ASSERT_EQ("newVille", AdresseVal.reqVille());
	ASSERT_EQ("newCp", AdresseVal.reqCodePostal());
	ASSERT_EQ("newProvince", AdresseVal.reqProvince());
}
TEST_F(AdresseValide,asgNumeroCivicInvalide)
{
	ASSERT_THROW(AdresseVal.asgAdresse(-2, "newRue", "newVille", "newCp", "newProvince"),ContratException)
          << "Une adresse ne doit pas accepter de numero civic negatif";
}
TEST_F(AdresseValide,asgNomRueInvalide)
{
	ASSERT_THROW(AdresseVal.asgAdresse(2, "", "newVille", "newCp", "newProvince"),ContratException)
          << "Une adresse ne doit pas accepter de nom de rue vide";
}
TEST_F(AdresseValide,asgVilleInvalide)
{
	ASSERT_THROW(AdresseVal.asgAdresse(2, "newRue", "", "newCp", "newProvince"),ContratException)
          << "Une adresse ne doit pas accepter de ville vide";
}
TEST_F(AdresseValide,asgCodePostalInvalide)
{
	ASSERT_THROW(AdresseVal.asgAdresse(2, "newRue", "newVille", "", "newProvince"),ContratException)
          << "Une adresse ne doit pas accepter de code postal vide";
}
TEST_F(AdresseValide,asgProvinceInvalide)
{
	ASSERT_THROW(AdresseVal.asgAdresse(2, "newRue", "newVille", "newCp", ""),ContratException)
          << "Une adresse ne doit pas accepter de province vide";
}
/**
 * \brief Test de la méthode int reqNumeroCivic() const.
 *     Cas valide: vérifier le retour du numero civic.
 *     Cas invalide: aucun.
 */
TEST_F(AdresseValide,reqNumeroCivic)
{
	ASSERT_EQ(1,AdresseVal.reqNumeroCivic());
}
/**
 * \brief Test de la méthode const string& reqNomRue() const.
 *     Cas valide: vérifier le retour du nom de rue.
 *     Cas invalide: aucun.
 */
TEST_F(AdresseValide,reqNomRue)
{
	ASSERT_EQ("rue",AdresseVal.reqNomRue());
}
/**
 * \brief Test de la méthode const string& reqVille() const.
 *     Cas valide: vérifier le retour de la ville.
 *     Cas invalide: aucun.
 */
TEST_F(AdresseValide,reqVille)
{
	ASSERT_EQ("ville",AdresseVal.reqVille());
}
/**
 * \brief Test de la méthode const string& reqCodePostal() const.
 *     Cas valide: vérifier le retour du code postal.
 *     Cas invalide: aucun.
 */
TEST_F(AdresseValide,reqCodePostal)
{
	ASSERT_EQ("cp",AdresseVal.reqCodePostal());
}
/**
 * \brief Test de la méthode const string& reqProvince() const.
 *     Cas valide: vérifier le retour de la province.
 *     Cas invalide: aucun.
 */
TEST_F(AdresseValide,reqProvince)
{
	ASSERT_EQ("province",AdresseVal.reqProvince());
}
/**
 * \brief Test de la méthode bool operator==(const Adresse& p_adresse) const.
 *     Cas valide: verifier si l'egalite est detectee.
 *     Cas invalide: aucun.
 */
TEST_F(AdresseValide, operatorEgalite)
{
	ASSERT_EQ(true, AdresseVal.reqNumeroCivic() == AdresseVal.reqNumeroCivic() and AdresseVal.reqNomRue() == AdresseVal.reqNomRue() and
			AdresseVal.reqVille() == AdresseVal.reqVille() and AdresseVal.reqCodePostal() == AdresseVal.reqCodePostal() and
			AdresseVal.reqProvince() == AdresseVal.reqProvince());
}
/**
 * \brief Test de la méthode string reqAdresseFormate() const.
 *     Cas valide: verifier le retour de l'adresse formatee.
 *     Cas invalide: aucun.
 */
TEST_F(AdresseValide, reqAdresseFormate)
{
	ASSERT_EQ("1, rue, ville, cp, province", AdresseVal.reqAdresseFormate());
}
