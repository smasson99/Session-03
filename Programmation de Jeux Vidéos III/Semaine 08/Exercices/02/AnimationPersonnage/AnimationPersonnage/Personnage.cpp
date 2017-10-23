#include "Personnage.h"

using namespace isometrique;

Texture Personnage::texture; //Initialisation de notre texture (appel du constructeur par défaut - hmmm "défaut" le beau mot de vocabulaire qui soit, comme le dirait un grand sage: https://www.youtube.com/watch?v=RhvIISDoarU)

Personnage::Personnage(const float posX, const float posY, RenderWindow  * const renderWindow) : renderWindow(renderWindow)
{
	cadran = 6;  //On décide qu'au déaprt, notre personnage regarde vers le bas
    frameCourante = 0;
    animRate = 0.25f;
    isRightFrameIdle = true;
	setPosition(posX, posY);
}

Personnage::~Personnage()
{
	//On commence par effacer chaque "tableau dans les tableaux"
	for (int i = 0; i < NBR_MIVEAUX; i++)
	{
		delete[] intRectsImmobile[i];
		delete[] intRectsMouvement[i];
	}

	//Puis on efface les tableaux extérieurs
	delete[] intRectsImmobile;
	delete[] intRectsMouvement;
}

bool Personnage::chargerTextures(const char texturePath[])
{
	//Chargement du fichier de texture
	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}

	texture.setSmooth(true);
	return true;
}

void Personnage::ajustementsVisuels()
{
	setTexture(texture);   //Placement de la texture dans le sprite
	
	intRectsImmobile = new IntRect*[NBR_MIVEAUX];  //Tableaux de frames à deux dimensions dépendant du nombre d'animations
	intRectsMouvement = new IntRect*[NBR_MIVEAUX];  //On a une série d'animation pour chaque direction

    //Pour chaque direction donc...
	for (int i = 0; i < NBR_MIVEAUX; i++)
	{
		intRectsImmobile[i] = new IntRect[NBR_ANIMS_IMMOBILE]; //On se fait des tableaux pour les niveaux individuelles
		intRectsMouvement[i] = new IntRect[NBR_ANIMS_MOUVEMENT];

		int largeur = texture.getSize().x / NBR_ANIMS; //On calcule la largeur et la hauteur à partir de la taille de la texture
		int hauteur = texture.getSize().y / NBR_MIVEAUX; //et des nombres d'animations

		//Taille et position de chacun des rectangles
		for (int j = 0; j < NBR_ANIMS_IMMOBILE; j++)
		{	
			intRectsImmobile[i][j].left = largeur * j;
			intRectsImmobile[i][j].top = hauteur * i;
			intRectsImmobile[i][j].width = largeur;
			intRectsImmobile[i][j].height = hauteur;
		}

		//Taille et position de chacun des rectangles
		for (int j = 0; j < NBR_ANIMS_MOUVEMENT; j++)
		{
			intRectsMouvement[i][j].left = largeur * (j + NBR_ANIMS_IMMOBILE);  //NBR_ANIMS_IMMOBILE: offset en X, là où commence les anims de course.
			intRectsMouvement[i][j].top = hauteur * i;
			intRectsMouvement[i][j].width = largeur;
			intRectsMouvement[i][j].height = hauteur;
		}
	}

    UpdateAnim(cadran, frameCourante, intRectsImmobile);
    //Comme tous les rectangles on la même taille, on prend le premier
    setOrigin(intRectsImmobile[0][0].height / 2, intRectsImmobile[0][0].width / 2);
}

void Personnage::gererInputs()
{
	//Si le Gamepad est connecté, on l'utilise
	if (Joystick::isConnected(0))
	{
		joystickMovement();
	}

	//Sinon on se rabat sur le clavier
	else
	{
		keyboardMovement();
	}
}

