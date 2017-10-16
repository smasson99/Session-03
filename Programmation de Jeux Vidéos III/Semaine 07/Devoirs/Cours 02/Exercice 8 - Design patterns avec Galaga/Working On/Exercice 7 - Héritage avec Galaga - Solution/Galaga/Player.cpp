#include "Player.h"

using namespace galaga;

Player* Player::instance = nullptr;

Player::Player()
{
    
}

Player * galaga::Player::GetInstance()
{
    if (!instance)
        instance = new Player();
    return instance;
}

Player::~Player()
{
    delete instance;
    instance = nullptr;
    delete renderWindow;
    renderWindow = nullptr;
}

void galaga::Player::Initialiser(const float posX, const float posY, const float vitesse, RenderWindow * renderWindow)
{
    setPosition(posX, posY);
    this->vitesse = vitesse;
    this->renderWindow = renderWindow;
    limiteGauche = 0;
    limiteDroite = renderWindow->getSize().x/1.05;
}

bool galaga::Player::chargerTexture(const char texturePath[])
{
    bool init = texture.loadFromFile(texturePath);
    texture.setSmooth(true);
    setTexture(texture);
    return init;
}

void galaga::Player::deplacement(const bool aDroite)
{
    if (aDroite)
    {
        move(Vector2f(vitesse, 0));
    }
    else
    {
        move(Vector2f(-vitesse, 0));
    }
}

int galaga::Player::GetLimiteDroite()
{
    return limiteDroite;
}

int galaga::Player::GetLimiteGauche()
{
    return limiteGauche;
}
