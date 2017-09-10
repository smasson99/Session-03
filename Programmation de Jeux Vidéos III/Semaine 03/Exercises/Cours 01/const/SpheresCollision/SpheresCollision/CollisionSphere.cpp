#include "CollisionSphere.h"
#include <math.h>
#include <cstdlib>

const int SURFACE_WIDTH = 1360;
const int SURFACE_HEIGHT = 720;
const int MIN_RADIUS = 20;
const int MAX_RADIUS = 200;

CollisionSphere::CollisionSphere()
{
  radius = 0.0f;
  posX = posY = 0.0f;

  Randomize();
}

bool CollisionSphere::CheckCollisionWith(CollisionSphere& other) const
{
  // Calcul de la distance entre les deux centres des sph�res
  // Pythagore bien standard
  float lineX = posX - other.GetPosX();
  float lineY = posY - other.GetPosY();
  float distance = sqrtf(lineX*lineX-lineY*lineY);

  // Les sph�res entrent en collision si la distance entre les deux centres
  // est inf�rieure � la somme des rayons.
  return (distance<(GetRadius() + other.GetRadius()));
}

float CollisionSphere::GetRadius() const
{
    return radius;
}

float CollisionSphere::GetPosX() const
{
    return posX;
}

float CollisionSphere::GetPosY() const
{
  return posY;
}

void CollisionSphere::Randomize()
{
  // Plusieurs fa�ons de faire.  
  // Ne pas oublier de mettre le srand dans le main
  
  // Rayon al�atoire
  radius = (float) rand() / (float) RAND_MAX *(MAX_RADIUS-MIN_RADIUS) + MIN_RADIUS;

  // PosX al�atoire
  posX = (float)rand() / (float)RAND_MAX * (SURFACE_WIDTH-2*radius) + radius;

  // PosY al�atoire
  posY = (float)rand() / (float)RAND_MAX * (SURFACE_HEIGHT - 2*radius) + radius;

}
