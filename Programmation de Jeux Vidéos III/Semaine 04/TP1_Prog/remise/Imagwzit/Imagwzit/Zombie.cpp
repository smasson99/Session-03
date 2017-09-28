#include "Zombie.h"

Zombie::Zombie()
{
    //Initialisation des variables par d�faut
    enable = false;
    speed = 1.0f;
}
/// <summary>
/// Fonction dont le r�le est de mettre � jour le zombie selon les param�tres re�us
/// </summary>
/// <param name="playerX">La position en X du joueur</param>
/// <param name="playerY">La position en Y du joueur</param>
void Zombie::Update(float playerX, float playerY)
{
    //Mettre � jour la position de de la cible
    UpdateTargetPosistion(playerX, playerY);
    //S'assurer de pointer vers la cible (qui dans ce cas-ci devrait �tre la souris)
    LookAtTarget();
    dir = GenerateDirection(currentAngle, false);
    SetPosition(GetX() + (dir.x*speed), GetY() + (dir.y*speed));
}
/// <summary>
/// Fonction dont le r�le est de changer le status du zombie et de changer sa position.
/// </summary>
/// <param name="enable">True si enable, False si disable</param>
/// <param name="x">La nouvelle position en X du zombie</param>
/// <param name="y">La nouvelle position en Y du zombie</param>
void Zombie::SetEnabled(bool enable, float x, float y)
{
    this->enable = enable;
    SetPosition(x, y);
}
/// <summary>
/// Retourner le status du zombie
/// </summary>
/// <returns>Bool�en indiquant si le zombie est enable (VRAI) ou ne l'est pas (FAUX)</returns>
bool Zombie::IsEnable() const
{
    return enable;
}
