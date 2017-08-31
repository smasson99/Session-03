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
  mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Bouncing ball");  
  view = mainWin.getDefaultView();

  //Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes. � faire absolument  
  mainWin.setFramerateLimit(60); 
    
  // Initialisation des objets du jeu
  bool retval = true;
  retval = ball.Init();
  retval = retval && background.Init(mainWin) && retval;

  // Pour placer le cercle au centre de l'�cran au d�but
  ball.SetPosition(LARGEUR/2, HAUTEUR/2);
	return retval;
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
    //Si on a un �v�ment de changement de taille
    else if (event.type == Event::Resized)
    {
      //Fixer la taille de la vue (par d�faut, elle reste proportionnelle
      mainWin.setView(view = View(FloatRect(0.f, 0.f, (float)mainWin.getSize().x, (float)mainWin.getSize().y)));
      
      // Petit hint: si vous avez respect� mon diagramme de classes, vous devriez devoir faire l'appel suivant 
       background.SetScale(mainWin.getSize().x, mainWin.getSize().y);
    }
    else if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
      mainWin.close();
    }

    // �v�nements g�r�s dans l'InputManager
    inputManager.Update(mainWin);
	}
}

/// <summary>
/// Met � jour la logique du jeu
/// </summary>
void Game::update()
{
  // Mise � jour de la logique de jeu
  ball.Update(mainWin);
}

/// <summary>
/// Affiche tous les �l�ments du jeu.  Il faut vraiment afficher tout 
/// car � chaque frame, tout est effac� (voir mainWin.Clear() plus bas).
/// </summary>
void Game::draw()
{
	//Toujours important d'effacer l'�cran pr�c�dent
	mainWin.clear();

  // Affichage ici des �l�ments en ordre de profondeur.
  background.Draw(mainWin);
  ball.Draw(mainWin);
  
  mainWin.display();
}