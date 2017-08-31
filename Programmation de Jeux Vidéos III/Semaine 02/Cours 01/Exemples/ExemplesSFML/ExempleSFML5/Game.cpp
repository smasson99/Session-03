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
}


int Game::run()
{
  // Boucle de jeu assez standard
  // 1) Initialisation
	if (!init())
	{
		return EXIT_FAILURE;
	}

  music.play();
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
  mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "ExempleSFML5");  
  view = mainWin.getDefaultView();

  //Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes. � faire absolument
  mainWin.setFramerateLimit(60);


  // Initialisation de tout!
  bool retval = background.loadFromFile("Assets/Sprites/terrain.png");
  if (retval)
  {
    backgroundSprite.setTexture(background);
  }
  
  if (ball.loadFromFile("Assets/Sprites/soccerBall.png"))
  {
    ballSprite.setTexture(ball);
  }
  else
    retval = false;
  
  retval = music.openFromFile("Assets/Music/Carl_Sagan_-_Pale_Blue_Dot.ogg") && retval;  
  

   
  if (font.loadFromFile("Assets/Fonts/segoepr.ttf"))
  {
    text.setFont(font);
  }
  else
    retval = false;
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
  // A �crire selon les besoins du jeu
  // Mise � jour de la logique de jeu
  //------------Clavier---------------------------------------------------------------------
  if (inputManager.GetLeft())
  {
    ballSprite.setPosition(ballSprite.getPosition().x - SPEEDKEYBOARD, ballSprite.getPosition().y);
  }
  else if (inputManager.GetRight())
  {
    ballSprite.setPosition(ballSprite.getPosition().x + SPEEDKEYBOARD, ballSprite.getPosition().y);
  }

  if (inputManager.GetUp())
  {
    ballSprite.setPosition(ballSprite.getPosition().x , ballSprite.getPosition().y - SPEEDKEYBOARD);
  }
  else if (inputManager.GetDown())
  {
    ballSprite.setPosition(ballSprite.getPosition().x, ballSprite.getPosition().y + SPEEDKEYBOARD);
  }

   static int cpt = 0;
   cpt++;
   std::string currentText = "Nombre d'appels: " + std::to_string(cpt);
   text.setString(currentText);
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
  mainWin.draw(backgroundSprite);
  mainWin.draw(text);
  mainWin.draw(ballSprite);
  

	mainWin.display();
}