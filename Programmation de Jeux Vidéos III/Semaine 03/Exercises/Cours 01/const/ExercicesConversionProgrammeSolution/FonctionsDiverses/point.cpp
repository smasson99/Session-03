#include "point.h"
#include <cmath> // pour sqrt plus bas


namespace FonctionsDiverses
{
  Point::Point()
  {
    // 1re m�thode d'initialisation: dans le constructeur
    x = 0;
    y = 0;
  }

  // 2e m�thode d'initialisation: avant le constructeur.  Lorsque
  // c'est possible, c'est la m�thode � privil�gier.  Ceci dit,
  // pourquoi d�j�? (difficile comme question...)
  Point::Point(int newX, int newY)
    : x(newX)
    , y(newY)
  {

  }
  
  int Point::GetX()
  {
    return x;
  }

  int Point::GetY()
  {
    return y;
  }

  float Point::GetDistanceToOrigin() const
  {
    // Pour utiliser sqrt, il faut inclure <cmath> au d�but du fichier
    return (float)sqrt(x*x+y*y);
    //return (float)sqrt(GetX()*GetX() + GetY()*GetY());
    // Nous aurions aussi pu faire
    //return sqrtf(x*x + y*y);
  }
}