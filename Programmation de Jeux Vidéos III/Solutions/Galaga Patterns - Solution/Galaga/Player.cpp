#include "Player.h"

using namespace galaga;

Player *Player::instance = nullptr;

Player::Player()
{

}

Player* Player::getInstance()
{
	if (!instance)
		instance = new Player();
	return instance;
}

void Player::release()
{
	delete instance;
	instance = nullptr;
}

void Player::initialiser(const float posX, const float posY, const float vitesse, RenderWindow* const renderWindow)
{
	setPosition(posX, posY);
	this->vitesse = vitesse;
	this->renderWindow = renderWindow;
}

bool Player::chargerTexture(const char texturePath[])
{
	//Chargement du fichier de texture
	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}

	texture.setSmooth(true);

	ajustementsVisuels();

	return true;
}

void Player::ajustementsVisuels()
{
	setTexture(texture);   //Placement de la texture dans le sprite
	setOrigin(texture.getSize().x / 2, texture.getSize().x / 2);
	setPosition(getPosition().x, renderWindow->getSize().y - texture.getSize().y / 2);

	limiteGauche = texture.getSize().x / 2;
	limiteDroite = renderWindow->getSize().x - texture.getSize().x / 2;
}

void Player::deplacement(bool aDroite)
{
	if (aDroite)
	{
		move(vitesse, 0);
	}
	else
	{
		move(-vitesse, 0);
	}

	if (getPosition().x < limiteGauche)
	{
		setPosition(limiteGauche, getPosition().y);
	}
	else if (getPosition().x > limiteDroite)
	{
		setPosition(limiteDroite, getPosition().y);
	}
}