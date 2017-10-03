//
//  Samuel Masson (1632010)
//
//
//  IntVector_fbrAffichage.cpp
//  tp1
//
//  Created by François Bélanger on 17-09-14.
//  Copyright © 2017 François Bélanger. All rights reserved.
//

#include <iostream>

#include "IntVector.h"

using namespace std;


//Méthode pour vous aider à mettre au point votre TP.
//Elle vous donne l'état interne de votre structure de données.
//
//Inspirer d'une fonction de M. Jean Goulet.

void IntVector::afficher()
{
    cout << "État du vecteur" << endl;
    cout << "Adresse de tab: " << tab << endl;
    cout << "Taille: " << nbElem << endl;
    cout << "Capacité: " << cap << endl;
    
    size_t vide = nbElem;
    if(vide > 11)
        vide = nbElem-11;
    else
        vide = 0;
    
    size_t i;
    for(i= 0; i < nbElem; ++i)
    {
        if(i<10 || i > vide)
            cout << " " << i << ": " << tab[i] << endl;
        else
        {
            cout << "....." << endl;
            i = vide;
        }
    }
    
    if(cap > nbElem)
    {
        cout<<" "<<i;
        if(cap-nbElem>1)cout<<" a "<<cap;
        cout<<": (--en reserve--)"<<endl;
    }
    system("pause");
}
