#include <iostream>
#include <time.h>       /* time */
#include <stdlib.h>     /* srand, rand */

#include "point.h"
using namespace FonctionsDiverses;

void main()
{
  Point p1; // Attention, pas de new!!!

  // G�n�ration de nombres al�atoires c++:
  // - On utilise la fonction rand dans le fichier d'ent�te <stdlib.h>
  // - Il ne faut pas oublier d'initialiser AVANT le g�n�rateur de nombres al�atoires

  // Initialisation du g�n�rateur de nombres:
  // Une valeur fixe va produire toujours la m�me s�quence de nombres al�atoires.
  // srand(1234);
  // une valeur bas�e sur le temps va faire en sorte que la s�quence variera � chaque ex�cution
  // La fonction time se trouve dans le fichier d'ent�te <time.h>
  srand((unsigned int)time(NULL));

  int p2X = rand();
  int p2Y = rand();
  Point p2(p2X, p2Y); // Pas de new!!!

  std::cout << "La distance entre le point 1 et l'origine est " << p1.GetDistanceToOrigin() << std::endl;
  std::cout << "La distance entre le point 2 et l'origine est " << p2.GetDistanceToOrigin() << std::endl;
}