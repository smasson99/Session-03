#include "Game.h"



// La d�finition des propri�t�s statiques devrait
// toujours se faire dans un .cpp.  Elle se fait
// toujours de la m�me mani�re:
// Type Port�e::NomPropri�t� = Initialisation;
const int Game::LARGEUR = 1280;
const int Game::HAUTEUR = 768;

// Autre mani�re de d�finir une constante. Ne fonctionne qu'� l'int�rieur d'un fichier .cpp
const float SPEEDRATIO = 20.0f;
const float SPEEDKEYBOARD = 4.0f;

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


  xboxColors[0] = sf::Color::Green;
  xboxColors[1] = sf::Color::Red;
  xboxColors[2] = sf::Color::Blue;
  xboxColors[3] = sf::Color::Yellow;
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
  mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Le titre de mon jeu");  
  mainWin.setTitle(std::to_string(mainWin.getSize().x) + " * " + std::to_string(mainWin.getSize().y));
  view = mainWin.getDefaultView();

  //Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes. � faire absolument
  mainWin.setVerticalSyncEnabled(true);
  //mainWin.setFramerateLimit(60);  //�quivalent... normalement, mais pas toujours. � utiliser si la synchonisation de l'�cran fonctionne mal.
  //https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate

  // Arri�re-plan rouge
  circle.SetBackgroundColor(sf::Color(255,0,0));
  // Bordure blanche
  circle.SetOutlineColor(sf::Color(255,255,255));
  // Rayon de 100
  circle.SetRadius(100);

  // Pour placer le cercle au centre de l'�cran
  circle.SetPosition(LARGEUR/2, HAUTEUR/2);
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
    //Si on a un �v�ment de changement de taille
    else if (event.type == Event::Resized)
    {
      //Fixer la taille de la vue (par d�faut, elle reste proportionnelle
      mainWin.setView(view = View(FloatRect(0.f, 0.f, (float)mainWin.getSize().x, (float)mainWin.getSize().y)));

      //Afficher la taille de la fen�tre dans la barre de titre
      mainWin.setTitle(std::to_string(mainWin.getSize().x) + " * " + std::to_string(mainWin.getSize().y));
    }
    //------------Gamepad event---------------------------------------------------------------------
    else if (event.type == Event::JoystickButtonPressed)
    {
      //Attention, il y a deux mani�re d'acc�der aux inputs.  Avec les �v�nements, nous allons v�rifier le dernier �v�nement survenu
      //Qui peut �tre un bouton appuy�, mais d�s qu'un autre �v�nement se produit, ce n'est plus le dernier �v�nement survenu
      //On ne peut s'y fier pour une v�rification continue de l'�tat d'un input
      //http://www.sfml-dev.org/tutorials/2.4/window-events-fr.php
      // On peut lire l'�tat d'un bouton avec
      // event.joystickButton.button
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
  //------------Clavier---------------------------------------------------------------------
  if (inputManager.GetLeft())
  {
    circleOffset.x -= SPEEDKEYBOARD;
  }
  else if (inputManager.GetRight())
  {
    circleOffset.x += SPEEDKEYBOARD;
  }

  if (inputManager.GetUp())
  {
    circleOffset.y -= SPEEDKEYBOARD;
  }
  else if (inputManager.GetDown())
  {
    circleOffset.y += SPEEDKEYBOARD;
  }

  //------------Souris---------------------------------------------------------------------
  //http://www.sfml-dev.org/documentation/2.3-fr/classsf_1_1Mouse.php#details

  if (inputManager.GetMouseClick())
  {
    Vector2i posSouris = Mouse::getPosition(mainWin);

    circleOffset.x = (float)posSouris.x - (LARGEUR / 2);
    circleOffset.y = (float)posSouris.y - (HAUTEUR / 2);
  }




  // Exemple d'utilisation d'une variable statique � l'int�rieur d'une m�thode
  static float radius = 50;
  radius += 0.25f;
  if(radius > 100.0f)
    radius = 50.0f;

  // A �crire selon les besoins du jeu
  circle.SetRadius(radius);
  circle.SetPosition(sf::Vector2f(circleOffset.x + LARGEUR / 2, circleOffset.y + HAUTEUR / 2));
  
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
  circle.Draw(mainWin);

	mainWin.display();
}