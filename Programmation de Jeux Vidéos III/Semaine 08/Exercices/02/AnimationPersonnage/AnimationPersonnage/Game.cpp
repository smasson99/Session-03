#include "Game.h"

using namespace isometrique;

Game::Game()
{
	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Animation du personnage");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();
	mainWin.setFramerateLimit(60);
	//mainWin.setVerticalSyncEnabled(true);  //Si le pr�c�dent vous pose probl�me	
}


int Game::run()
{
	if (!init())
	{
		return EXIT_FAILURE;
	}


	while (mainWin.isOpen())
	{
		getInputs();
		update();
		draw();
	}

	delete personnage;

	return EXIT_SUCCESS;
}

bool Game::init()
{
	//Fond d'�cran
	if (!backgroundT.loadFromFile("Sprites\\floor.png"))
	{
		return false;
	}

	//Ici chargement dans notre attribut statique
	if (!Personnage::chargerTextures("Sprites\\perso.png"))
	{
		return false;
	}

	background.setTexture(backgroundT);

	//On cr�e notre personnage
	personnage = new Personnage(LARGEUR / 2, 100.0f, &mainWin);
	personnage->ajustementsVisuels();

	//----------------------TUILES DE FOND------------------------//
	//----On calcule les positions de nos jolies tuiles de fond---//

	for (int i = 0; i < 6; i++) // celles � partir de 0/0
	{
		backgroundPositions[i].x = (i % 2) * 512;
		backgroundPositions[i].y = (i / 2) * 256;
	}

	for (int i = 0; i < 12; i++)  //Les entre-tuiles
	{
		backgroundPositions[i + 6].x = ((i % 3) * 512) - 256;
		backgroundPositions[i + 6].y = ((i / 3) * 256) - 128;
	}
	//-------------------fin des tuiles de fond------------------//

	return true;
}


void Game::getInputs()
{
	//On passe l'�v�nement en r�f�rence et celui-ci est charg� du dernier �v�nement re�u!
	while (mainWin.pollEvent(event))
	{
		//x sur la fen�tre
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}
	}

	//Le personnage g�re lui-m�me ses contr�les
	personnage->gererInputs();
}

void Game::update()
{
	//d�placement du personnage
	personnage->deplacement();
}

void Game::draw()
{
	mainWin.clear();

	//Dessin des tuiles
	for (int i = 0; i < 18; i++)
	{
		//On ajuste la position du sprite de tuile
		background.setPosition(backgroundPositions[i]);

		//On "�tampe" la tuile
		mainWin.draw(background);
	}

	mainWin.draw(*personnage);
	mainWin.display();
}