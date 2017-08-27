#include <iostream>
#include <time.h>       /* time */
#include <stdlib.h>     /* srand, rand */

#include "point.h"
using namespace FonctionsDiverses;

void main()
{
  Point p1; // Attention, pas de new!!!

  // Génération de nombres aléatoires c++:
  // - On utilise la fonction rand dans le fichier d'entête <stdlib.h>
  // - Il ne faut pas oublier d'initialiser AVANT le générateur de nombres aléatoires

  // Initialisation du générateur de nombres:
  // Une valeur fixe va produire toujours la même séquence de nombres aléatoires.
  // srand(1234);
  // une valeur basée sur le temps va faire en sorte que la séquence variera à chaque exécution
  // La fonction time se trouve dans le fichier d'entête <time.h>
  srand((unsigned int)time(NULL));

  int p2X = rand();
  int p2Y = rand();
  Point p2(p2X, p2Y); // Pas de new!!!

  std::cout << "La distance entre le point 1 et l'origine est " << p1.GetDistanceToOrigin() << std::endl;
  std::cout << "La distance entre le point 2 et l'origine est " << p2.GetDistanceToOrigin() << std::endl;
}