#pragma once
#include <SFML\Graphics.hpp>
#include <ctime>

class Pokemon
{
public:
	Pokemon();
    bool Init();
    void Update(sf::RenderWindow& mainWindow);
	void SetTeleportDelay(float newDelay);
    void StartTeleport();
    void Draw(sf::RenderWindow& mainWindow);
    void SetPosition(float x, float y);
    sf::Vector2f GetPosition();
private:
	sf::Sprite sprite;
	sf::Texture pokemonTexture;
    bool teleportLaunched;
    float teleportDelay;
    time_t clockT;
    time_t timePassed;
    time_t timePassedSeconds;
    float RandNext(int min, int maxExcluded);
};