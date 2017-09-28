#pragma once

#include <random>
#include "Player.h"
#include "Zombie.h"
#include "GameObject.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//#include <CppUnitTest.h>
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


    /* Les textures devraient devenir des propriétés statiques de leur classes respectives*/
    /* Pour le moment vous pouvez même les mettre publique si vous le souhaitez*/
    Texture terrainT;


    /* À partir d'ici, certains attributs sont des placeholders temporaires, et ce que vous voulez garder devrait*/
    /* se retrouver de plus en plus à l'intérieur de classes. Ne faites pas tout d'un coup, allez-y lentement et */
    /* assurez-vous que tout fonctionne, une étape à la fois*/
    Sprite terrain;
    Player player;
    
    /*Voici le générateur de nombres aléatoires et ses intervalles*/
    std::default_random_engine generator;
    /*Voici le vecteur de zombies du jeu*/
    std::vector<Zombie> zombies;
    /*Voici le timer pour le spawn des zombies*/
    sf::Clock clockZR;
    /*Voici le timer pour le changement de munition*/
    sf::Clock clockCM;
    /*Voici le timer pour les scores*/
    sf::Clock clockScore;
    /*Voici le timer pour le rate de spawn des zombies*/
    sf::Clock clockRateChange;
    /*Voici le délais pour le spawn des zombies*/
    sf::Time zSpawnDelay = sf::seconds(1.0f);
    /*Voici le délais pour le changement de munition*/
    sf::Time cMunitionDelay = sf::seconds(0.2f);
    /*Voici le délais pour le score*/
    sf::Time scoreDelay = sf::seconds(0.5f);
    /*Voici le délais pour le rate spawn des zombies*/
    sf::Time rateChangeDelay = sf::seconds(45);
    /*Voici les valeurs de rate spawn des zombies*/
    const float VARIATION_RATE_CHANGE = 0.15f;
    const float MAX_VARIATION_RATE_CHANGE = 0.2f;
    bool canChangeSpawn = true;
    /*Voici les valeurs de points pour le score*/
    int basicKillPoints = 100;
    int inDelayKillPoints = 10;
    int delayVariation = 0;
    const int MAX_DELAY_POINTS = 500;
    const int TRANCHE_POINTS = 50000;
    int trancheCourante = TRANCHE_POINTS;
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
    int nbProjsFlame = 10;
    int nbProjsMissile = 20;
    int nbProjsScatter = 25;
    /*Chances de dropper un pack de projectiles*/
    int chancesPackDrop = 5;
    /*Index du projectile courant*/
    int curProj = 0;
    /*Score du jeu*/
    int currentScore = 0;
    /*Munition courante*/
    std::string munitionCourante = "Basique";

    Font police;
    Text texte;
    Music musique;

    //Booléen des inputs
    bool gauche = false;
    bool droite = false;
    bool haut = false;
    bool bas = false;

    bool click = false;
    
    bool changeMunition = false;

    /*Fin du transfert supposé vers les classes*/

    bool init();
    void getInputs();
    void update();
    void draw();

    void ajusterDepassementLimitesVue();
    void UpdaterScoreJeu();

    Mouse mouse;
    RenderWindow mainWin;
    View view;
    Event event;
};