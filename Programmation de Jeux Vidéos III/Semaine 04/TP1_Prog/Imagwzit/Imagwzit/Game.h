#pragma once

#include <random>
#include "Player.h"
#include "Zombie.h"
#include "GameObject.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Game
{
public:
    Game();
    int run();
    int testTest();

private:
    const int LARGEUR_ECRAN = 1280;
    const int HAUTEUR_ECRAN = 720;

    const int LARGEUR_MONDE = 3384;
    const int HAUTEUR_MONDE = 1656;

    const int CENTRE_MONDE_X = LARGEUR_MONDE / 2;
    const int CENTRE_MONDE_Y = HAUTEUR_MONDE / 2;

    //Puisque la vue utilise des positions centrales, les limites d'affichage
    //sont les positions centrales des cadres limites.
    const int LIMITE_VUE_MIN_X = LARGEUR_ECRAN / 2;
    const int LIMITE_VUE_MIN_Y = HAUTEUR_ECRAN / 2;
    const int LIMITE_VUE_MAX_X = LARGEUR_MONDE - LIMITE_VUE_MIN_X;
    const int LIMITE_VUE_MAX_Y = HAUTEUR_MONDE - LIMITE_VUE_MIN_Y;


    /* Les textures devraient devenir des propri�t�s statiques de leur classes respectives*/
    /* Pour le moment vous pouvez m�me les mettre publique si vous le souhaitez*/
    Texture terrainT;


    /* � partir d'ici, certains attributs sont des placeholders temporaires, et ce que vous voulez garder devrait*/
    /* se retrouver de plus en plus � l'int�rieur de classes. Ne faites pas tout d'un coup, allez-y lentement et */
    /* assurez-vous que tout fonctionne, une �tape � la fois*/
    Sprite terrain;
    Sprite joueur;
    Player player;
    
    /*Voici le g�n�rateur de nombres al�atoires et ses intervalles*/
    std::default_random_engine generator;
    /*Voici le vecteur de zombies du jeu*/
    std::vector<Zombie> zombies;
    /*Voici le timer pour le spawn des zombies*/
    sf::Clock clockZR;
    /*Voici le d�lais pour le spawn des zombies*/
    sf::Time zSpawnDelay = sf::seconds(1.0f);
    /*Voici les vecteurs de projectiles du jeu*/
    std::vector<Projectile> projectiles;
    std::vector<Projectile> flameProjectiles;
    std::vector<Projectile> missileProjectiles;
    std::vector<Projectile> scatterProjectiles;
    /*Voici les vecteurs de collectables*/
    std::vector<GameObject> flamePacks;
    std::vector<GameObject> missilePacks;
    std::vector<GameObject> scatterPacks;
    /*Le nombre de projectiles du joueur*/
    int nbProjsPlayer = 1200;
    int nbProjsFlame = 100;
    int nbProjsMissile = 100;
    int nbProjsScatter = 100;
    /*Chances de dropper un pack de projectiles*/
    int chancesPackDrop = 5;
    /*Index du projectile courant*/
    int curProj = 0;

    Font police;
    Text texte;
    Music musique;

    //Bool�en des inputs
    bool gauche = false;
    bool droite = false;
    bool haut = false;
    bool bas = false;

    bool click = false;
    
    bool changeMunition = false;

    /*Fin du transfert suppos� vers les classes*/

    bool init();
    void getInputs();
    void update();
    void draw();

    void ajusterDepassementLimitesVue();

    Mouse mouse;
    RenderWindow mainWin;
    View view;
    Event event;
};