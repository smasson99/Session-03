#define _USE_MATH_DEFINES

#include "Game.h"
#include "Butterfly.h"
#include "Wasp.h"
#include "Catcher.h"  //Ici, parce que le .h n'est a pas besoin (il a juste des pointeurs de Galagas)
using namespace galaga;

Game::Game()
{
    //On place dans le contructeur ce qui permet à la game elle-même de fonctionner

    mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Galaga");  // , Style::Titlebar); / , Style::FullScreen);
    view = mainWin.getDefaultView();

    //Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes
    //À faire absolument
    mainWin.setFramerateLimit(60);
    mainWin.setVerticalSyncEnabled(true); //Équivalent... normalement
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
    //Aussi bien commencer par le chargement des textures
    if (!backgroundT.loadFromFile("Sprites\\Stars.jpg"))
    {
        return false;
    }

    //Ici chargement dans notre attribut statique
    if (!Galaga::chargerTexture("Sprites\\enemies.png"))
    {
        return false;
    }
    if (!player->chargerTexture("Sprites\\galaga.png"))
    {
        return false;
    }

    background.setTexture(backgroundT);
    background.setPosition(0, 0);

    //Setter la position de départ du spawner
    for (int i = 0; i < nbSpawners; ++i)
    {
        spawners[i].SetPosition(LARGEUR / 2, HAUTEUR / 6);
    }
    //Setter les mouvements initiaux
    for (int i = 0; i < nbSpawners; i += 2)
    {
        right[i] = false;
    }
    //Position depart joueur et size
    player->Initialiser(LARGEUR / 2, mainWin.getSize().y/1.1, 6, &mainWin);
    player->setScale(Vector2f(2, 2));

    /*Galagas[0] = new Butterfly(LARGEUR / 2, 100.0f, VITESSE, BUTTERFLY, NOMBRE_ANIMATIONS, NOMBRE_FRAMES, &mainWin);
    Galagas[1] = new Wasp(LARGEUR / 4, 100.0f, VITESSE, WASP, NOMBRE_ANIMATIONS, NOMBRE_FRAMES, &mainWin);
    Galagas[2] = new Catcher(LARGEUR * 3 / 4, 100.0f, VITESSE, CATCHER, NOMBRE_ANIMATIONS, NOMBRE_FRAMES, &mainWin);*/

    //Positions: quart de l'écran, milleu et trois quart de l'écran (en x)
    galagas.clear();
    FabriqueGalaga::ChargerData(VITESSE, NOMBRE_FRAMES, NOMBRE_ANIMATIONS, &mainWin);
    galagas.push_back(CreateGalaga(FabriqueGalaga::BUTTERFLY));
    galagas.push_back(CreateGalaga(FabriqueGalaga::WASP));
    galagas.push_back(CreateGalaga(FabriqueGalaga::CATCHER));
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

    //Pour le mouvement du joueur
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        if (player->getPosition().x > player->GetLimiteGauche())
        {
            player->deplacement(false);
        }
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        if (player->getPosition().x < player->GetLimiteDroite())
        {
            player->deplacement(true);
        }
    }
}

void Game::update()
{
    for (unsigned i = 0; i < galagas.size(); ++i)
    {
        galagas.at(i)->deplacement();
    }
    //Déplacer le spawner
    for (int i = 0; i < nbSpawners; ++i)
    {
        //Si le spawner arrive à 100 unités d'un rebord, chager direction
        if (spawners[i].GetX() < 100 || spawners[i].GetX() > LARGEUR - 100)
        {
            right[i] = !right[i];
        }
        spawners[i].AutoMoveX(right[i]);
    }
}

void Game::draw()
{
    mainWin.clear();
    mainWin.draw(background);
    mainWin.draw(*player);
    for (int i = 0; i < galagas.size(); i++)
    {
        mainWin.draw(*galagas.at(i));
    }
    //Afficher spawner
    for (int i = 0; i < nbSpawners; ++i)
    {
        spawners[i].Draw(mainWin);
    }
    mainWin.draw(*player);

    mainWin.display();
}

Galaga* Game::CreateGalaga(FabriqueGalaga::Galagas type)
{
    Galaga* myGalaga = FabriqueGalaga::FabriquerGalaga(type);
    std::uniform_int_distribution<int> GenSpawnerIndex(1, 2);
    int index = GenSpawnerIndex(generator);
    myGalaga->setPosition(Vector2f(spawners[index].GetX(), spawners[index].GetY()));
    return myGalaga;
}

void Game::unload()
{
    for (int i = 0; i < galagas.size(); i++)
    {
        //Libération d'un tableau de pointeur avant la fermeture
        delete galagas.at(i);
    }
    delete player;
}