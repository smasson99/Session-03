#include "main.h"
#include "piles.h"
//#include "pile01.h"

int main()
{
	//Tests de la pile g�n�rique
	//Entiers:
	PileGenerique<int> pileGEntiers;



	//res
	return 0;
}

/*
Exercice : Pile et types g�n�riques
1. Implanter une pile g�n�rique avec comme repr�sentation interne une structure de
donn�es de la librairie standard. Je vous sugg�re le vector.
2. Implanter une pile g�n�rique avec comme repr�sentation interne un pointeur et un
nombre d��l�ment tel que vu en classe.
3. Concevoir un petit programme qui va lire un caract�re au clavier jusqu�� ce que
l�utilisateur entre autre chose qu�une lettre (minuscule ou majuscule). R�f�rez-vous � la
table ASCII
4. Sp�cialis� votre pile pour les caract�res en y ajoutant une m�thode pour inverser la
Case.

Classe Pile

Priv� :
Pile (const Pile& ) = delete; //pour les raisons vue en cours.
Le vector ou les attributs sommet et nombre d��l�ments.

Public :
Pile();
~Pile();
Const Type& Sommet() const
Void Empiler(const type& valeur);
Type D�piler() //Pourquoi on ne retourne pas Type&?
Bool Est vide()
Size_t Dimension()
Pile& Operator=(const Pile&)
*/