#include "GameObject.h"

/// <summary>
/// Constructeur initialisant les variables par d�faut de l'objet
/// </summary>
GameObject::GameObject()
{
    //Initialisation des variables par d�faut
    enable = false;
}
/// <summary>
/// Fonction dont le r�le est de changer le status de l'objet et de changer sa position.
/// </summary>
/// <param name="enable">True si enable, False si disable</param>
/// <param name="x">La nouvelle position en X de l'objet</param>
/// <param name="y">La nouvelle position en Y de l'objet</param>
void GameObject::SetEnabled(bool enable, float x, float y)
{
    //Changer les valeurs selon les param�tres entr�s
    this->enable = enable;
    SetPosition(x, y);
}

/// <summary>
/// Fonction dont le r�le est de changer le status de l'objet 
/// </summary>
/// <param name="enable">True si enable, False si disable.</param>
void GameObject::SetEnabled(bool enable)
{
    //Changer le status
    this->enable = enable;
}

/// <summary>
/// Retourner le status de l'objet
/// </summary>
/// <returns>True si enable, False si disable</returns>
bool GameObject::IsEnable() const
{
    //Retourner le status
    return enable;
}
