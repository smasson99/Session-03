#include "Joueur.h"

using namespace platformer;

Joueur::Joueur() : persoRect(0, 0, TAILLE_RECT, TAILLE_RECT)
{
}

Joueur::~Joueur()
{
    delete animMoveLeft;
    delete animMoveRight;
}

bool Joueur::init(const int limiteGauche, const int limiteDroite, const String texturePath, const String movePath, const bool moveLeft, const String idlePath)
{
	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}
    if (!animMoveLeftTexture.loadFromFile(movePath))
    {
        return false;
    }
    if (!animMoveRightTexture.loadFromFile(movePath))
    {
        return false;
    }

    if (moveLeft)
    {
        flipMoveLeft = false;
        flipMoveRight = true;
    }
    else
    {
        flipMoveLeft = true;
        flipMoveRight = false;
    }

    animMoveRight = new Animation(animMoveRightTexture, 0.5f, true);


	setTexture(texture);
	setTextureRect(persoRect);
	setOrigin(TAILLE_RECT / 2, TAILLE_RECT /2);

	this->limiteGauche = limiteGauche + TAILLE_RECT / 4;
	this->limiteDroite = limiteDroite - TAILLE_RECT / 4;

	return true;
}

void Joueur::move(const int direction)
{
	if (direction == 1)
	{
		Sprite::move(vitesse, 0);
        /*Droite*/
        setTexture(animMoveLeftTexture);
        if (flipMoveRight)
        {
            setScale(-1, 1);
        }
        animPlayer.Play(animMoveRight);
        setTextureRect(animPlayer.GetRect());
	}
	else if (direction == -1)
	{
		Sprite::move(-vitesse, 0);
        /*Gauche*/

	}

	//Test sur les limites de l'écran
	if (getPosition().x < limiteGauche)
	{
		setPosition(limiteGauche, getPosition().y);
	}
	else if (getPosition().x > limiteDroite)
	{
		setPosition(limiteDroite, getPosition().y);
	}
}