void Personnage::keyboardMovement()
{
	//Avec le clavier les directions sont franches
	//La technique ci-dessous permet d'éviter les comportents ou si par exemple le joueur appui à la fois en haut et en bas, que aritrairement une des deux directions soit choisie

	int moveMap = 0;

	//On enregistre binairement chacune des touches de direction appuyé.
	if (Keyboard::isKeyPressed(Keyboard::Right)) moveMap |= 1;
	if (Keyboard::isKeyPressed(Keyboard::Left)) moveMap |= 2;
	if (Keyboard::isKeyPressed(Keyboard::Up)) moveMap |= 4;
	if (Keyboard::isKeyPressed(Keyboard::Down)) moveMap |= 8;

	switch (moveMap)
	{
		//Si on a une direction franche, c'est facile
        //Droite
	case 1:
		interfaceDeplacement.x = CLAVIER_DROITE;
		interfaceDeplacement.y = 0.0f;
        if (cadran != 4)
        {
            cadran = 4;
            frameCourante = 0;
        }
        else
        {
            frameCourante+=animRate;
            if (frameCourante > NBR_ANIMS_MOUVEMENT-1)
                frameCourante = 0;
        }
        isIdle = false;
		break;
        //Gauche
	case 2:
		interfaceDeplacement.x = -CLAVIER_DROITE;
		interfaceDeplacement.y = 0.0f;
        if (cadran != 0)
        {
            cadran = 0;
            frameCourante = 0;
        }
        else
        {
            frameCourante += animRate;
            if (frameCourante > NBR_ANIMS_MOUVEMENT - 1)
                frameCourante = 0;
        }
        isIdle = false;
		break;
        //Haut
	case 4:
		interfaceDeplacement.x = 0.0f;
		interfaceDeplacement.y = -CLAVIER_DROITE;
        if (cadran != 2)
        {
            cadran = 2;
            frameCourante = 0;
        }
        else
        {
            frameCourante += animRate;
            if (frameCourante > NBR_ANIMS_MOUVEMENT - 1)
                frameCourante = 0;
        }
        isIdle = false;
		break;
        //Bas
	case 8:
		interfaceDeplacement.x = 0.0f;
		interfaceDeplacement.y = CLAVIER_DROITE;
        if (cadran != 6)
        {
            cadran = 6;
            frameCourante = 0;
        }
        else
        {
            frameCourante += animRate;
            if (frameCourante > NBR_ANIMS_MOUVEMENT - 1)
                frameCourante = 0;
        }
        isIdle = false;
		break;

		//Les chiffres suivants représentes deux bits qui reprententent chaucn une direction, qui
		//ensemble font sens.
        //Haut-Droite
	case 5:
		interfaceDeplacement.x = CLAVIER_DIAGONALE;
		interfaceDeplacement.y = -CLAVIER_DIAGONALE;
        if (cadran != 3)
        {
            cadran = 3;
            frameCourante = 0;
        }
        else
        {
            frameCourante += animRate;
            if (frameCourante > NBR_ANIMS_MOUVEMENT - 1)
                frameCourante = 0;
        }
        isIdle = false;
		break;
        //Bas-Droite
	case 9:
		interfaceDeplacement.x = CLAVIER_DIAGONALE;
		interfaceDeplacement.y = CLAVIER_DIAGONALE;
        if (cadran != 5)
        {
            cadran = 5;
            frameCourante = 0;
        }
        else
        {
            frameCourante += animRate;
            if (frameCourante > NBR_ANIMS_MOUVEMENT - 1)
                frameCourante = 0;
        }
        isIdle = false;
		break;
        //Haut-Gauche
	case 6:
		interfaceDeplacement.x = -CLAVIER_DIAGONALE;
		interfaceDeplacement.y = -CLAVIER_DIAGONALE;
        if (cadran != 1)
        {
            cadran = 1;
            frameCourante = 0;
        }
        else
        {
            frameCourante += animRate;
            if (frameCourante > NBR_ANIMS_MOUVEMENT - 1)
                frameCourante = 0;
        }
        isIdle = false;
		break;
        //Bas-Gauche
	case 10:
		interfaceDeplacement.x = -CLAVIER_DIAGONALE;
		interfaceDeplacement.y = CLAVIER_DIAGONALE;
        if (cadran != 7)
        {
            cadran = 7;
            frameCourante = 0;
        }
        else
        {
            frameCourante += animRate;
            if (frameCourante > NBR_ANIMS_MOUVEMENT - 1)
                frameCourante = 0;
        }
        isIdle = false;
		break;
        //Aucun Mouvement (IDLE)
	default:
		interfaceDeplacement.x = 0;
		interfaceDeplacement.y = 0;
        if (!isIdle)
            frameCourante = 0;
        if (isRightFrameIdle)
        {
            frameCourante += animRate/2;
            if (frameCourante > NBR_ANIMS_IMMOBILE-1)
            {
                frameCourante = NBR_ANIMS_IMMOBILE-1;
                //On va vers la gauche
                isRightFrameIdle = false;
            }
        }
        else
        {
            frameCourante -= animRate/2;
            if (frameCourante < 0)
            {
                frameCourante = 0;
                //On va vers la droite
                isRightFrameIdle = true;
            }
        }

        isIdle = true;
		break;
	}
    if (isIdle)
    {
        UpdateAnim(cadran, frameCourante, intRectsImmobile);
    }
    //Sinon est en mouvement
    else
    {
        UpdateAnim(cadran, frameCourante, intRectsMouvement);
    }
}

