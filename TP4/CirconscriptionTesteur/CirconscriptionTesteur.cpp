/**
 * \file CirconscriptionTesteur.cpp
 * \brief Testeur de la classe Circonscription
 * \author etudiant
 * \version 1.0
 * \date 2020-11-24
 *  A tester:
 *         Circonscription(const std::string& p_nomCirconscription, const Candidat& p_deputeElu);
 *         Circonscription(Circonscription const& p_circonscription);
 *         const string& reqNomCirconscription() const;
 *         const Candidat& reqDeputeElu() const;
 *         string reqCirconscriptionFormate() const;
 *         void inscrire(const Personne& p_nouvelInscrit);
 *         Circonscription& operator=(const Circonscription& p_circonscription);
 *         bool Circonscription::personneEstDejaPresente(const string& p_nas) const;
 *         void Circonscription::desinscrire(const std::string& p_nas);
 */
#include <gtest/gtest.h>
#include <sstream>

#include "Circonscription.h"
#include "Electeur.h"

using namespace elections;
using namespace util;

/**
 * \brief Test du constructeur Circonscription(const std::string& p_nomCirconscription, const Candidat& p_deputeElu).
 *
 *     Cas valide: 		nomCirconscription ne doit pas etre vide;
 *     					deputeElu doit etre valide;
 *
 *     Cas invalide:	nomCirconscription est vide;
 *     					deputeElu est invalide;
 */
