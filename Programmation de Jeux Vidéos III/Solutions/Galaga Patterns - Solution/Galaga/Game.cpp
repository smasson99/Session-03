#define _USE_MATH_DEFINES

#include "Game.h"
#include "Fabrique.h"
#include "Player.h"

using namespace galaga;

Game::Game()
{
	//On place dans le contructeur ce qui permet à la game elle-même de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Galaga");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes
	//À faire absolument
	mainWin.setFramerateLimit(60);
	//mainWin.setVerticalSyncEnabled(true); //Équivalent... normalement
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

	Player::getInstance()->initialiser(LARGEUR / 2, 0, 8, &mainWin);

	if (!Player::getInstance()->chargerTexture("Sprites\\galaga.png"))
	{
		return false;
	}

	background.setTexture(backgroundT);
	background.setPosition(0, 0);
	Galaga::finaliserSprite();

	spawner.setRadius(25);
	spawner.setOrigin(25, 25);
	spawner.setFillColor(Color::Transparent);
	spawner.setOutlineColor(Color::White);
	spawner.setOutlineThickness(3);
	spawner.setPosition(100, 50);

	FabriqueGalaga::chargerData(VITESSE, &mainWin);

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

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Num1)
			{
				spawnNumber = 1;
			}
			else if (event.key.code == sf::Keyboard::Num2)
			{
				spawnNumber = 2;
			}

			else if (event.key.code == sf::Keyboard::Num3)
			{
				spawnNumber = 3;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bougerJoueur = 1;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bougerJoueur = 2;
		}
		else
		{
			bougerJoueur = 0;
		}
	}
}

void Game::update()
{
	spawner.setPosition(spawner.getPosition().x + spawnerMove, spawner.getPosition().y);

	if (spawner.getPosition().x <= 100 || spawner.getPosition().x >= LARGEUR - 100)
	{
		spawnerMove *= -1;
	}

	if (spawnNumber > 0)
	{		
		FabriqueGalaga::setPosition(spawner.getPosition());
		switch (spawnNumber)
		{
		case 1:
			vecteurGalagas.push_back(FabriqueGalaga::createGalaga(FabriqueGalaga::Galagas::WASP));
			break;
		case 2:
			vecteurGalagas.push_back(FabriqueGalaga::createGalaga(FabriqueGalaga::Galagas::BUTTERFLY));
			break;
		case 3:
			vecteurGalagas.push_back(FabriqueGalaga::createGalaga(FabriqueGalaga::Galagas::CATCHER));
			break;
		}
		
		spawnNumber = 0;
	}

	if (bougerJoueur == 1)
	{
		Player::getInstance()->deplacement(false);
	}
	else if (bougerJoueur == 2)
	{
		Player::getInstance()->deplacement(true);
	}

	for (int i = 0; i < vecteurGalagas.size(); i++)
	{
		vecteurGalagas[i]->deplacement();
	}
}

void Game::draw()
{
	mainWin.clear();
	mainWin.draw(background);

	mainWin.draw(*Player::getInstance());

	mainWin.draw(spawner);

	for (int i = 0; i < vecteurGalagas.size(); i++)
	{
		vecteurGalagas[i]->dessiner(mainWin);
	}
	mainWin.display();
}

void Game::unload()
{
	Player::getInstance()->release();

	for (int i = 0; i < vecteurGalagas.size(); i++)
	{
		//Libération d'un tableau de pointeur avant la fermeture
		delete vecteurGalagas[i];
	}
}