void Personnage::joystickMovement()
{
	interfaceDeplacement.x = eliminateVibration(Joystick::getAxisPosition(0, Joystick::Axis::X)) / GAMEPAD_RATIO;
	interfaceDeplacement.y = eliminateVibration(Joystick::getAxisPosition(0, Joystick::Axis::Y)) / GAMEPAD_RATIO;
}

//Pour changer l'animation courante
void isometrique::Personnage::UpdateAnim(const int& cadranCourant, const float& frameCouranteP, IntRect** myRect)
{
    setTextureRect(myRect[cadranCourant][(int)frameCouranteP]);
}

//Pour garder le gamepad propre
float Personnage::eliminateVibration(float analogInput)
{
	if (abs(analogInput) < 20.0f)
	{
		return 0.0f;
	}
	return analogInput;
}


void Personnage::deplacement()//const float axeX, const float axeY)
{
	//Déplacement du personnage
	move(interfaceDeplacement.x * VITESSE, interfaceDeplacement.y * VITESSE);

	//Test pour la traverse des autres côtés de l'écran
	setPosition(autreCote(getPosition().x, renderWindow->getSize().x, (texture.getSize().x / NBR_ANIMS) / 2), autreCote(getPosition().y, renderWindow->getSize().y, (texture.getSize().y / NBR_MIVEAUX) / 2));
}

/// <summary>
/// Modifie un des axe du personnage s'il dépasse la limite de l'écran de plus
/// de la moitié de sa taille (donc au moment où il disparait de l'écran.
/// </summary>
/// <param name="position">La position de l'axe.</param>
/// <param name="tailleEcran">La taille de l'écran pour cet axe.</param>
/// <param name="demiTaillePersonnage">La taille de la moitié du personnage, du centre à son extrémité.</param>
/// <returns>Nouvelle position du personnagedans l'axe</returns>
float Personnage::autreCote(float positionDansAxe, const int tailleEcran, const int demiTaillePersonnage)
{
	if (positionDansAxe > tailleEcran + demiTaillePersonnage)
	{
		positionDansAxe -= tailleEcran + demiTaillePersonnage * 2;
	}
	else if (positionDansAxe < -demiTaillePersonnage)
	{
		positionDansAxe += tailleEcran + demiTaillePersonnage * 2;
	}
	return positionDansAxe;
}

