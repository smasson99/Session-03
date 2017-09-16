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
		
		TEST_METHOD(SphereParDefautPos0)
		{
			CollisionSphere CollisionSphere;
			Assert::AreEqual(CollisionSphere.getPosX(), 0.0f);
		}

		TEST_METHOD(SphereParDefautPosNot0)
		{
			CollisionSphere CollisionSphere;
			Assert::AreNotEqual(CollisionSphere.getPosX(), 1.0f);
		}
	};
}