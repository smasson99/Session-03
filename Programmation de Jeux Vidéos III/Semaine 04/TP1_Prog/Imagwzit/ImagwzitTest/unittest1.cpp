#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Imagwzit/CollisionSphere.h"
//Il faut que ce dernier lien soit aussi dans 
//[right-click sur projet]\�diteur de liens\propri�t�s\entr�es\d�pendances additionnelles
//sinon il y aura une erreur de linkage

//Si la classe que vous testez a une autre classe comme attribut, alors il faut aussi linker son .obj

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjetSFMLTest
{
    TEST_CLASS(UnitTest1)
    {
    public:
        
        /*Voici les tests concernant les m�thodes de retour et les constructeurs de la classe CollisionSphere*/

        /// <summary>
        /// Tester la position en X par d�faut de la sph�re.
        /// </summary>
        TEST_METHOD(SphereParDefautPos0_01)
        {
            /*Cr�er une sph�re de collision*/
            CollisionSphere CollisionSphere;
            /*La position en Y devrait valoire 0.00f*/
            Assert::AreEqual(CollisionSphere.getPosX(), 0.0f);
        }

        /// <summary>
        /// Tester la position en Y par d�faut de la sph�re de collision.
        /// </summary>
        TEST_METHOD(SphereParDefautPos0_02)
        {
            /*Cr�er une sph�re de collision*/
            CollisionSphere CollisionSphere;
            /*La position en Y devrait valoire 0.00f*/
            Assert::AreEqual(CollisionSphere.getPosY(), 0.0f);
        }
        
        /// <summary>
        /// Tester la valeur par d�faut du rayon de la sph�re de collision.
        /// </summary>
        TEST_METHOD(TesterSphereRayonDefaut_01)
        {
            /*Cr�er une sph�re de collision*/
            CollisionSphere sphere01;
            /*Le rayon devrait valoir 1*/
            Assert::AreEqual(sphere01.getRayon(), 1.0f);
        }
        
        /// <summary>
        /// Tester les valeurs entr�es en param�tre dans le deuxi�me constructeur de la sph�re de collision.
        /// </summary>
        TEST_METHOD(TesterConstructeurParam01_01)
        {
            /*Cr�er une sph�re de collision avec des param�tres entr�s dans le 
            constructeur*/
            CollisionSphere sphere01(2, 5, 10);
            /*V�rifier les coordonn�es*/
            Assert::AreEqual(sphere01.getRayon(), 2.0f);
            Assert::AreEqual(sphere01.getPosX(), 5.0f);
            Assert::AreEqual(sphere01.getPosY(), 10.0f);
        }

        /// <summary>
        /// Tester les valeurs entr�es en param�tre dans le deuxi�me constructeur de la sph�re de collision.
        /// </summary>
        TEST_METHOD(TesterConstructeurParam01_02)
        {
            /*Cr�er une sph�re de collision avec des param�tres entr�s dans le
            constructeur*/
            CollisionSphere sphere01(2.7f, -5.2f, -10.0f);
            /*V�rifier les coordonn�es*/
            Assert::AreEqual(sphere01.getRayon(), 2.7f);
            Assert::AreEqual(sphere01.getPosX(), -5.2f);
            Assert::AreEqual(sphere01.getPosY(), -10.0f);
        }

        /*Voici les tests concernant la d�tection des collisions*/

        /// <summary>
        /// Tester un cas o� il n'y a clairement pas de collision.
        /// </summary>
        TEST_METHOD(TesterClairementPasCollision_01)
        {
            /*Cr�er deux sph�res du m�me rayon et les placer � deux positions distanc�es de 100 unit�s*/
            CollisionSphere sphere01(1, 100, 1);
            CollisionSphere sphere02(1, 0, 1);
            /*Aucune collision ne devrait �tre d�tect�e*/
            Assert::IsFalse(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas o� il n'y a clairement pas de collision.
        /// </summary>
        TEST_METHOD(TesterClairementPasCollision_02)
        {
            /*Cr�er deux sph�res du m�me rayon et les placer � deux positions distanc�es de 100 unit�s*/
            CollisionSphere sphere01(1, 1, 100);
            CollisionSphere sphere02(1, 1, 0);
            /*Aucune collision ne devrait �tre d�tect�e*/
            Assert::IsFalse(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas o� il n'y a pas de collision, mais o� les deux sph�res se fr�lent.
        /// </summary>
        TEST_METHOD(TesterPasCollisionLimite_01)
        {
            /*Cr�er deux sph�res du m�me rayon(1) � une distance de 2 unit�s*/
            CollisionSphere sphere01(1, 2, 0);
            CollisionSphere sphere02(1, 0, 0);
            /*Aucune collision ne devrait �tre d�tect�e*/
            Assert::IsFalse(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas o� il n'y a pas de collision, mais o� les deux sph�res se fr�lent.
        /// </summary>
        TEST_METHOD(TesterPasCollisionLimite_02)
        {
            /*Cr�er deux sph�res du m�me rayon(1) � une distance de 2 unit�s*/
            CollisionSphere sphere01(1, 0, 2);
            CollisionSphere sphere02(1, 0, 0);
            /*Aucune collision ne devrait �tre d�tect�e*/
            Assert::IsFalse(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas limite o� une collision a lieu.
        /// </summary>
        TEST_METHOD(TesterCollisionLimite_01)
        {
            /*Cr�er deux sph�res du m�me rayon(1) � une distance de 1.9 unit�s*/
            CollisionSphere sphere01(1, 1.9f, 0);
            CollisionSphere sphere02(1, 0, 0);
            /*Une collision devrait �tre d�tect�e*/
            Assert::IsTrue(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas limite o� une collision a lieu.
        /// </summary>
        TEST_METHOD(TesterCollisionLimite_02)
        {
            /*Cr�er deux sph�res du m�me rayon(1) � une distance de 1.9 unit�s*/
            CollisionSphere sphere01(1, 0, 1.9f);
            CollisionSphere sphere02(1, 0, 0);
            /*Une collision devrait �tre d�tect�e*/
            Assert::IsTrue(sphere01.verifierCollision(sphere02));
        }
        
        /// <summary>
        /// Tester un cas o� il y a une �vidente collision entre les deux sph�res.
        /// </summary>
        TEST_METHOD(TesterCollisionFranche_01)
        {
            /*Cr�er deux sph�res du m�me rayon(1) � une distance de 1.5 unit�s*/
            CollisionSphere sphere01(1, 1.5f, 0);
            CollisionSphere sphere02(1, 0, 0);
            /*Une collision devrait �tre d�tect�e*/
            Assert::IsTrue(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas o� il y a une �vidente collision entre les deux sph�res.
        /// </summary>
        TEST_METHOD(TesterCollisionFranche_02)
        {
            /*Cr�er deux sph�res du m�me rayon(1) � une distance de 1.5 unit�s*/
            CollisionSphere sphere01(1, 0, 1.5f);
            CollisionSphere sphere02(1, 0, 0);
            /*Une collision devrait �tre d�tect�e*/
            Assert::IsTrue(sphere01.verifierCollision(sphere02));
        }

        /*Voici les tests des SETS de la classe CollisionSphere*/
        
        /// <summary>
        /// Tester le SetPosition en X.
        /// </summary>
        TEST_METHOD(TesterSetPositionX_01)
        {
            /*Cr�er une sph�re de collision*/
            CollisionSphere sphere01;
            /*Faire le SetPosition*/
            sphere01.SetPosition(12, sphere01.getPosY());
            /*V�rifier la position en X*/
            Assert::AreEqual(sphere01.getPosX(), 12.0f);
        }

        /// <summary>
        /// Tester le SetPosition en X.
        /// </summary>
        TEST_METHOD(TesterSetPositionX_02)
        {
            /*Cr�er une sph�re de collision*/
            CollisionSphere sphere01;
            /*Faire le SetPosition*/
            sphere01.SetPosition(-12, sphere01.getPosY());
            /*V�rifier la position en X*/
            Assert::AreEqual(sphere01.getPosX(), -12.0f);
        }

        /// <summary>
        /// Tester le SetPosition en Y.
        /// </summary>
        TEST_METHOD(TesterSetPositionY_01)
        {
            /*Cr�er une sph�re de collision*/
            CollisionSphere sphere01;
            /*Faire le SetPosition*/
            sphere01.SetPosition(sphere01.getPosX(), 50);
            /*V�rifier la position en Y*/
            Assert::AreEqual(sphere01.getPosY(), 50.0f);
        }

        /// <summary>
        /// Tester le SetPosition en Y.
        /// </summary>
        TEST_METHOD(TesterSetPositionY_02)
        {
            /*Cr�er une sph�re de collision*/
            CollisionSphere sphere01;
            /*Faire le SetPosition*/
            sphere01.SetPosition(sphere01.getPosX(), -50);
            /*V�rifier la position en Y*/
            Assert::AreEqual(sphere01.getPosY(), -50.0f);
        }

    };
}