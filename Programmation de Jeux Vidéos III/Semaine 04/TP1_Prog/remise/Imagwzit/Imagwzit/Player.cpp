#include "Player.h"

/// <summary>
/// Constructeur dont le r�le est d'initialiser les variables par d�faut du joueur.
/// </summary>
Player::Player()
{
    //Initialisation des varaibles par d�faut
    nbHealthPoints = 5;
    shootDelay = sf::seconds(0.15f);
    immortalDelay = sf::seconds(3.0f);
    isHit = false;
}
/// <summary>
/// Fonction dont le r�le est de retourner si le joueur peut tirer ou non
/// </summary>
/// <returns>Bool�en indiquant True si le joueur peut tirer et False s'il ne peut pas</returns>
bool Player::CanFire()
{
    if (!isHit && shootClock.getElapsedTime().asSeconds() > shootDelay.asSeconds())
    {
        shootClock.restart();
        return true;
    }
    else
    {
        return false;
    }
}
/// <summary>
/// Indiquer si le joueur est immortel ou non
/// </summary>
/// <returns>bool�en indiquant Vrai si le joueur est immortel et Faux s'il ne l'est pas</returns>
bool Player::IsImmortal()
{
    return isHit;
}
/// <summary>
/// Fonction dont le r�le est de retourner l'angle du joueur
/// </summary>
/// <returns>float.repr�sentant l'angle courante du joueur en degr�s</returns>
float Player::GetAngle()
{
    return currentAngle;
}
/// <summary>
/// Fonction dont le r�le est de mettre � jour le joueur selon les param�tres re�us
/// </summary>
/// <param name="x">Position de la cible en X</param>
/// <param name="y">Position de la cible en Y</param>
void Player::Update(float x, float y)
{
    //Mettre � jour la position de de la cible
    UpdateTargetPosistion(x, y);
    //S'assurer de pointer vers la cible (qui dans ce cas-ci devrait �tre la souris)
    LookAtTarget();
    //Dans le cas o� le joueur a �t� touch� et que son temps de r�pit est pass�
    if (isHit && immortalClock.getElapsedTime().asSeconds() > immortalDelay.asSeconds())
    {
        //Rendre mortel
        isHit = false;
        SetTransparencyAlpha(255.0f);
    }
}
/// <summary>
/// Retourner un nouveau projectile
/// </summary>
/// <returns>Projectile.repr�sentant le nouveau projectile</returns>
Projectile Player::CreateProjectile()
{
    //Retourner un projectile selon le standard
    return Projectile(GetX(), GetY(), currentAngle, false);
}

/// <summary>
/// Fonction dont le r�le est de retourner le nombre de points de vie du joueur
/// </summary>
/// <returns>entier repr�sentant.le nombre de points de vie du joueur</returns>
int Player::GetHealthPoints() const
{
    return nbHealthPoints;
}
/// <summary>
/// Fonction dont le r�le est de faire subir des d�g�ts au joueur
/// </summary>
void Player::Hit()
{
    if (nbHealthPoints > 0)
        nbHealthPoints--;
    isHit = true;
    SetTransparencyAlpha(255.0f/2);
    immortalClock.restart();
}
/// <summary>
/// Fonction dont le r�le est d'ajouter un certains nombre de points de vie au joueur
/// </summary>
/// <param name="nb">The nb.</param>
void Player::AddHealthPoints(int nb)
{
    nbHealthPoints += nb;
}

