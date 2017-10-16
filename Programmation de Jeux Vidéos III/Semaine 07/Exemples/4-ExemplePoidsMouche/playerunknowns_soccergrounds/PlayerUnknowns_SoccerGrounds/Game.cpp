#include "Game.h"

using namespace sf;
using namespace pusg;

Game::Game()
{
	//On place dans le contructeur ce qui permet à la game elle-même de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "PlayerUnknowns SoccerGrounds");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes. À faire absolument
	//mainWin.setVerticalSyncEnabled(true);
	mainWin.setFramerateLimit(60);  //Équivalent... normalement, mais pas toujours. À utiliser si la synchonisation de l'écran fonctionne mal.
	//https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate
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
	if (!terrainT.loadFromFile("Sprites\\terrain.png"))
	{
		return false;
	}

	if (!soccerBallT.loadFromFile("Sprites\\soccerBall.png"))
	{
		return false;
	}

	if (!font.loadFromFile("Fonts\\segoepr.ttf"))
	{
		return false;
	}

	srand(time(NULL));

	soccerBall.setTexture(soccerBallT);
	soccerBall.setOrigin(soccerBallT.getSize().x / 2, soccerBallT.getSize().y / 2);
	
	terrain.setTexture(terrainT);
	terrain.setPosition(0, 0);

	text.setFont(font);
	text.setCharacterSize(10);
	text.setFillColor(Color::Red);
	text.setStyle(Text::Bold);

	//La position des balles est hardcodé mais disons que le placement de 100
	//balles s'est fait un peu par essai et erreur
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			int posX = 100 + i * 124;
			int posY = 50 + j * 62;

			Balle* b = new Balle();
			b->init(soccerBallT, i * 10 + j + 1);
			b->setPosition(posX, posY);
			balles.push_back(b);
		}

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

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left && !clicked)
			{
				clicked = true;
			}
		}
	}
}

void Game::update()
{
	gererClick();
	gererMouvementBalles();
	gererCollisionsBalles();
	gererEffacementBalles();
}

void Game::draw()
{
	//Toujours important d'effacer l'écran précédent
	mainWin.clear();

	mainWin.draw(terrain);

	for (int i = 0; i < balles.size(); i++)
	{
		balles[i]->dessiner(mainWin, soccerBall, text);
	}

	if (droitDeFaireFeu)
	{
		ecrireGrosTexte("Vous pouvez faire feu!", 450, 60);
	}

	if (balles.size() == 1)
	{
		ecrireGrosTexte("La balle gagnante est la balle no. " + std::to_string(balles[0]->getNoBalle()), 380, 10);
	}
	else if (balles.size() == 0)
	{
		ecrireGrosTexte("Partie nulle; pas de gagnant", 400, 10);
	}

	mainWin.display();
}

void Game::unload()
{
	for (int i = 0; i < balles.size(); i++)
	{
		delete balles[i];
	}
}


//---------------------------------------------------------------------------------------


void Game::gererClick()
{
	if (clicked)
	{
		clicked = false;

		if (droitDeFaireFeu)
		{
			droitDeFaireFeu = false;

			//Ici on fait "feu"
			for (int i = 0; i < balles.size(); i++)
			{
				balles[i]->injectionDeForce();
			}
		}
	}

	//Ici on utilise le casting inplicite de bool en int
	//Si plus aucune balle est en mouvement, alors on a le droit de les relancer.
	if (!droitDeFaireFeu)
	{
		int compteur = 0;

		for (int i = 0; i < balles.size(); i++)
		{
			//retourne 0 si false et 1 si true
			compteur += balles[i]->enMouvement();
		}

		//Si toutes les balles sont immobiles
		if (compteur == 0)
		{
			//Alors on a le droit de "tirer" à nouveau
			droitDeFaireFeu = true;
		}
	}
}

/// <summary>
/// Mouvement de la balle et collision
/// avec les limites de la table
/// </summary>
void Game::gererMouvementBalles()
{
	const static float HALFBALL = soccerBallT.getSize().x / 2;

	for (int i = 0; i < balles.size(); i++)
	{
		//MOUVEMENT DE LA BALLE ICI, DANS UN BUFFER TEMPORAIRE
		Vector2f testPosition = balles[i]->getPosition() + balles[i]->getMouvement();

		//AJUSTEMENT DU BUFFER SELON LA LIMITE DES MURS
		if (testPosition.x < HALFBALL)
		{
			testPosition.x = HALFBALL;
			balles[i]->hit();
			balles[i]->setMouvement(balles[i]->getMouvement().x *= -1, balles[i]->getMouvement().y);
		}
		else if (testPosition.x > LARGEUR - HALFBALL)
		{
			testPosition.x = LARGEUR - HALFBALL;
			balles[i]->hit();
			balles[i]->setMouvement(balles[i]->getMouvement().x *= -1, balles[i]->getMouvement().y);
		}

		if (testPosition.y < HALFBALL)
		{
			testPosition.y = HALFBALL;
			balles[i]->hit();
			balles[i]->setMouvement(balles[i]->getMouvement().x, balles[i]->getMouvement().y *= -1);
		}
		else if (testPosition.y > HAUTEUR - HALFBALL)
		{
			testPosition.y = HAUTEUR - HALFBALL;
			balles[i]->hit();
			balles[i]->setMouvement(balles[i]->getMouvement().x, balles[i]->getMouvement().y *= -1);
		}

		//MOUVEMENT DE LA BALLE, EFFECTIVEMENT APPLIQUÉE À CELLE-CI
		balles[i]->setPosition(testPosition);
	}
}

/// <summary>
/// Gestion des collisions (et redirection des balles), puis ajustement du
/// chevauchement s'il y a collision, et finalement application de la friction
/// </summary>
void Game::gererCollisionsBalles()
{
	for (int i = 0; i < balles.size(); i++)
	{
		for (int j = i + 1; j < balles.size(); j++)
		{
			if (balles[i]->testerCollision(*balles[j]))
			{
				balles[i]->ajusterChevauchement(*balles[j]);
			}
		}
		balles[i]->appliquerFriction();
	}
}

/// <summary>
///Effacement des balles mortes.
///Pas certain que vous avez travaillé encore les itérateurs.
///En attendant, puisque erase enlève une entrée et rabat les
///autres, on fait la patente à rebours	
/// </summary>
void Game::gererEffacementBalles()
{
	if (balles.size() > 1)
	{
		for (int i = balles.size() - 1; i > -1; i--)
		{
			if (balles[i]->estMort())
			{
				delete balles[i];
				balles.erase(balles.begin() + i);
			}
		}
	}
}


void Game::ecrireGrosTexte(String texte, int posX, int posY)
{
	text.setCharacterSize(30);
	text.setPosition(posX, posY);
	text.setString(texte);
	mainWin.draw(text);
	text.setCharacterSize(10);
}