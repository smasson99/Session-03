#include "pokeball.h"


Pokeball::Pokeball()
{
    //Initialisations des variables & des status
    sprite.setOrigin(50, 50);
    justFollow = false;
}

bool Pokeball::Init()
{
    //Tenter de loader la texture
    if (pokeballTexture.loadFromFile("Assets\\Sprites\\Pokeball.png"))
    {
        sprite.setTexture(pokeballTexture);
        return true;
    }
    else
        return false;
}

bool Pokeball::Update(InputManager& inputManager, Pokemon pokemon)
{
    if (inputManager.GetMouseClicked() == true)
    {
        //En assumant que la balle est un cercle...
        float radius = sprite.getLocalBounds().width / 2;
        if (justFollow == false)
        {
            //SetPosition(inputManager.GetMouseX(), inputManager.GetMouseY());
            if (sprite.getPosition().x + radius >= inputManager.GetMouseX() &&
                sprite.getPosition().x - radius <= inputManager.GetMouseX() &&
                sprite.getPosition().y + radius >= inputManager.GetMouseY() &&
                sprite.getPosition().y - radius <= inputManager.GetMouseY())
            {
                SetPosition(inputManager.GetMouseX(), inputManager.GetMouseY());
                justFollow = true;
            }
        }
        else
            SetPosition(inputManager.GetMouseX(), inputManager.GetMouseY());
        //Déterminer si on touche le pokemon
        if (
            sprite.getPosition().x + radius >= pokemon.GetPosition().x &&
            sprite.getPosition().x - radius <= pokemon.GetPosition().x &&
            sprite.getPosition().y + radius >= pokemon.GetPosition().y &&
            sprite.getPosition().y - radius <= pokemon.GetPosition().y
            )
        {
            return true;
        }


    }
    else
        justFollow = false;
    return false;
}

void Pokeball::SetPosition(float x, float y)
{
    //Setter la position de la sprite
    sprite.setPosition(sf::Vector2f(x, y));
}

void Pokeball::Draw(sf::RenderWindow& mainWindow)
{
    //Dessiner la sprite à l'écran
    mainWindow.draw(sprite);
}