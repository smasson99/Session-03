#include "GameObject.h"

GameObject::GameObject()
{
    //Initialisation des variables par défaut
    enable = false;
}

void GameObject::SetEnabled(bool enable, float x, float y)
{
    //Changer les valeurs selon les paramètres entrés
    this->enable = enable;
    SetPosition(x, y);
}

void GameObject::SetEnabled(bool enable)
{
    //Changer le status
    this->enable = enable;
}


bool GameObject::IsEnable() const
{
    //Retourner le status
    return enable;
}
