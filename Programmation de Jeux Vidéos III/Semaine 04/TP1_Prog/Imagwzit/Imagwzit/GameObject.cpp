#include "GameObject.h"

GameObject::GameObject()
{
    //Initialisation des variables par d�faut
    enable = false;
}

void GameObject::SetEnabled(bool enable, float x, float y)
{
    //Changer les valeurs selon les param�tres entr�s
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
