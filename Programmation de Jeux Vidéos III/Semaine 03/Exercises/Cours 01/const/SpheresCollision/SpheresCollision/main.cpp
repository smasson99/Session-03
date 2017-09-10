#include <cstdlib>
#include <ctime>
#include "CollisionSphere.h"
#include <iostream>



void main()
{
  const int NB_SPHERES = 20;

  // Pour les caract�res accentu�s.
  setlocale(LC_ALL,"");
  
  // Initialisation du g�n�rateur al�atoire.
  srand((unsigned int)time(nullptr));

  CollisionSphere spheres[NB_SPHERES];

  for(int i=0;i<NB_SPHERES;i++)
  {
    for (int j = i+1;j<NB_SPHERES;j++)
    {
      if(spheres[i].CheckCollisionWith(spheres[j]))
      {
        std::cout   << "La sph�re " << i << ", rayon de " << spheres[i].GetRadius() << ", en position (" 
                    << spheres[i].GetPosX() << ", " << spheres[i].GetPosY() << "), collisionne avec \nla sph�re " 
                    << j << ", rayon de " << spheres[j].GetRadius() << ", en position (" << spheres[j].GetPosX()
                    << ", " << spheres[j].GetPosY() << ").\n\n";
      }
    }
  }
}
