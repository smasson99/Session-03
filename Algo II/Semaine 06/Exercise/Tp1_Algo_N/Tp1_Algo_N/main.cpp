//
//  main.cpp
//  tp1
//
//  Exemple minimaliste d'utilisation
//
#include <iostream>
#include "IntVector.h"
using namespace std;

int main()
{
    IntVector* iv = new IntVector();
    
    ////Tester les push back
    //cout << "D�but du test des push back" << endl;
    //iv->push_back(1);
    //iv->push_back(2);
    //iv->push_back(3);
    //iv->push_back(4);
    //iv->push_back(5);
    ////Faire un pop back
    //iv->pop_back();
    ////On affiche, �a devrait donner 1,2,3,4 avec 4 de size 4 et 50 de cap
    //iv->afficher();
    ////Clear
    //iv->clear();

    ////On affiche, le tab devrait �tre vide
    //cout << "D�but du test des clears" << endl;
    //iv->afficher();
    ////Tester les resizes
    //cout << "D�but du test des resizes" << endl;
    //iv->push_back(1);
    //iv->push_back(2);
    ////On resize pour 4
    //iv->resize(4);
    ////On affiche, �a devrait donner 1,2,def,def de size 4 et 50 de cap
    //iv->afficher();
    ////Clear
    //iv->clear();

    ////Tester les resizes plus grands que la capacit�
    //cout << "D�but du test des resizes plus grands que la capacit�" << endl;
    //iv->push_back(1);
    //iv->push_back(2);
    ////On resize pour 60
    //iv->resize(60);
    ////On affiche, �a devrait donner 1,2,def,def... de size 60 et 100 de cap
    //iv->afficher();
    ////Clear
    //iv->clear();

    //Tester la copie d'instance
    //cout << "D�but du test des copies d'instances (opperateur =)" << endl;
    ////Cr�er l'instance
    //iv->push_back(3);
    //iv->push_back(2);
    //iv->push_back(1);
    //cout << "Voici le contenu de l'instance avant la copie" << endl;
    //iv->afficher();
    ////Copie de l'instance
    //IntVector* nouveau = new IntVector(*iv);
    //cout << "Voici le contenu du nouveau vecteur apr�s la copie" << endl;
    //nouveau->afficher();

    //Faire un swap
    //D�claration des variables:
    IntVector* vect1;
    IntVector* vect2;
    //Rentrer vecteur 1 dans vecteur 2:
    


    iv->afficher();

    return 0;
}
