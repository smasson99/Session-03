#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Imagwzit/CollisionSphere.h"
//Il faut que ce dernier lien soit aussi dans 
//[right-click sur projet]\éditeur de liens\propriétés\entrées\dépendances additionnelles
//sinon il y aura une erreur de linkage

//Si la classe que vous testez a une autre classe comme attribut, alors il faut aussi linker son .obj

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjetSFMLTest
{
    TEST_CLASS(UnitTest1)
    {
    public:
        
        /*Voici les tests concernant les méthodes de retour et les constructeurs de la classe CollisionSphere*/

        /// <summary>
        /// Tester la position en X par défaut de la sphère.
        /// </summary>
        TEST_METHOD(SphereParDefautPos0_01)
        {
            /*Créer une sphère de collision*/
            CollisionSphere CollisionSphere;
            /*La position en Y devrait valoire 0.00f*/
            Assert::AreEqual(CollisionSphere.getPosX(), 0.0f);
        }

        /// <summary>
        /// Tester la position en Y par défaut de la sphère de collision.
        /// </summary>
        TEST_METHOD(SphereParDefautPos0_02)
        {
            /*Créer une sphère de collision*/
            CollisionSphere CollisionSphere;
            /*La position en Y devrait valoire 0.00f*/
            Assert::AreEqual(CollisionSphere.getPosY(), 0.0f);
        }
        
        /// <summary>
        /// Tester la valeur par défaut du rayon de la sphère de collision.
        /// </summary>
        TEST_METHOD(TesterSphereRayonDefaut_01)
        {
            /*Créer une sphère de collision*/
            CollisionSphere sphere01;
            /*Le rayon devrait valoir 1*/
            Assert::AreEqual(sphere01.getRayon(), 1.0f);
        }
        
        /// <summary>
        /// Tester les valeurs entrées en paramètre dans le deuxième constructeur de la sphère de collision.
        /// </summary>
        TEST_METHOD(TesterConstructeurParam01_01)
        {
            /*Créer une sphère de collision avec des paramètres entrés dans le 
            constructeur*/
            CollisionSphere sphere01(2, 5, 10);
            /*Vérifier les coordonnées*/
            Assert::AreEqual(sphere01.getRayon(), 2.0f);
            Assert::AreEqual(sphere01.getPosX(), 5.0f);
            Assert::AreEqual(sphere01.getPosY(), 10.0f);
        }

        /// <summary>
        /// Tester les valeurs entrées en paramètre dans le deuxième constructeur de la sphère de collision.
        /// </summary>
        TEST_METHOD(TesterConstructeurParam01_02)
        {
            /*Créer une sphère de collision avec des paramètres entrés dans le
            constructeur*/
            CollisionSphere sphere01(2.7f, -5.2f, -10.0f);
            /*Vérifier les coordonnées*/
            Assert::AreEqual(sphere01.getRayon(), 2.7f);
            Assert::AreEqual(sphere01.getPosX(), -5.2f);
            Assert::AreEqual(sphere01.getPosY(), -10.0f);
        }

        /*Voici les tests concernant la détection des collisions*/

        /// <summary>
        /// Tester un cas où il n'y a clairement pas de collision.
        /// </summary>
        TEST_METHOD(TesterClairementPasCollision_01)
        {
            /*Créer deux sphères du même rayon et les placer à deux positions distancées de 100 unités*/
            CollisionSphere sphere01(1, 100, 1);
            CollisionSphere sphere02(1, 0, 1);
            /*Aucune collision ne devrait être détectée*/
            Assert::IsFalse(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas où il n'y a clairement pas de collision.
        /// </summary>
        TEST_METHOD(TesterClairementPasCollision_02)
        {
            /*Créer deux sphères du même rayon et les placer à deux positions distancées de 100 unités*/
            CollisionSphere sphere01(1, 1, 100);
            CollisionSphere sphere02(1, 1, 0);
            /*Aucune collision ne devrait être détectée*/
            Assert::IsFalse(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas où il n'y a pas de collision, mais où les deux sphères se frôlent.
        /// </summary>
        TEST_METHOD(TesterPasCollisionLimite_01)
        {
            /*Créer deux sphères du même rayon(1) à une distance de 2 unités*/
            CollisionSphere sphere01(1, 2, 0);
            CollisionSphere sphere02(1, 0, 0);
            /*Aucune collision ne devrait être détectée*/
            Assert::IsFalse(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas où il n'y a pas de collision, mais où les deux sphères se frôlent.
        /// </summary>
        TEST_METHOD(TesterPasCollisionLimite_02)
        {
            /*Créer deux sphères du même rayon(1) à une distance de 2 unités*/
            CollisionSphere sphere01(1, 0, 2);
            CollisionSphere sphere02(1, 0, 0);
            /*Aucune collision ne devrait être détectée*/
            Assert::IsFalse(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas limite où une collision a lieu.
        /// </summary>
        TEST_METHOD(TesterCollisionLimite_01)
        {
            /*Créer deux sphères du même rayon(1) à une distance de 1.9 unités*/
            CollisionSphere sphere01(1, 1.9f, 0);
            CollisionSphere sphere02(1, 0, 0);
            /*Une collision devrait être détectée*/
            Assert::IsTrue(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas limite où une collision a lieu.
        /// </summary>
        TEST_METHOD(TesterCollisionLimite_02)
        {
            /*Créer deux sphères du même rayon(1) à une distance de 1.9 unités*/
            CollisionSphere sphere01(1, 0, 1.9f);
            CollisionSphere sphere02(1, 0, 0);
            /*Une collision devrait être détectée*/
            Assert::IsTrue(sphere01.verifierCollision(sphere02));
        }
        
        /// <summary>
        /// Tester un cas où il y a une évidente collision entre les deux sphères.
        /// </summary>
        TEST_METHOD(TesterCollisionFranche_01)
        {
            /*Créer deux sphères du même rayon(1) à une distance de 1.5 unités*/
            CollisionSphere sphere01(1, 1.5f, 0);
            CollisionSphere sphere02(1, 0, 0);
            /*Une collision devrait être détectée*/
            Assert::IsTrue(sphere01.verifierCollision(sphere02));
        }

        /// <summary>
        /// Tester un cas où il y a une évidente collision entre les deux sphères.
        /// </summary>
        TEST_METHOD(TesterCollisionFranche_02)
        {
            /*Créer deux sphères du même rayon(1) à une distance de 1.5 unités*/
            CollisionSphere sphere01(1, 0, 1.5f);
            CollisionSphere sphere02(1, 0, 0);
            /*Une collision devrait être détectée*/
            Assert::IsTrue(sphere01.verifierCollision(sphere02));
        }

        /*Voici les tests des SETS de la classe CollisionSphere*/
        
        /// <summary>
        /// Tester le SetPosition en X.
        /// </summary>
        TEST_METHOD(TesterSetPositionX_01)
        {
            /*Créer une sphère de collision*/
            CollisionSphere sphere01;
            /*Faire le SetPosition*/
            sphere01.SetPosition(12, sphere01.getPosY());
            /*Vérifier la position en X*/
            Assert::AreEqual(sphere01.getPosX(), 12.0f);
        }

        /// <summary>
        /// Tester le SetPosition en X.
        /// </summary>
        TEST_METHOD(TesterSetPositionX_02)
        {
            /*Créer une sphère de collision*/
            CollisionSphere sphere01;
            /*Faire le SetPosition*/
            sphere01.SetPosition(-12, sphere01.getPosY());
            /*Vérifier la position en X*/
            Assert::AreEqual(sphere01.getPosX(), -12.0f);
        }

        /// <summary>
        /// Tester le SetPosition en Y.
        /// </summary>
        TEST_METHOD(TesterSetPositionY_01)
        {
            /*Créer une sphère de collision*/
            CollisionSphere sphere01;
            /*Faire le SetPosition*/
            sphere01.SetPosition(sphere01.getPosX(), 50);
            /*Vérifier la position en Y*/
            Assert::AreEqual(sphere01.getPosY(), 50.0f);
        }

        /// <summary>
        /// Tester le SetPosition en Y.
        /// </summary>
        TEST_METHOD(TesterSetPositionY_02)
        {
            /*Créer une sphère de collision*/
            CollisionSphere sphere01;
            /*Faire le SetPosition*/
            sphere01.SetPosition(sphere01.getPosX(), -50);
            /*Vérifier la position en Y*/
            Assert::AreEqual(sphere01.getPosY(), -50.0f);
        }

    };
}