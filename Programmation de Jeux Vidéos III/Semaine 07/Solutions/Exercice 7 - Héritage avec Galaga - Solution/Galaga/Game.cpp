#define _USE_MATH_DEFINES

#include "Game.h"
#include "Butterfly.h"
#include "Wasp.h"
#include "Catcher.h"  //Ici, parce que le .h n'est a pas besoin (il a juste des pointeurs de Galagas)
using namespace galaga;

Game::Game()
{
	//On place dans le contructeur ce qui permet � la game elle-m�me de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Galaga");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes
	//� faire absolument
	mainWin.setFramerateLimit(60);
	//mainWin.setVerticalSyncEnabled(true); //�quivalent... normalement
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

	unload();

	return EXIT_SUCCESS;
}

bool Game::init()
{
	//Aussi bien commencer par le chargement des textures
	if (!backgroundT.loadFromFile("Sprites\\Stars.jpg"))
	{
		return false;
	}

	//Ici chargement dans notre attribut statique
	if (!Galaga::chargerTexture("Sprites\\enemies.png"))
	{
		return false;
	}

	background.setTexture(backgroundT);
	background.setPosition(0, 0);

	//Positions: quart de l'�cran, milleu et trois quart de l'�cran (en x)
	Galagas[0] = new Butterfly(LARGEUR / 2, 100.0f, VITESSE, BUTTERFLY, NOMBRE_ANIMATIONS, NOMBRE_FRAMES, &mainWin);
	Galagas[1] = new Wasp(LARGEUR / 4, 100.0f, VITESSE, WASP, NOMBRE_ANIMATIONS, NOMBRE_FRAMES, &mainWin);
	Galagas[2] = new Catcher(LARGEUR * 3 / 4, 100.0f, VITESSE, CATCHER, NOMBRE_ANIMATIONS, NOMBRE_FRAMES, &mainWin);

	for (int i = 0; i < 3; i++)
	{
		Galagas[i]->ajustementsVisuels();
	}

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

	//Juste pour tester l'origine des sprites
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		Galagas[0]->rotate(-2.0f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		Galagas[0]->rotate(2.0f);
	}
}

void Game::update()
{
	for (int i = 0; i < 3; i++)
	{
		Galagas[i]->deplacement();
	}
}

void Game::draw()
{
	mainWin.clear();
	mainWin.draw(background);
	for (int i = 0; i < 3; i++)
	{
		mainWin.draw(*Galagas[i]);
	}
	mainWin.display();
}

void Game::unload()
{
	for (int i = 0; i < 3; i++)
	{
		//Lib�ration d'un tableau de pointeur avant la fermeture
		delete Galagas[i];
	}
}