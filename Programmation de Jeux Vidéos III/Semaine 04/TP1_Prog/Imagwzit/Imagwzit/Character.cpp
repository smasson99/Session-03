#include "Character.h"

/// <summary>
/// Constructeur dont le rôle est d'initialiser les variables par défaut de la classe Character
/// </summary>
Character::Character()
{
    //Initialiser les variables par défaut
    targetPos.x = 1;
    targetPos.y = 0;
}
/// <summary>
/// Fonction dont le rôle est de setter la position du personnage en x et en y
/// </summary>
/// <param name="x">La position en X</param>
/// <param name="y">La position en Y</param>
void Character::SetPosition(float x, float y)
{
    //Setter la position en x et en y
    Movable::SetPosition(x, y);
}
/// <summary>
/// Fonction dont le rôle est d'updater la position de la cible à pointer en x et en y
/// </summary>
/// <param name="x">La position de la cible en x.</param>
/// <param name="y">La position de la cible en y.</param>
void Character::UpdateTargetPosistion(float x, float y)
{
    //Setter la position de la cible en x et en y
    targetPos = sf::Vector2f(x, y);
}
/// <summary>
/// Fonction dont le rôle est de calculer l'angle pour pointer vers la cible et pointer la sprite vers celle-ci
/// </summary>
void Character::LookAtTarget()
{
    //Calculer l'angle pour pointer vers la cible
    float angle = (float)atan2((targetPos.y - GetY()), (targetPos.x - GetX()));
    //Pointer vers la cible
    currentAngle = Movable::SetRotation(angle, true);
}
