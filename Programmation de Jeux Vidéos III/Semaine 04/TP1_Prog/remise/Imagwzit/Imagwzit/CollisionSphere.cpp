#include <cmath>  //sqrt
#include <cstdlib> //rand
#include "CollisionSphere.h"

/// <summary>
/// Constructeur dont le rôle est d'initialiser une nouvelle instance par défaut de la classe <see cref="CollisionSphere"/>.
/// </summary>
CollisionSphere::CollisionSphere()
{
    //Initialisation des variables
	this->rayon = 1;
	this->posX = 0;
	this->posY = 0;
}
/// <summary>
/// Constructeur dont le rôle est d'initialiser une nouvelle instance de la classe <see cref="CollisionSphere"/> selon les paramètres entrés.
/// </summary>
/// <param name="rayon">Le rayon de la sphère de collision</param>
/// <param name="posX">La position en x de la sphère</param>
/// <param name="posY">La position en y de la sphère</param>
CollisionSphere::CollisionSphere(const float rayon, const float posX, const float posY)
{
    //Initialisation des variables
	this->rayon = rayon;
	this->posX = posX;
	this->posY = posY;
}
/// <summary>
/// Fonction dont le rôle est de vérifier les collisiont avec une autre sphère et de retourner s'il y a collision ou non.
/// </summary>
/// <param name="autreSphere">La sphère à examiner</param>
/// <returns>Booléen inquidant si la sphère entre en collision avec celle entrée en paramètre (true) ou pas (false)</returns>
bool CollisionSphere::verifierCollision(const CollisionSphere &autreSphere) const
{
    //Effectuer les calculs
	float LigneX = this->posX - autreSphere.posX;
	float LigneY = this->posY - autreSphere.posY;

	float distance = sqrt(LigneX * LigneX + LigneY * LigneY);

	//Deux sphères qui se touchent mais ne sont pas en 
	//intersection en sont pas considérées en collision
	if (distance < this->rayon + autreSphere.rayon)
	{
		return true;
	}

	return false;
}
/// <summary>
/// Fonction dont le rôle est de changer la valueur du rayon de la sphère de collision
/// </summary>
/// <param name="rayon">La nouvelle valeur en float du rayon</param>
void CollisionSphere::SetRayon(float rayon)
{
    //Assigner la nouvelle valeur
    this->rayon = rayon;
}
/// <summary>
/// Fonction dont le rôle est de setter une nouvelle position à la sphère de collision
/// </summary>
/// <param name="x">La position en X</param>
/// <param name="y">La position en Y</param>
void CollisionSphere::SetPosition(float x, float y)
{
    //Assigner les nouvelles valeurs
    posX = x;
    posY = y;
}
/// <summary>
/// Fonction dont le rôle est de retourner le rayon de la sphère de collision courante.
/// </summary>
/// <returns>float représentant la valeur du rayon</returns>
float CollisionSphere::getRayon() const
{
    //Retourner le rayon
	return rayon;
}
/// <summary>
/// Fonction dont le rôle est de retourner la valeur de la position de la sphère en X
/// </summary>
/// <returns>float.représentant la position de la sphère en X</returns>
float CollisionSphere::getPosX() const
{
    //Retourner la position en X
	return posX;
}
/// <summary>
/// Fonction dont le rôle est de retourner la valeur de la position de la sphère en Y
/// </summary>
/// <returns>float.représentant la position de la sphère en Y</returns>
float CollisionSphere::getPosY() const
{
    //Retourner la position en Y
	return posY;
}
