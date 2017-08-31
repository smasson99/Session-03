#include "Game.h"

// La d�finition des propri�t�s statiques devrait
// toujours se faire dans un .cpp.  Elle se fait
// toujours de la m�me mani�re:
// Type Port�e::NomPropri�t� = Initialisation;
const int Game::LARGEUR = 1280;
const int Game::HAUTEUR = 768;

Game::Game()
{
  // Vous pourriez mettre les initialisations concr�tes ici.  Le danger de le mettre dans un 
  // constructeur est que le constructeur ne retourne rien, donc pas de code d'erreur si quelque
  // chose n'a pas fonctionn�.
  // Vous pourriez donc d�placer le code qui suit dans la m�thode init.
	
 // //On place dans le contructeur ce qui permet � la game elle-m�me de fonctionner
 
	// mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Le titre de mon jeu");
  // ou, pour avoir une fen�tre plein �cran
  // mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Le titre de mon jeu", sf::Style::Fullscreen);
  // view = mainWin.getDefaultView();

	////Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes. � faire absolument
	//mainWin.setVerticalSyncEnabled(true);
	////mainWin.setFramerateLimit(60);  //�quivalent... normalement, mais pas toujours. � utiliser si la synchonisation de l'�cran fonctionne mal.
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

  // 2) On ex�cute le jeu (frame par frame) tant que la fen�tre 
  // principale n'est pas ferm�e
	while (mainWin.isOpen())
	{
    // S�quence pour un frame:
    // a) Lecture des entr�es du joueur
		getInputs();
    // b) Mise � jour du jeu (d�placements des personnages, physique, etc)
		update();
    // c) Mise � jour de l'affichage
		draw();
	}

	return EXIT_SUCCESS;
}

/// <summary>
/// Initialise le jeu lui-m�me. On y cr�e la fen�tre principale et les �l�ments requis dans le jeu
/// </summary>
/// <returns>true si l'initialisation est un succ�s, false sinon</returns>
bool Game::init()
{
  //On place dans le contructeur ce qui permet � la game elle-m�me de fonctionner
  mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Le titre de mon jeu");  // , Style::Titlebar); / , Style::FullScreen);
  // ou, pour avoir une fen�tre plein �cran
  // mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Le titre de mon jeu", sf::Style::Fullscreen);
  view = mainWin.getDefaultView();

  //Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes. � faire absolument
  mainWin.setVerticalSyncEnabled(true);
  //mainWin.setFramerateLimit(60);  //�quivalent... normalement, mais pas toujours. � utiliser si la synchonisation de l'�cran fonctionne mal.
  //https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate

  
	return true;
}

/// <summary>
/// Lecture des entr�es. Les entr�es peuvent "venir" de plusieurs endroits: clavier, gamepad, souris, etc
/// </summary>
void Game::getInputs()
{
	//On passe l'�v�nement en r�f�rence et celui-ci est charg� du dernier �v�nement re�u!
  // Les entr�es fonctionnent par �v�nement. Lorsque la souris se d�place, lorsqu'une touche est enfonc�e,
  // lorsqu'un bouton ou un stick du gamepad est enfonc� ou d�plac�, un �v�nement est g�n�r�. �a �vite de tout 
  // lire � chaque frame et, du coup, de ne r�agir que lorsque c'est vraiment important.
	while (mainWin.pollEvent(event))
	{
		// Les �v�nements peuvent �tre divers
    // 1) sur la fen�tre elle-m�me: fermeture, redimensionnement, etc
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}
    // 2) sur la souris
    else if (event.type == Event::MouseMoved)
    {
      // �crire le code n�cessaire.  Faites F12 sur le texte MouseMoved ci-haut pour voir tous les
      // autres �v�nements disponibles, tant pour la souris que pour le joystick
    }
	}
}

/// <summary>
/// Met � jour la logique du jeu
/// </summary>
void Game::update()
{
  // A �crire selon les besoins du jeu
}

/// <summary>
/// Affiche tous les �l�ments du jeu.  Il faut vraiment afficher tout 
/// car � chaque frame, tout est effac� (voir mainWin.Clear() plus bas).
/// </summary>
void Game::draw()
{
	//Toujours important d'effacer l'�cran pr�c�dent
	mainWin.clear();

  // Affichage ici des �l�ments.


	mainWin.display();
}