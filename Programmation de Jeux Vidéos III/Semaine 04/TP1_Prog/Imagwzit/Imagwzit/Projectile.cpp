#include "Projectile.h"

Projectile::Projectile(float x, float y, float angle, bool isRadian)
{
    enable = false;
    this->angle = angle;
    this->isRadian = isRadian;
    SetRotation(angle, isRadian);
    speed = 20.0f;
    Movable::SetPosition(x, y);
    dir = Movable::GenerateDirection(angle, isRadian);
}
/// <summary>
/// Fonction dont le rôle est de garder le projectile à jour
/// </summary>
void Projectile::Update()
{
    SetPosition(GetX()+(dir.x*speed), GetY()+(dir.y*speed));
}
/// <summary>
/// Fonction dont le rôle est de changer le status du projectile selon les paramètres reçus
/// </summary>
/// <param name="enable">Boo;éen indiquand si le projectile est enable (VRAI) ou ne l'est pas (FAUX)</param>
/// <param name="startPos">La position de départ du projectile</param>
/// <param name="angle">L'angle du projectile en degrés</param>
void Projectile::SetEnable(bool enable, sf::Vector2f startPos, float angle)
{
    //Changer le status
    this->enable = enable;
    this->angle = angle;
    SetRotation(angle, isRadian);
    SetPosition(startPos.x, startPos.y);
    dir = Movable::GenerateDirection(angle, isRadian);
}

/// <summary>
/// Retourner le status du projectile
/// </summary>
/// <returns>Booléen indiquant si le projectile est enable (VRAI) ou ne l'est pas (FAUX)</returns>
bool Projectile::IsEnable()
{
    return enable;
}
