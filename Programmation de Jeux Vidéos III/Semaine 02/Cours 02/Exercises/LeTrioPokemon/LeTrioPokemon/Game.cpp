#include "Game.h"

Game::Game()
{
	//On place dans le contructeur ce qui permet � la game elle-m�me de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Pokemon_V01");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes. � faire absolument
	mainWin.setVerticalSyncEnabled(true);
	mainWin.setFramerateLimit(60);  //�quivalent... normalement, mais pas toujours. � utiliser si la synchonisation de l'�cran fonctionne mal.
	//https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate

    //Instantiation des variables
    nbPoints = 0;
    
    //Setter les positions de d�part
    pokemon.SetPosition(LARGEUR / 2, HAUTEUR / 2);
    pokeball.SetPosition(LARGEUR / 4 - 50, HAUTEUR / 3 -50);
    //Lancer les timers:
    pokemon.StartTeleport();
}

int Game::testTest()
{
	return 0;
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



	return EXIT_SUCCESS;
}

bool Game::init()
{
    bool initValue = pokemon.Init();
    initValue = pokeball.Init() && initValue;
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

        //Update des �v�nemnets g�r�s dans le input manager:
        inputManager.Update(mainWin);
	}
}

void Game::update()
{
    //Update de la logique du jeu:
    pokemon.Update(mainWin);
    if (pokeball.Update(inputManager, pokemon))
        nbPoints++;
}

void Game::draw()
{
	//Toujours important d'effacer l'�cran pr�c�dent
	mainWin.clear();

    //Dessiner le nouveau contenu au nouvel �cran
    pokemon.Draw(mainWin);
    pokeball.Draw(mainWin);

	mainWin.display();
}