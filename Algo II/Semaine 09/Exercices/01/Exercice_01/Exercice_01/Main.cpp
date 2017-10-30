#include "main.h"
#include "piles.h"
//#include "pile01.h"

int main()
{
	//Tests de la pile générique
	//Entiers:
	PileGenerique<int> pileGEntiers;



	//res
	return 0;
}

/*
Exercice : Pile et types génériques
1. Implanter une pile générique avec comme représentation interne une structure de
données de la librairie standard. Je vous suggère le vector.
2. Implanter une pile générique avec comme représentation interne un pointeur et un
nombre d’élément tel que vu en classe.
3. Concevoir un petit programme qui va lire un caractère au clavier jusqu’à ce que
l’utilisateur entre autre chose qu’une lettre (minuscule ou majuscule). Référez-vous à la
table ASCII
4. Spécialisé votre pile pour les caractères en y ajoutant une méthode pour inverser la
Case.

Classe Pile

Privé :
Pile (const Pile& ) = delete; //pour les raisons vue en cours.
Le vector ou les attributs sommet et nombre d’éléments.

Public :
Pile();
~Pile();
Const Type& Sommet() const
Void Empiler(const type& valeur);
Type Dépiler() //Pourquoi on ne retourne pas Type&?
Bool Est vide()
Size_t Dimension()
Pile& Operator=(const Pile&)
*/