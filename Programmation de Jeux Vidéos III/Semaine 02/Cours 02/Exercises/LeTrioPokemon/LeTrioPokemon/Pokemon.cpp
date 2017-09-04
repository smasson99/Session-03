#include "Pokemon.h"
#include <time.h>

bool Pokemon::Init()
{
    //Loader les assets
    if (pokemonTexture.loadFromFile("Assets\\Sprites\\Bulbasaur.png"))
    {
        sprite.setTexture(pokemonTexture);
        return true;
    }
    else
        return false;
    return true;
}

Pokemon::Pokemon()
{
    //Initialisation des valeurs par défaut
    teleportDelay = 0.5f;
    srand(clock());
}

void Pokemon::SetTeleportDelay(float newDelay)
{
    teleportDelay = newDelay;
}

void Pokemon::StartTeleport()
{
    //Prendre en note la valeur temporelle au moment du lancement du timer:
    clockT = clock();
    teleportLaunched = true;
}

float Pokemon::RandNext(int min, int maxExcluded)
{
    return (rand() % (maxExcluded - min) + min);
}

void Pokemon::Update(sf::RenderWindow& mainWindow)
{
    timePassed = clock() - clockT;
    timePassedSeconds = timePassed / CLOCKS_PER_SEC;
    if (teleportLaunched)
    {
        if (teleportDelay <= timePassedSeconds)
        {
            //Générer position aléatoire et placer le pokemon à l'endroit choisie
            float nPosX = RandNext(0.00f + sprite.getScale().x, mainWindow.getSize().x - sprite.getScale().x -20);
            float nPosY = RandNext(0.00f + sprite.getScale().y, mainWindow.getSize().y - sprite.getScale().y - 20);
            SetPosition(nPosX, nPosY);
            //Reseter le timer
            clockT = clock();
        }
    }
}

void Pokemon::SetPosition(float x, float y)
{
    sprite.setPosition(sf::Vector2f(x, y));
}

void Pokemon::Draw(sf::RenderWindow& mainWindow)
{
    //Afficher la sprite à l'écran
    mainWindow.draw(sprite);
}

sf::Vector2f Pokemon::GetPosition()
{
    return sprite.getPosition();
}