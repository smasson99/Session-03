#define _USE_MATH_DEFINES

#include "Game.h"
using namespace galaga;

Game::Game()
{
	//On place dans le contructeur ce qui permet à la game elle-même de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Galaga");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes
	//À faire absolument
	mainWin.setFramerateLimit(60);  
	//mainWin.setVerticalSyncEnabled(true);  //Équivalent... normalement

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

	delete galaga1;

	return EXIT_SUCCESS;
}

bool Game::init()
{
    //On crée notre Galaga papillon
    galaga1 = new Galaga(LARGEUR / 2, 100.0f, VITESSE, BUTTERFLY, NOMBRE_ANIMATIONS, NOMBRE_FRAMES, &mainWin);

	//Fond d'écran
	if (!backgroundT.loadFromFile("Sprites\\Stars.jpg"))
	{
		return false;
	}
    if (!galaga1->Init("Sprites\\enemies.png"))
    {
        return false;
    }

	background.setTexture(backgroundT);
	background.setPosition(0, 0);

	return true;
}

void Game::getInputs()
{
	while (mainWin.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}
	}
}

void Game::update()
{
	//déplacement du galaga
	galaga1->deplacement();
}

void Game::draw()
{
	mainWin.clear();
	mainWin.draw(background);
	mainWin.draw(*galaga1);
	mainWin.display();
}