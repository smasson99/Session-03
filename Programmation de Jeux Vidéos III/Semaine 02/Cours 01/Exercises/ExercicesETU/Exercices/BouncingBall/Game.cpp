#include "Game.h"

const int Game::LARGEUR = 1280;
const int Game::HAUTEUR = 768;

Game::Game()
{  
}


int Game::run()
{
  // Boucle de jeu assez standard
  // 1) Initialisation
	if (!init())
	{
		return EXIT_FAILURE;
	}

  // 2) On exécute le jeu (frame par frame) tant que la fenêtre 
  // principale n'est pas fermée
	while (mainWin.isOpen())
	{
    // Séquence pour un frame:
    // a) Lecture des entrées du joueur
		getInputs();
    // b) Mise à jour du jeu (déplacements des personnages, physique, etc)
		update();
    // c) Mise à jour de l'affichage
		draw();
	}

	return EXIT_SUCCESS;
}

/// <summary>
/// Initialise le jeu lui-même. On y crée la fenêtre principale et les éléments requis dans le jeu
/// </summary>
/// <returns>true si l'initialisation est un succès, false sinon</returns>
bool Game::init()
{
  //On place dans le contructeur ce qui permet à la game elle-même de fonctionner
  mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Bouncing ball");  
  view = mainWin.getDefaultView();

  //Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes. À faire absolument  
  mainWin.setFramerateLimit(60); 
    
  // Initialisation des objets du jeu
  bool retval = true;
  retval = ball.Init();
  retval = retval && background.Init(mainWin) && retval;

  // Pour placer le cercle au centre de l'écran au début
  ball.SetPosition(LARGEUR/2, HAUTEUR/2);
	return retval;
}

/// <summary>
/// Lecture des entrées. Les entrées peuvent "venir" de plusieurs endroits: clavier, gamepad, souris, etc
/// </summary>
void Game::getInputs()
{
	//On passe l'événement en référence et celui-ci est chargé du dernier événement reçu!
  // Les entrées fonctionnent par événement. Lorsque la souris se déplace, lorsqu'une touche est enfoncée,
  // lorsqu'un bouton ou un stick du gamepad est enfoncé ou déplacé, un événement est généré. Ça évite de tout 
  // lire à chaque frame et, du coup, de ne réagir que lorsque c'est vraiment important.
	while (mainWin.pollEvent(event))
	{
		// Les événements peuvent être divers
    // 1) sur la fenêtre elle-même: fermeture, redimensionnement, etc
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}
    //Si on a un évément de changement de taille
    else if (event.type == Event::Resized)
    {
      //Fixer la taille de la vue (par défaut, elle reste proportionnelle
      mainWin.setView(view = View(FloatRect(0.f, 0.f, (float)mainWin.getSize().x, (float)mainWin.getSize().y)));
      
      // Petit hint: si vous avez respecté mon diagramme de classes, vous devriez devoir faire l'appel suivant 
       background.SetScale(mainWin.getSize().x, mainWin.getSize().y);
    }
    else if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
      mainWin.close();
    }

    // Événements gérés dans l'InputManager
    inputManager.Update(mainWin);
	}
}

/// <summary>
/// Met à jour la logique du jeu
/// </summary>
void Game::update()
{
  // Mise à jour de la logique de jeu
  ball.Update(mainWin);
}

/// <summary>
/// Affiche tous les éléments du jeu.  Il faut vraiment afficher tout 
/// car à chaque frame, tout est effacé (voir mainWin.Clear() plus bas).
/// </summary>
void Game::draw()
{
	//Toujours important d'effacer l'écran précédent
	mainWin.clear();

  // Affichage ici des éléments en ordre de profondeur.
  background.Draw(mainWin);
  ball.Draw(mainWin);
  
  mainWin.display();
}