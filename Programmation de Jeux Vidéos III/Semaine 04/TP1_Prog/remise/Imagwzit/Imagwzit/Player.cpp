#include "Player.h"

/// <summary>
/// Constructeur dont le rôle est d'initialiser les variables par défaut du joueur.
/// </summary>
Player::Player()
{
    //Initialisation des varaibles par défaut
    nbHealthPoints = 5;
    shootDelay = sf::seconds(0.15f);
    immortalDelay = sf::seconds(3.0f);
    isHit = false;
}
/// <summary>
/// Fonction dont le rôle est de retourner si le joueur peut tirer ou non
/// </summary>
/// <returns>Booléen indiquant True si le joueur peut tirer et False s'il ne peut pas</returns>
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
/// <returns>booléen indiquant Vrai si le joueur est immortel et Faux s'il ne l'est pas</returns>
bool Player::IsImmortal()
{
    return isHit;
}
/// <summary>
/// Fonction dont le rôle est de retourner l'angle du joueur
/// </summary>
/// <returns>float.représentant l'angle courante du joueur en degrés</returns>
float Player::GetAngle()
{
    return currentAngle;
}
/// <summary>
/// Fonction dont le rôle est de mettre à jour le joueur selon les paramètres reçus
/// </summary>
/// <param name="x">Position de la cible en X</param>
/// <param name="y">Position de la cible en Y</param>
void Player::Update(float x, float y)
{
    //Mettre à jour la position de de la cible
    UpdateTargetPosistion(x, y);
    //S'assurer de pointer vers la cible (qui dans ce cas-ci devrait être la souris)
    LookAtTarget();
    //Dans le cas où le joueur a été touché et que son temps de répit est passé
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
/// <returns>Projectile.représentant le nouveau projectile</returns>
Projectile Player::CreateProjectile()
{
    //Retourner un projectile selon le standard
    return Projectile(GetX(), GetY(), currentAngle, false);
}

/// <summary>
/// Fonction dont le rôle est de retourner le nombre de points de vie du joueur
/// </summary>
/// <returns>entier représentant.le nombre de points de vie du joueur</returns>
int Player::GetHealthPoints() const
{
    return nbHealthPoints;
}
/// <summary>
/// Fonction dont le rôle est de faire subir des dégâts au joueur
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
/// Fonction dont le rôle est d'ajouter un certains nombre de points de vie au joueur
/// </summary>
/// <param name="nb">The nb.</param>
void Player::AddHealthPoints(int nb)
{
    nbHealthPoints += nb;
}

