//
//  main.cpp
//  tp1
//
//  Exemple minimaliste d'utilisation
//

#include "IntVector.h"

int main()
{
    IntVector* iv = new IntVector();
    
    //Tester les push back
    iv->push_back(1);
    iv->push_back(2);
    iv->push_back(3);
    iv->push_back(4);
    iv->push_back(5);
    //Faire un pop back
    iv->pop_back();
    //On affiche, ça devrait donner 1,2,3,4 avec 4 de size 4 et 50 de cap
    iv->afficher();
    //Clear
    iv->clear();
    //On affiche, le tab devrait être vide
    iv->afficher();
    //Tester les resizes
    iv->push_back(1);
    iv->push_back(2);
    //On resize pour 4
    iv->resize(4);
    //On affiche, ça devrait donner 1,2,def,def de size 4 et 50 de cap
    iv->afficher();
    //Tester les resizes
    iv->push_back(1);
    iv->push_back(2);
    //On resize pour 60
    iv->resize(60);
    //On affiche, ça devrait donner 1,2,def,def... de size 60 et 100 de cap
    iv->afficher();

    iv->afficher();

    return 0;
}
