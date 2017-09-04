#pragma once
#include<SFML\Graphics.hpp>
#include "InputManager.h"
#include "Pokemon.h"

class Pokeball
{
    //Le publique
public:
	bool Init();
	Pokeball();
    bool Update(InputManager& inputManager, Pokemon pokemon);
	void SetPosition(float x, float y);
    void Draw(sf::RenderWindow& mainWindow);
    //Le privé
private:
	sf::Sprite sprite;
	sf::Texture pokeballTexture;
    bool justFollow;
};