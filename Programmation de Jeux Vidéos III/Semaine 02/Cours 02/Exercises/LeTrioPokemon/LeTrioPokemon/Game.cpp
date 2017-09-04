#include "Game.h"

Game::Game()
{
	//On place dans le contructeur ce qui permet à la game elle-même de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Pokemon_V01");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes. À faire absolument
	mainWin.setVerticalSyncEnabled(true);
	mainWin.setFramerateLimit(60);  //Équivalent... normalement, mais pas toujours. À utiliser si la synchonisation de l'écran fonctionne mal.
	//https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate

    //Instantiation des variables
    nbPoints = 0;
    
    //Setter les positions de départ
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
	//On passe l'événement en référence et celui-ci est chargé du dernier événement reçu!
	while (mainWin.pollEvent(event))
	{
		//x sur la fenêtre
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}

        //Update des événemnets gérés dans le input manager:
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
	//Toujours important d'effacer l'écran précédent
	mainWin.clear();

    //Dessiner le nouveau contenu au nouvel écran
    pokemon.Draw(mainWin);
    pokeball.Draw(mainWin);

	mainWin.display();
}