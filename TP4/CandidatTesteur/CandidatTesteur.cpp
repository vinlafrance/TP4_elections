/**
 * \file CandidatTesteur.cpp
 * \brief Testeur de la classe Candidat
 * \author etudiant
 * \version 1.0
 * \date 2020-11-24
 *  A tester:
 *         Candidat(const string& p_nas, const string& p_prenom, const string& p_nom,
 *         const util::Date& p_dateNaissance, const util::Adresse& p_adresse, int p_partiPolitique);
 *         int reqPartiPolitique() const;
 *         string reqPersonneFormate() const;
 *         Personne* clone() const;
 */
#include <gtest/gtest.h>
#include <sstream>

#include "Candidat.h"

using namespace elections;
using namespace util;

/**
 * \brief Test du constructeur Candidat(const string& p_nas, const string& p_prenom, const string& p_nom,
 * 										const Date& p_dateNaissance, const Adresse& p_adresse, int p_partiPolitique).
 *
 *     Cas valide: 		nas doit etre valide;
 *     					prenom ne doit pas etre vide;
 *     					nom ne doit pas etre vide;
 *     					dateNaissance doit etre valide;
 *     					adresse doit etre valide.
 *     					partiPolitique doit etre >= 0 et <= 4
 *
 *     Cas invalide:	nas est invalide;
 *     					prenom est vide;
 *     					nom est vide;
 *     					dateNaissance est invalide;
 *     					adresse est invalide.
 *     					partiPolitique est < 0 ou > 4.
 */
TEST(Candidat, ConstructeurCandidatValide)
{
	Candidat unCandidat("000 000 000", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0);
	ASSERT_EQ("000 000 000", unCandidat.reqNas());
	ASSERT_EQ("prenom", unCandidat.reqPrenom());
	ASSERT_EQ("nom", unCandidat.reqNom());
	ASSERT_EQ(Date(01, 01, 2000), unCandidat.reqDateNaissance());
	ASSERT_EQ(Adresse(1, "rue", "ville", "cp", "province"), unCandidat.reqAdresse());
	ASSERT_EQ(0, unCandidat.reqPartiPolitique());
}
TEST(Candidat, ConstructeurNasInvalide)
{
	ASSERT_THROW(Candidat unCandidat("123 456 789", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0),ContratException)
	      << "Un candidat ne doit pas accepter de nas invalide";
}
TEST(Candidat, ConstructeurPrenomInvalide)
{
	ASSERT_THROW(Candidat unCandidat("000 000 000", "", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0),ContratException)
	      << "Un candidat ne doit pas accepter de prenom vide";
}
TEST(Candidat, ConstructeurNomInvalide)
{
	ASSERT_THROW(Candidat unCandidat("000 000 000", "prenom", "", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0),ContratException)
	      << "Un candidat ne doit pas accepter de nom vide";
}
TEST(Candidat, ConstructeurDateInvalide)
{
	ASSERT_THROW(Candidat unCandidat("000 000 000", "prenom", "nom", Date(42, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0),ContratException)
	      << "Un candidat ne doit pas accepter de date invalide";
}
TEST(Candidat, ConstructeurAdresseInvalide)
{
	ASSERT_THROW(Candidat unCandidat("000 000 000", "prenom", "nom", Date(01, 01, 2000), Adresse(-1, "rue", "ville", "cp", "province"), 0),ContratException)
	      << "Un candidat ne doit pas accepter d'adresse invalide";
}
TEST(Candidat, ConstructeurPartiPolitiqueInvalide)
{
	ASSERT_THROW(Candidat unCandidat("000 000 000", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 7),ContratException)
	      << "Un candidat ne doit pas accepter de parti politique en bas de 0 ou en haut de 4";
}
/**
 * \brief Test fixture pour les méthodes de la classe Candidat.
 */
class CandidatValide: public ::testing::Test
{
public:
	CandidatValide() :
		CandidatVal("000 000 000", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0)
    {
	}
	Candidat CandidatVal;
};
/**
 * \brief Test de la méthode int reqPartiPolitique() const.
 *     Cas valide: vérifier le retour du parti politique.
 *     Cas invalide: aucun.
 */
TEST_F(CandidatValide,reqPartiPolitique)
{
	ASSERT_EQ(0,CandidatVal.reqPartiPolitique());
}
/**
 * \brief Test de la méthode string reqPersonneFormate() const.
 *     Cas valide: verifier le retour de la personne formatee.
 *     Cas invalide: aucun.
 */
TEST_F(CandidatValide, reqPersonneFormate)
{
	std::ostringstream os;
	os << "\nCandidat"
			<< "\n----------------------------------------------"
			<< "\nNAS			: 000 000 000"
			<< "\nPrenom			: prenom"
			<< "\nNom			: nom"
			<< "\nDate de naissance	: Samedi le 01 janvier 2000"
			<< "\nAdresse			: 1, rue, ville, cp, province"
			<< "\nParti politique		: BLOC_QUEBECOIS";
	ASSERT_EQ(os.str(), CandidatVal.reqPersonneFormate());
}
/**
 * \brief Test de la méthode Personne* clone() const.
 *     Cas valide: vérifier si le clone est egale.
 *     Cas invalide: aucun.
 */
TEST_F(CandidatValide, clone)
{
	ASSERT_EQ(CandidatVal,*CandidatVal.clone());
}
