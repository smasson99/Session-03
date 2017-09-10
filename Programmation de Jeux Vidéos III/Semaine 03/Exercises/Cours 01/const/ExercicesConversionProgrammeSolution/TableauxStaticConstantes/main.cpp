#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
const int NB_ELEMENTS_TABLEAUX = 10;
// ou, selon la m�thode proche du langage C, 
// #define NB_ELEMENTS_TABLEAUX 10


// Il faut que les fonctions soient connues avant de pouvoir les utiliser!
void InitaliserTableau(int tab[]);

void main()
{
  // Attention. Le tableau ne sera pas initialis�.
  int tab[NB_ELEMENTS_TABLEAUX];

  InitaliserTableau(tab);
  

  std::stringstream ss;
  for (int i = 0; i < NB_ELEMENTS_TABLEAUX; i++)
  {
    ss << tab[i] << " ";
  }

  std::cout << ss.str() << std::endl;
}

// Quel est le mode de passage de param�tre de tab ici?
void InitaliserTableau(int tab[])
{
  static bool premiereFois = true;

  if (premiereFois)
  {
    // G�n�ration al�atoire
    srand((unsigned int)time(NULL));
    
    premiereFois=false;
  }
  
  // Attention! Pas de .length en C++. tab n'est qu'un emplacement m�moire, pas un objet
  for (int i = 0; i < NB_ELEMENTS_TABLEAUX; i++)
  {
    tab[i] = (int)(10.0f * (float)rand() / (float)RAND_MAX);
  }
}