TEST(Circonscription, ConstructeurCirconscriptionValide)
{
	Circonscription uneCirconscription("Circonscription1", Candidat("000 000 000", "prenom",
			"nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0));
	ASSERT_EQ("Circonscription1", uneCirconscription.reqNomCirconscription());
	ASSERT_EQ(Candidat("000 000 000", "prenom", "nom", Date(01, 01, 2000),
			Adresse(1, "rue", "ville", "cp", "province"), 0), uneCirconscription.reqDeputeElu());
}
TEST(Circonscription, ConstructeurNomCirconscriptionInvalide)
{
	ASSERT_THROW(Circonscription uneCirconscription("",
			Candidat("000 000 000", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0)), ContratException)
	      << "Une circonscription ne doit pas accepter de nomCirconscription vide";
}
TEST(Circonscription, ConstructeurDeputeEluInvalide)
{
	ASSERT_THROW(Circonscription uneCirconscription("Circonscription1",
			Candidat("123 456 789", "prenom", "nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0)), ContratException)
	      << "Une circonscription ne doit pas accepter de deputeElu invalide";
}
/**
 * \brief Test du constructeur copie Circonscription(Circonscription const& p_circonscription).
 *
 *     Cas valide: 		circonscription doit etre valide;
 *
 *     Cas invalide:	circonscription est invalide.
 */
TEST(Circonscription, ConstructeurCopieCirconscriptionValide)
{
	Circonscription uneCirconscription(Circonscription("Circonscription1", Candidat("000 000 000", "prenom",
			"nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0)));
	ASSERT_EQ("Circonscription1", uneCirconscription.reqNomCirconscription());
	ASSERT_EQ(Candidat("000 000 000", "prenom", "nom", Date(01, 01, 2000),
				Adresse(1, "rue", "ville", "cp", "province"), 0), uneCirconscription.reqDeputeElu());
}
TEST(Circonscription, ConstructeurCopieCirconscriptionInvalide)
{
	ASSERT_THROW(Circonscription uneCirconscription(Circonscription("Circonscription1", Candidat("123 456 789", "prenom",
			"nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0))), ContratException)
	      << "Impossible de faire la copie d'une circonscription invalide";
}
/**
 * \brief Test fixture pour les méthodes de la classe Circonscription.
 */
class CirconscriptionValide: public ::testing::Test
{
public:
	CirconscriptionValide() :
		CirconscriptionVal("Circonscription1", Candidat("000 000 000", "prenom",
				"nom", Date(01, 01, 2000), Adresse(1, "rue", "ville", "cp", "province"), 0))
    {
	}
	Circonscription CirconscriptionVal;
};
/**
 * \brief Test de la méthode const string& reqNomCirconscription() const.
 *     Cas valide: vérifier le retour du nomCirconscription.
 *     Cas invalide: aucun.
 */
TEST_F(CirconscriptionValide,reqNomCirconscription)
{
	ASSERT_EQ("Circonscription1",CirconscriptionVal.reqNomCirconscription());
}
/**
 * \brief Test de la méthode const Candidat& reqDeputeElu() const.
 *     Cas valide: vérifier le retour du deputeElu.
 *     Cas invalide: aucun.
 */
TEST_F(CirconscriptionValide,reqDeputeElu)
{
	ASSERT_EQ(Candidat("000 000 000", "prenom", "nom", Date(01, 01, 2000),
			Adresse(1, "rue", "ville", "cp", "province"), 0),CirconscriptionVal.reqDeputeElu());
}
/**
 * \brief Test de la méthode string reqCirconscriptionFormate() const.
 *     Cas valide: vérifier le retour de la circonscription formatee.
 *     Cas invalide: aucun.
 */
TEST_F(CirconscriptionValide,reqCirconscriptionFormate)
{
	std::ostringstream os;
	os << "\ncirconscription : Circonscription1"
			<< "\nDepute sortant :"
			<< "\nCandidat"
			<< "\n----------------------------------------------"
			<< "\nNAS			: 000 000 000"
			<< "\nPrenom			: prenom"
			<< "\nNom			: nom"
			<< "\nDate de naissance	: Samedi le 01 janvier 2000"
			<< "\nAdresse			: 1, rue, ville, cp, province"
			<< "\nParti politique		: BLOC_QUEBECOIS"
			<< "\n\nListe des inscrits :";
	ASSERT_EQ(os.str(), CirconscriptionVal.reqCirconscriptionFormate());
}
/**
 * \brief Test de la méthode void inscrire(const Personne& p_nouvelInscrit).
 *     Cas valide: vérifier le reqCirconscriptionFormate attendu avec un inscrit de plus.
 *     Cas valide: vérifier que nous n'inscrivons pas deux fois la meme personne.
 *     Cas invalide: aucun.
 */
TEST_F(CirconscriptionValide,inscrire)
{
	CirconscriptionVal.inscrire(Electeur("000 000 000", "prenom2", "nom2", Date(02, 01, 2000), Adresse(2, "rue2", "ville2", "cp2", "province2")));
	std::ostringstream os;
	os << "\ncirconscription : Circonscription1"
			<< "\nDepute sortant :"
			<< "\nCandidat"
			<< "\n----------------------------------------------"
			<< "\nNAS			: 000 000 000"
			<< "\nPrenom			: prenom"
			<< "\nNom			: nom"
			<< "\nDate de naissance	: Samedi le 01 janvier 2000"
			<< "\nAdresse			: 1, rue, ville, cp, province"
			<< "\nParti politique		: BLOC_QUEBECOIS"
			<< "\n\nListe des inscrits :"
			<< "\nElecteur"
			<< "\n----------------------------------------------"
			<< "\nNAS			: 000 000 000"
			<< "\nPrenom			: prenom2"
			<< "\nNom			: nom2"
			<< "\nDate de naissance	: Dimanche le 02 janvier 2000"
			<< "\nAdresse			: 2, rue2, ville2, cp2, province2\n";
	ASSERT_EQ(os.str(), CirconscriptionVal.reqCirconscriptionFormate());
	ASSERT_THROW(CirconscriptionVal.inscrire(Electeur("000 000 000", "prenom2", "nom2", Date(02, 01, 2000),
			Adresse(2, "rue2", "ville2", "cp2", "province2"))), PersonneDejaPresenteException)
		      << "Impossible d'inscrire une personne deja inscrite";
}
/**
 * \brief Test de la méthode Circonscription& operator=(const Circonscription& p_circonscription).
 *     Cas valide: 	nouveau nomCirconscription est egale a l'autre.
 *     				nouveau deputeElu est egale a l'autre
 *     				vérifier si les reqCirconscriptionFormate sont egaux
 *     Cas invalide: aucun.
 */
TEST_F(CirconscriptionValide,operatorAssignation)
{
	Circonscription uneCirconscription = CirconscriptionVal;
	ASSERT_EQ(uneCirconscription.reqNomCirconscription(), CirconscriptionVal.reqNomCirconscription());
	ASSERT_EQ(uneCirconscription.reqDeputeElu(), CirconscriptionVal.reqDeputeElu());
	ASSERT_EQ(uneCirconscription.reqCirconscriptionFormate(), CirconscriptionVal.reqCirconscriptionFormate());
}
/**
 * \brief Test de la méthode void Circonscription::desinscrire(const std::string& p_nas).
 *     Cas valide:
 *     Cas invalide: aucun.
 */
TEST_F(CirconscriptionValide, desinscrire)
{
	CirconscriptionVal.inscrire(Electeur("000 000 000", "prenom2", "nom2", Date(02, 01, 2000), Adresse(2, "rue2", "ville2", "cp2", "province2")));
	CirconscriptionVal.desinscrire("000 000 000");
	std::ostringstream os;
	os << "\ncirconscription : Circonscription1"
				<< "\nDepute sortant :"
				<< "\nCandidat"
				<< "\n----------------------------------------------"
				<< "\nNAS			: 000 000 000"
				<< "\nPrenom			: prenom"
				<< "\nNom			: nom"
				<< "\nDate de naissance	: Samedi le 01 janvier 2000"
				<< "\nAdresse			: 1, rue, ville, cp, province"
				<< "\nParti politique		: BLOC_QUEBECOIS"
				<< "\n\nListe des inscrits :";
	ASSERT_EQ(os.str(), CirconscriptionVal.reqCirconscriptionFormate());
	ASSERT_THROW(CirconscriptionVal.desinscrire("111 111 118"), PersonneAbsenteException)
	<< "Impossible de desinscrire une personne non-inscrite";
}
