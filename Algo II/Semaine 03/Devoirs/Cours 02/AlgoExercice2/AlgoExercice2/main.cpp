#include <iostream>
#include "console.h"


int main(char* argv, int argc)
{
	//Fin du programme. En C++, si la fonction "main" retourne 0, cela
	//veut dire que le programme a terminé correctement.
	//
	//S'il retourne 1, cela veut dire que le programme ne s'est pas 
	//terminé correctement.

    Console console;

    //int* tab = Console::readInt("", "");
    int size = console.readInt("Combien de nombres ?", "Erreur, veuillez entrer un nombre valide.");
    IntArray monTab = console.readIntArray(size, "Entrez un nombre :", "Erreur, veuillez entrer un nombre valide.");



    //monTab.~IntArray();
    system("pause");
	return 0;
}
