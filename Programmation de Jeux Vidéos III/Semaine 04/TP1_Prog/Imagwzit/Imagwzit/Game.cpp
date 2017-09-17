#include "Game.h"

Game::Game()
{
	//On place dans le contructeur ce qui permet à la game elle-même de fonctionner

	mainWin.create(VideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32), "I made a game with zombies in it!");  // , Style::Titlebar); / , Style::FullScreen);
	view = View(sf::FloatRect(0, 0, LARGEUR_ECRAN, HAUTEUR_ECRAN));
	view.setCenter(LARGEUR_MONDE / 2, HAUTEUR_MONDE / 2);

	//Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes. À faire absolument
	//mainWin.setVerticalSyncEnabled(true);
	mainWin.setFramerateLimit(60);  //Équivalent... normalement, mais pas toujours. À utiliser si la synchonisation de l'écran fonctionne mal.
	//https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate
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
	//ATTENTION.  Créer un répertoire dans les fichiers de ressource n'en crée pas un pour autant sur le DD
	//Créez tout de même des répertoires dans les ressources (pour garder votre projet trié et propre) mais vous devrez
	//aussi créer des répertoires sur le disque et y placer vos différents assets.

	//POUR L'INSTANT, on garde ça simple.  Si un asset n'est pas chargé, on fait échouer le jeu


	if (!terrainT.loadFromFile("Sprites\\Terrain.jpg"))
	{
		return false;
	}

	if (player.Init("Sprites\\FreeArt\\Joueur.png") == false)
	{
		return false;
	}

	if (!zombieT[0].loadFromFile("Sprites\\FreeArt\\Zombie1.png"))
	{
		return false;
	}

	if (!zombieT[1].loadFromFile("Sprites\\FreeArt\\Zombie2.png"))
	{
		return false;
	}

	if (!zombieT[2].loadFromFile("Sprites\\FreeArt\\Zombie3.png"))
	{
		return false;
	}

	if (!police.loadFromFile("Polices\\segoepr.ttf"))
	{
		return false;
	}

	if (!musique.openFromFile("Sons\\i_maed_a_gam3_w1th_z0mb1es_full_song.ogg"))
	{
		return false;
	}


	terrain.setTexture(terrainT);
	terrain.setPosition(0, 0);

    player.SetPosition(CENTRE_MONDE_X, CENTRE_MONDE_Y);

	for (int i = 0; i < 3; i++)
	{
		zombie[i].setTexture(zombieT[i]);
		zombie[i].setOrigin(zombieT[i].getSize().x / 2, zombieT[i].getSize().y / 2);
		zombie[i].setPosition(CENTRE_MONDE_X - 200 + i * 200, CENTRE_MONDE_Y + 200);
	}

	texte.setString("Ahhhhh! Zombies!!!");
	texte.setFont(police);
	texte.setCharacterSize(50);
	texte.setFillColor(Color::Red);

	//musique.play();
	return true;

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
	}
    //Pour le contrôle avec les flèches du clavier
	(Keyboard::isKeyPressed(Keyboard::Up)) ? haut = true : haut = false;
    (Keyboard::isKeyPressed(Keyboard::Down)) ? bas = true : bas = false;
	(Keyboard::isKeyPressed(Keyboard::Left)) ? gauche = true : gauche = false;
	(Keyboard::isKeyPressed(Keyboard::Right)) ? droite = true : droite = false;
    //Pour le contrôle avec WASD
    (Keyboard::isKeyPressed(Keyboard::W)) ? haut = true : haut = false;
    (Keyboard::isKeyPressed(Keyboard::S)) ? bas = true : bas = false;
    (Keyboard::isKeyPressed(Keyboard::A)) ? gauche = true : gauche = false;
    (Keyboard::isKeyPressed(Keyboard::D)) ? droite = true : droite = false;
    //Pour les clicks
    (Mouse::isButtonPressed(Mouse::Left)) ? click = true : click = false;
}

//Vous devrez centrer la vue sur le joueur: https://www.sfml-dev.org/tutorials/2.4/graphics-view-fr.php
void Game::update()
{
	float moveX = 0.0f;
	float moveY = 0.0f;

	if (gauche) moveX -= 5.0f;
	if (droite) moveX += 5.0f;
	if (haut) moveY -= 5.0f;
	if (bas) moveY += 5.0f;

    //Si click, ajouter un projectile
    if (click)
    {
        projectiles.push_back(player.CreateProjectile());
    }
    //Pour chaque projectile
    for (int i = 0; i < projectiles.size(); ++i)
    {
        if (projectiles.size() > 0)
            bool debug;
        //Updater chacun des projectiles
        projectiles.at(i).Update();
        //Dans le cas d'une sortie de zone
        if (/*projectiles.at(i).GetX() < 0 ||
            projectiles.at(i).GetY() < 0 ||*/
            mainWin.getSize().x - projectiles.at(i).GetX() > LARGEUR_ECRAN ||
            mainWin.getSize().y - projectiles.at(i).GetY() > HAUTEUR_ECRAN)
        {
            //Détruire le projectile
            projectiles.erase(projectiles.begin() + i);
        }
    }

	view.move(moveX, moveY);

	ajusterDepassementLimitesVue();
    player.SetPosition(view.getCenter().x, view.getCenter().y);
    //Position de la souris
    sf::Vector2f mousePos = mainWin.mapPixelToCoords(mouse.getPosition(mainWin));
    //Updater le joueur
    player.Update(mousePos.x, mousePos.y);
    //Seter les positions de l'interface
	texte.setPosition(view.getCenter().x - 220, view.getCenter().y - 310);
}

void Game::draw()
{
	//Toujours important d'effacer l'écran précédent
	mainWin.clear();
	mainWin.setView(view);

	mainWin.draw(terrain);
    mainWin.draw(player.GetSprite());
	mainWin.draw(zombie[0]);
	mainWin.draw(zombie[1]);
	mainWin.draw(zombie[2]);
	mainWin.draw(texte);

    //Pour chaque projectile
    for (int i = 0; i < projectiles.size(); ++i)
    {
        //Dessiner chacun des projectiles
        mainWin.draw(projectiles.at(i).GetSprite());
    }

	mainWin.display();
}

void Game::ajusterDepassementLimitesVue()
{
	if (view.getCenter().x < LIMITE_VUE_MIN_X)
	{
		view.setCenter(LIMITE_VUE_MIN_X, view.getCenter().y);
	}
	else if (view.getCenter().x > LIMITE_VUE_MAX_X)
	{
		view.setCenter(LIMITE_VUE_MAX_X, view.getCenter().y);
	}

	if (view.getCenter().y < LIMITE_VUE_MIN_Y)
	{
		view.setCenter(view.getCenter().x, LIMITE_VUE_MIN_Y);
	}
	else if (view.getCenter().y > LIMITE_VUE_MAX_Y)
	{
		view.setCenter(view.getCenter().x, LIMITE_VUE_MAX_Y);
	}
}