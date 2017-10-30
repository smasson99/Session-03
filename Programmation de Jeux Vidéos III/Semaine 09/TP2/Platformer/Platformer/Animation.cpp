#include "Animation.h"

using namespace platformer;

/// <summary>
/// Constructeur d'une animation simple a une ligne.
/// </summary>
Animation::Animation(Texture& textureSheet, float duration, bool isCircular)
{
    /*Assignation/Initialisation des variables 
    de base.*/
    this->textureSheet = textureSheet;
    this->duration = duration;
    this->isCircular = isCircular;
}

/// <summary>
/// Retourne la durée entre chaque frame de l'animation.
/// </summary>
/// <returns>float.</returns>
float Animation::GetDuration()
{
    /*La durée de play d'une frame est 
    reçue dans le constructeur. */
    return duration;
}

/// <summary>
/// Retourne un réel indiquant la hauteur d'une frame de l'animation.
/// </summary>
/// <returns>Réel indiquant la hauteur d'une frame de l'animation.</returns>
float platformer::Animation::GetFrameHeight()
{
    /*Une seule ligne d'animation, la hauteur 
    est donc la hauteur de la texture*/
    return textureSheet.getSize().y;
}

/// <summary>
/// Retourne un réel indiquant la largeur d'une frame de l'animation.
/// </summary>
/// <returns>Réel indiquant la largeur d'une frame de l'animation.</returns>
float platformer::Animation::GetFrameWidth()
{
    /*Nous assumons ici que chaque frame est
    carrée.*/
    return textureSheet.getSize().y;
}

/// <summary>
/// Retourne un entier indiquant le nombre de frames de l'animation.
/// </summary>
/// <returns>Entier indiquant le nombre de frames de l'animation.</returns>
int platformer::Animation::GetFrameCount()
{
    /*Nous retournons le nombre de frames 
    de l'animation en divisant la largeur de
    la spritesheet par la hauteur d'une seule 
    frame.*/
    return textureSheet.getSize().x/GetFrameHeight();
}

/// <summary>
/// Fonction dont le rôle est de retourner si l'animation en 
/// question circulaire (TRUE) ou ne l'est pas (FALSE).
/// </summary>
/// <returns>Booléen indiquant si l'animation est circulaire (VRAI)
/// ou ne l'est pas (FALSE).</returns>
bool platformer::Animation::IsCircularAnimation()
{
    /*Est-ce que nous repartons de début après 
    avoir atteint la fin de la ligne de frames ?*/
    return isCircular;
}
