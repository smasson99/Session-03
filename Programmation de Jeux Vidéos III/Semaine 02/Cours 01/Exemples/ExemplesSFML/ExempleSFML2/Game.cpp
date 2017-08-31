#include "Game.h"

// La définition des propriétés statiques devrait
// toujours se faire dans un .cpp.  Elle se fait
// toujours de la même manière:
// Type Portée::NomPropriété = Initialisation;
const int Game::LARGEUR = 1280;
const int Game::HAUTEUR = 768;

Game::Game()
{
  // Vous pourriez mettre les initialisations concrètes ici.  Le danger de le mettre dans un 
  // constructeur est que le constructeur ne retourne rien, donc pas de code d'erreur si quelque
  // chose n'a pas fonctionné.
  // Vous pourriez donc déplacer le code qui suit dans la méthode init.
	
 // //On place dans le contructeur ce qui permet à la game elle-même de fonctionner
 
	// mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Le titre de mon jeu");
  // ou, pour avoir une fenêtre plein écran
  // mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Le titre de mon jeu", sf::Style::Fullscreen);
  // view = mainWin.getDefaultView();

	////Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes. À faire absolument
	//mainWin.setVerticalSyncEnabled(true);
	////mainWin.setFramerateLimit(60);  //Équivalent... normalement, mais pas toujours. À utiliser si la synchonisation de l'écran fonctionne mal.
	////https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate
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
  mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Le titre de mon jeu");  
  mainWin.setTitle(std::to_string(mainWin.getSize().x) + " * " + std::to_string(mainWin.getSize().y));
  view = mainWin.getDefaultView();

  //Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes. À faire absolument
  mainWin.setVerticalSyncEnabled(true);
  //mainWin.setFramerateLimit(60);  //Équivalent... normalement, mais pas toujours. À utiliser si la synchonisation de l'écran fonctionne mal.
  //https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate

  // Arrière-plan rouge
  circle.SetBackgroundColor(sf::Color(255,0,0));
  // Bordure blanche
  circle.SetOutlineColor(sf::Color(255,255,255));
  // Rayon de 100
  circle.SetRadius(100);

  // Pour placer le cercle au centre de l'écran
  circle.SetPosition(LARGEUR/2, HAUTEUR/2);
	return true;
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
      mainWin.setView(view = View(FloatRect(0.f, 0.f, mainWin.getSize().x, mainWin.getSize().y)));

      //Afficher la taille de la fenêtre dans la barre de titre
      mainWin.setTitle(std::to_string(mainWin.getSize().x) + " * " + std::to_string(mainWin.getSize().y));
    }
	}
}

/// <summary>
/// Met à jour la logique du jeu
/// </summary>
void Game::update()
{
  // Exemple d'utilisation d'une variable statique à l'intérieur d'une méthode
  static float radius = 50;
  radius += 0.25f;
  if(radius > 100.0f)
    radius = 50.0f;

  // A écrire selon les besoins du jeu
  circle.SetRadius(radius);
  // Pour faire déplacer le cercle d'en haut à gauche vers en bas à droite
  //circle.SetPosition(circle.GetPosition() + sf::Vector2f(1,1));
  
}

/// <summary>
/// Affiche tous les éléments du jeu.  Il faut vraiment afficher tout 
/// car à chaque frame, tout est effacé (voir mainWin.Clear() plus bas).
/// </summary>
void Game::draw()
{
	//Toujours important d'effacer l'écran précédent
	mainWin.clear();

  // Affichage ici des éléments.
  circle.Draw(mainWin);

	mainWin.display();
}