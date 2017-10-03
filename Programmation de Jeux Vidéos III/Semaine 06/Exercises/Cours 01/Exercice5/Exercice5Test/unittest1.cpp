#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Exercice5/Joueur.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Exercice2Test
{
	TEST_CLASS(JoueurTest)
	{
	public:
		//Mail valides, avec nom de domaine � 2 ou 3 caract�res et caract�res l�gaux
		TEST_METHOD(ValiderAddresseCourriel_MailsValides)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");

			Assert::IsTrue(joueur.setCourriel("pg12345@gmail.com"));
			Assert::IsTrue(joueur.setCourriel("pg12345@gmail.ca"));
			Assert::IsTrue(joueur.setCourriel("pg12_345@gma-il.ca"));
			Assert::IsTrue(joueur.setCourriel("pg12_345@gma-il...ca"));
		}

		//Bizarrement, ceci est l�gal selont la d�finition de microsoft
		TEST_METHOD(ValiderAddresseCourriel_MailValideSuffixePoint)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsTrue(joueur.setCourriel("pg12_345@..ca"));
		}

		//----------------------------------------------------------------------------------------------------------------------

		//Pas de nom de domaine
		TEST_METHOD(ValiderAddresseCourriel_MailInvalidePasDeDomaine)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("pg12345@gmailcom"));
		}

		//Nom de domaine vide 
		TEST_METHOD(ValiderAddresseCourriel_MailInvalideDomaineVide)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("pg12345@gmail.com."));
		}

		//Nom de domaine trop court
		TEST_METHOD(ValiderAddresseCourriel_MailInvalideDomaineTropCourt)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("pg12345@gmail.co.m"));
		}

		//Nom de domaine trop long
		TEST_METHOD(ValiderAddresseCourriel_MailInvalideDomaineTropLong)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("pg12345@gmail.comm"));
		}

		//Deux arobas
		TEST_METHOD(ValiderAddresseCourriel_MailInvalideDeuxArobas)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("pg12345@gma@il.com"));
		}

		//Pas d'arobas
		TEST_METHOD(ValiderAddresseCourriel_MailInvalidePasArobas)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("pg12345gmail.com"));
		}

		//Les caract�res accentu�s sont ill�gaux
		TEST_METHOD(ValiderAddresseCourriel_MailValideAvecAccent)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("�pg12345�@gmail.com"));
		}

		//caract�re ill�gal
		TEST_METHOD(ValiderAddresseCourriel_MailInvalideCharIllegal)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("pg#12345@gmail.com"));
		}

		//caract�re ill�gal 2
		TEST_METHOD(ValiderAddresseCourriel_MailInvalideCharIllegal2)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("pg123+45@gmail.com"));
		}

		//caract�re ill�gal 3
		TEST_METHOD(ValiderAddresseCourriel_MailInvalideCharIllegal3)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("pg12345%@gmail.com"));
		}

		//Pas de pr�fixe
		TEST_METHOD(ValiderAddresseCourriel_MailInvalidePasPrefixe)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("@gmail.fr"));
		}

		//Pas de suffixe
		TEST_METHOD(ValiderAddresseCourriel_MailInvalidePasSuffixe)
		{
			Joueur joueur("Peter Griffin", "FamilyGuy@hotmail.com");
			Assert::IsFalse(joueur.setCourriel("pg12345@.fr"));
		}
	};
}