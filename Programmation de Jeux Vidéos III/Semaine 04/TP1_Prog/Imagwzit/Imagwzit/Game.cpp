#include "Game.h"

Game::Game()
{
    //On place dans le contructeur ce qui permet à la game elle-même de fonctionner
    clockZR.restart();
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
    //Réservation des espaces nécessaires
    
    //Projectiles
    //Bullet
    projectiles.reserve(300);
    //Flame
    flameProjectiles.reserve(100);
    //Missile
    missileProjectiles.reserve(100);
    //Scatter
    scatterProjectiles.reserve(100);

    //Packs
    //Flame
    flamePacks.reserve(75);
    //Missile
    missilePacks.reserve(75);
    //Scatter
    scatterPacks.reserve(75);
    //Les zombies
    zombies.reserve(600);


    //Initialisation des vecteurs:
    //Les projectiles
    //Bullet
    for (int i = 0; i < projectiles.capacity(); ++i)
    {
        projectiles.push_back(player.CreateProjectile());
    }
    //Flame
    for (int i = 0; i < flameProjectiles.capacity(); ++i)
    {
        flameProjectiles.push_back(player.CreateProjectile());
    }
    //Missile
    for (int i = 0; i < missileProjectiles.capacity(); ++i)
    {
        missileProjectiles.push_back(player.CreateProjectile());
    }
    //Scatter
    for (int i = 0; i < scatterProjectiles.capacity(); ++i)
    {
        scatterProjectiles.push_back(player.CreateProjectile());
    }

    //Les packs
    //Flame
    for (int i = 0; i < flamePacks.capacity(); ++i)
    {
        flamePacks.push_back(GameObject());
    }
    //Missile
    for (int i = 0; i < missilePacks.capacity(); ++i)
    {
        missilePacks.push_back(GameObject());
    }
    //Scatter
    for (int i = 0; i < scatterPacks.capacity(); ++i)
    {
        scatterPacks.push_back(GameObject());
    }
    //Les zombies
    for (int i = 0; i < zombies.capacity(); ++i)
    {
        zombies.push_back(Zombie());
    }

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


    //Initiation des projectiles
    //Courant
    for (int i = 0; i < projectiles.size(); ++i)
    {
        if (projectiles.at(i).Init("Sprites\\Projectiles\\Bullet.png") == false)
        {
            return false;
        }
    }
    //Flame
    for (int i = 0; i < flameProjectiles.size(); ++i)
    {
        if (flameProjectiles.at(i).Init("Sprites\\Projectiles\\Flame.png") == false)
        {
            return false;
        }
    }
    //Missile
    for (int i = 0; i < missileProjectiles.size(); ++i)
    {
        if (missileProjectiles.at(i).Init("Sprites\\Projectiles\\Missile.png") == false)
        {
            return false;
        }
    }
    //Scatter
    for (int i = 0; i < scatterProjectiles.size(); ++i)
    {
        if (scatterProjectiles.at(i).Init("Sprites\\Projectiles\\Scatter.png") == false)
        {
            return false;
        }
    }
    //Initialisation des packs
    //Flame
    for (int i = 0; i < flamePacks.size(); ++i)
    {
        if (flamePacks.at(i).Init("Sprites\\Logos\\FlameLogo.png") == false)
        {
            return false;
        }
    }
    //Missile
    for (int i = 0; i < missilePacks.size(); ++i)
    {
        if (missilePacks.at(i).Init("Sprites\\Logos\\MissileLogo.png") == false)
        {
            return false;
        }
    }
    //Scatter
    for (int i = 0; i < scatterPacks.size(); ++i)
    {
        if (scatterPacks.at(i).Init("Sprites\\Logos\\ScatterLogo.png") == false)
        {
            return false;
        }
    }
    //Initialisation des zombies
    for (int i = 0; i < zombies.size(); ++i)
    {
        std::uniform_int_distribution<int> genZombieAsset(1, 3);
        int pos = genZombieAsset(generator);
        std::string path = "Sprites\\FreeArt\\Zombie";
        if (zombies.at(i).Init("Sprites\\ZombiesAndSurvivors\\Zombie" + std::to_string(pos) + ".png") == false)
        {
            return false;
        }
    }

    if (!terrainT.loadFromFile("Sprites\\Terrain.jpg"))
    {
        return false;
    }

    if (player.Init("Sprites\\FreeArt\\Joueur.png") == false)
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

    /*Appliquer la texture au terrain*/
    terrain.setTexture(terrainT);
    /*Placer le terrain*/
    terrain.setPosition(0, 0);

    /*Placer le joueur au centre de la map*/
    player.SetPosition(CENTRE_MONDE_X, CENTRE_MONDE_Y);

    /*Ajouter le texte des statistiques au jeu*/
    texte.setString("Vies: " + std::to_string(player.GetHealthPoints()) + " Munitions: " + std::to_string(nbProjsPlayer) + "\n" + 
    "Flammes: " + std::to_string(nbProjsFlame) + " Missiles: " + std::to_string(nbProjsMissile) + " Particules: " + 
        std::to_string(nbProjsScatter));
    texte.setFont(police);
    texte.setCharacterSize(30);
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
    //Pour le contrôle avec les flèches du clavier et WASD
    (Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W)) ? haut = true : haut = false;
    (Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S)) ? bas = true : bas = false;
    (Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::A)) ? gauche = true : gauche = false;
    (Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::D)) ? droite = true : droite = false;
    //Pour le changement de munition
    (Keyboard::isKeyPressed(Keyboard::Q)) ? changeMunition = true : changeMunition = false;
    //Pour les clicks
    (Mouse::isButtonPressed(Mouse::Left)) ? click = true : click = false;
}

//Vous devrez centrer la vue sur le joueur: https://www.sfml-dev.org/tutorials/2.4/graphics-view-fr.php
void Game::update()
{
    //Déclaration des variables
    float moveX = 0.0f;
    float moveY = 0.0f;
    //Effectuer un mouvement selon les booléens indiquateurs
    if (gauche) moveX -= 5.0f;
    if (droite) moveX += 5.0f;
    if (haut) moveY -= 5.0f;
    if (bas) moveY += 5.0f;

    //Changer les munitions si le bouton est pressé
    if (changeMunition)
    {
        curProj++;
        if (curProj > 3)
            curProj = 0;
    }

    //Si click et assez de munition, ajouter un projectile
    if (click)
    {
        if (player.CanFire())
        {
            switch (curProj)
            {
                //Bullet
            case 0:
                if (nbProjsPlayer > 0)
                {
                    for (int i = 0; i < projectiles.capacity(); ++i)
                    {
                        if (projectiles.at(i).IsEnable() == false)
                        {
                            projectiles.at(i).SetEnable(true, player.GetPosition(), player.GetAngle());
                            nbProjsPlayer--;
                            if (nbProjsPlayer < 0)
                                nbProjsPlayer = 0;
                            break;
                        }
                    }
                }
                break;
                //Flame
            case 1:
                if (nbProjsFlame > 0)
                {
                    for (int i = 0; i < flameProjectiles.capacity(); ++i)
                    {
                        if (flameProjectiles.at(i).IsEnable() == false)
                        {
                            flameProjectiles.at(i).SetEnable(true, player.GetPosition(), player.GetAngle());
                            nbProjsFlame--;
                            if (nbProjsFlame < 0)
                                nbProjsFlame = 0;
                            break;
                        }
                    }
                }
                break;
                //Missile
            case 2:
                if (nbProjsMissile > 0)
                {
                    for (int i = 0; i < missileProjectiles.capacity(); ++i)
                    {
                        if (missileProjectiles.at(i).IsEnable() == false)
                        {
                            missileProjectiles.at(i).SetEnable(true, player.GetPosition(), player.GetAngle());
                            nbProjsMissile--;
                            if (nbProjsMissile < 0)
                                nbProjsMissile = 0;
                            break;
                        }
                    }
                }
                break;
                //Scatter
            case 3:
                if (nbProjsScatter > 0)
                {
                    for (int i = 0; i < scatterProjectiles.capacity(); ++i)
                    {
                        if (scatterProjectiles.at(i).IsEnable() == false)
                        {
                            scatterProjectiles.at(i).SetEnable(true, player.GetPosition(), player.GetAngle());
                            nbProjsScatter--;
                            if (nbProjsScatter < 0)
                                nbProjsScatter = 0;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    //Si le timer est passé, ajouter un zombie au jeu
    if (clockZR.getElapsedTime().asSeconds() > zSpawnDelay.asSeconds())
    {
        for (int i = 0; i < zombies.capacity(); ++i)
        {
            if (zombies.at(i).IsEnable() == false)
            {
                std::uniform_int_distribution<int> genZombiePosX(0, terrainT.getSize().x);
                std::uniform_int_distribution<int> genZombiePosY(0, terrainT.getSize().y);
                zombies.at(i).SetEnabled(true, genZombiePosX(generator), genZombiePosY(generator));
                clockZR.restart();
                break;
            }
        }
    }
    //Pour chaque projectile
    //Bullet
    for (int i = 0; i < projectiles.size(); ++i)
    {
        //Updater chacun des projectiles
        if (projectiles.at(i).IsEnable())
        {
            projectiles.at(i).Update();
        }
        //Dans le cas d'une sortie de zone
        if (projectiles.at(i).GetX() < 0 ||
            projectiles.at(i).GetY() < 0 ||
            projectiles.at(i).GetX() > terrainT.getSize().x ||
            projectiles.at(i).GetY() > terrainT.getSize().y)
        {
            //Désactiver les projectiles
            projectiles.at(i).SetEnable(false, player.GetPosition(), player.GetAngle());
        }
    }
    //Flame
    for (int i = 0; i < flameProjectiles.size(); ++i)
    {
        //Updater chacun des projectiles
        if (flameProjectiles.at(i).IsEnable())
        {
            flameProjectiles.at(i).Update();
        }
        //Dans le cas d'une sortie de zone
        if (flameProjectiles.at(i).GetX() < 0 ||
            flameProjectiles.at(i).GetY() < 0 ||
            flameProjectiles.at(i).GetX() > terrainT.getSize().x ||
            flameProjectiles.at(i).GetY() > terrainT.getSize().y)
        {
            //Désactiver les projectiles
            flameProjectiles.at(i).SetEnable(false, player.GetPosition(), player.GetAngle());
        }
    }
    //Missile
    for (int i = 0; i < missileProjectiles.size(); ++i)
    {
        //Updater chacun des projectiles
        if (missileProjectiles.at(i).IsEnable())
        {
            missileProjectiles.at(i).Update();
        }
        //Dans le cas d'une sortie de zone
        if (missileProjectiles.at(i).GetX() < 0 ||
            missileProjectiles.at(i).GetY() < 0 ||
            missileProjectiles.at(i).GetX() > terrainT.getSize().x ||
            missileProjectiles.at(i).GetY() > terrainT.getSize().y)
        {
            //Désactiver les projectiles
            missileProjectiles.at(i).SetEnable(false, player.GetPosition(), player.GetAngle());
        }
    }
    //Scatter
    for (int i = 0; i < scatterProjectiles.size(); ++i)
    {
        //Updater chacun des projectiles
        if (scatterProjectiles.at(i).IsEnable())
        {
            scatterProjectiles.at(i).Update();
        }
        //Dans le cas d'une sortie de zone
        if (scatterProjectiles.at(i).GetX() < 0 ||
            scatterProjectiles.at(i).GetY() < 0 ||
            scatterProjectiles.at(i).GetX() > terrainT.getSize().x ||
            scatterProjectiles.at(i).GetY() > terrainT.getSize().y)
        {
            //Désactiver les projectiles
            scatterProjectiles.at(i).SetEnable(false, player.GetPosition(), player.GetAngle());
        }
    }

    //Bouger la caméra lorsque le joueur est dans le range valide
    if (player.GetX() >= LIMITE_VUE_MIN_X && player.GetX() <= LIMITE_VUE_MAX_X)
    {
        view.move(moveX, 0);
    }
    if (player.GetY() >= LIMITE_VUE_MIN_Y && player.GetY() <= LIMITE_VUE_MAX_Y)
    {
        view.move(0, moveY);
    }

    //Déplacer le joueur
    if (player.GetX() <= LARGEUR_MONDE - 45 && player.GetX() >= 45 &&
        player.GetY() <= HAUTEUR_MONDE - 45 && player.GetY() >= 45)
    {
        player.SetPosition(player.GetX() + moveX, player.GetY() + moveY);
    }
    else if (player.GetX() < 45)
        player.SetPosition(45, player.GetY());
    else if (player.GetY() < 45)
        player.SetPosition(player.GetX(), 45);
    else if (player.GetX() > LARGEUR_MONDE - 45)
        player.SetPosition(LARGEUR_MONDE - 45, player.GetY());
    else if (player.GetY() > HAUTEUR_MONDE - 45)
        player.SetPosition(player.GetX(), HAUTEUR_MONDE - 45);

    //Position de la souris
    sf::Vector2f mousePos = mainWin.mapPixelToCoords(mouse.getPosition(mainWin));
    //Position du joueur
    sf::Vector2f playerPos = player.GetPosition();

    //Updater...
    //Le joueur
    player.Update(mousePos.x, mousePos.y);
    //Les zombies
    for (int i = 0; i < zombies.capacity(); ++i)
    {
        if (zombies.at(i).IsEnable())
        {
            zombies.at(i).Update(playerPos.x, playerPos.y);
        }
    }

    //Vérifier les collisions et réagir en fonction des conflicts
    //D'abord, le joueur et les zombies
    for (int i = 0; i < zombies.size(); ++i)
    {
        if (zombies.at(i).IsEnable() && player.GetCollider().verifierCollision(zombies.at(i).GetCollider()))
        {
            /*Le joueur s'est fait toucher par un zombie, perte d'un point de vie et respawn
            s'il lui en reste.*/
            player.SetPosition(CENTRE_MONDE_X, CENTRE_MONDE_Y);
            view.setCenter(player.GetX(), player.GetY());
            player.Hit();
            texte.setString("Vies: " + std::to_string(player.GetHealthPoints()) + "\n" + "Munitions: " + std::to_string(nbProjsPlayer));
            break;
        }
    }
    //Ensuite, les projectiles et les zombies
    //Bullet
    for (int i = 0; i < projectiles.size(); ++i)
    {
        bool canBreak = false;
        if (projectiles.at(i).IsEnable())
        {
            for (int j = 0; j < zombies.size(); ++j)
            {
                if (zombies.at(j).IsEnable() && zombies.at(j).GetCollider().verifierCollision(projectiles.at(i).GetCollider()))
                {
                    //Intervalle de chances de dropper un pack
                    std::uniform_int_distribution<int> genChancesMunPack(1, 100);
                    std::uniform_int_distribution<int> typePack(1, 3);
                    //Position courante du zombie
                    sf::Vector2f curPos = zombies.at(j).GetPosition();
                    //Projectile collide avec zombie, tuer le zombie
                    zombies.at(j).SetEnabled(false, curPos.x, curPos.y);
                    projectiles.at(i).SetEnable(false, curPos, 0.0f);
                    //Selon les chances, dropper un pack de projectile
                    if (genChancesMunPack(generator) > 100 - chancesPackDrop)
                    {
                        int res = typePack(generator);
                        switch (res)
                        {
                            //Flame
                        case 1:
                            for (int p = 0; p < flamePacks.size(); ++p)
                            {
                                if (flamePacks.at(p).IsEnable() == false)
                                {
                                    flamePacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                            //Missile
                        case 2:
                            for (int p = 0; p < missilePacks.size(); ++p)
                            {
                                if (missilePacks.at(p).IsEnable() == false)
                                {
                                    missilePacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                            //Scatter
                        case 3:
                            for (int p = 0; p < scatterPacks.size(); ++p)
                            {
                                if (scatterPacks.at(p).IsEnable() == false)
                                {
                                    scatterPacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                        default:
                            std::cout << "La génération du random des packs s'est terminée avec un erreur" << std::endl;
                            break;
                        }
                    }
                    //Briser la boucle
                    canBreak = true;
                    break;
                }
            }
        }
        if (canBreak)
            break;
    }
    //Flame
    for (int i = 0; i < flameProjectiles.size(); ++i)
    {
        bool canBreak = false;
        if (flameProjectiles.at(i).IsEnable())
        {
            for (int j = 0; j < zombies.size(); ++j)
            {
                if (zombies.at(j).IsEnable() && zombies.at(j).GetCollider().verifierCollision(flameProjectiles.at(i).GetCollider()))
                {
                    //Intervalle de chances de dropper un pack
                    std::uniform_int_distribution<int> genChancesMunPack(1, 100);
                    std::uniform_int_distribution<int> typePack(1, 3);
                    //Position courante du zombie
                    sf::Vector2f curPos = zombies.at(j).GetPosition();
                    //Projectile collide avec zombie, tuer le zombie
                    zombies.at(j).SetEnabled(false, curPos.x, curPos.y);
                    flameProjectiles.at(i).SetEnable(false, curPos, 0.0f);
                    //Selon les chances, dropper un pack de projectile
                    if (genChancesMunPack(generator) > 100 - chancesPackDrop)
                    {
                        int res = typePack(generator);
                        switch (res)
                        {
                            //Flame
                        case 1:
                            for (int p = 0; p < flamePacks.size(); ++p)
                            {
                                if (flamePacks.at(p).IsEnable() == false)
                                {
                                    flamePacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                            //Missile
                        case 2:
                            for (int p = 0; p < missilePacks.size(); ++p)
                            {
                                if (missilePacks.at(p).IsEnable() == false)
                                {
                                    missilePacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                            //Scatter
                        case 3:
                            for (int p = 0; p < scatterPacks.size(); ++p)
                            {
                                if (scatterPacks.at(p).IsEnable() == false)
                                {
                                    scatterPacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                        default:
                            std::cout << "La génération du random des packs s'est terminée avec un erreur" << std::endl;
                            break;
                        }
                    }
                    //Briser la boucle
                    canBreak = true;
                    break;
                }
            }
        }
        if (canBreak)
            break;
    }
    //Missile
    for (int i = 0; i < missileProjectiles.size(); ++i)
    {
        bool canBreak = false;
        if (missileProjectiles.at(i).IsEnable())
        {
            for (int j = 0; j < zombies.size(); ++j)
            {
                if (zombies.at(j).IsEnable() && zombies.at(j).GetCollider().verifierCollision(missileProjectiles.at(i).GetCollider()))
                {
                    //Intervalle de chances de dropper un pack
                    std::uniform_int_distribution<int> genChancesMunPack(1, 100);
                    std::uniform_int_distribution<int> typePack(1, 3);
                    //Position courante du zombie
                    sf::Vector2f curPos = zombies.at(j).GetPosition();
                    //Projectile collide avec zombie, tuer le zombie
                    zombies.at(j).SetEnabled(false, curPos.x, curPos.y);
                    missileProjectiles.at(i).SetEnable(false, curPos, 0.0f);
                    //Selon les chances, dropper un pack de projectile
                    if (genChancesMunPack(generator) > 100 - chancesPackDrop)
                    {
                        int res = typePack(generator);
                        switch (res)
                        {
                            //Flame
                        case 1:
                            for (int p = 0; p < flamePacks.size(); ++p)
                            {
                                if (flamePacks.at(p).IsEnable() == false)
                                {
                                    flamePacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                            //Missile
                        case 2:
                            for (int p = 0; p < missilePacks.size(); ++p)
                            {
                                if (missilePacks.at(p).IsEnable() == false)
                                {
                                    missilePacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                            //Scatter
                        case 3:
                            for (int p = 0; p < scatterPacks.size(); ++p)
                            {
                                if (scatterPacks.at(p).IsEnable() == false)
                                {
                                    scatterPacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                        default:
                            std::cout << "La génération du random des packs s'est terminée avec un erreur" << std::endl;
                            break;
                        }
                    }
                    //Briser la boucle
                    canBreak = true;
                    break;
                }
            }
        }
        if (canBreak)
            break;
    }
    //Scatter
    for (int i = 0; i < scatterProjectiles.size(); ++i)
    {
        bool canBreak = false;
        if (scatterProjectiles.at(i).IsEnable())
        {
            for (int j = 0; j < zombies.size(); ++j)
            {
                if (zombies.at(j).IsEnable() && zombies.at(j).GetCollider().verifierCollision(scatterProjectiles.at(i).GetCollider()))
                {
                    //Intervalle de chances de dropper un pack
                    std::uniform_int_distribution<int> genChancesMunPack(1, 100);
                    std::uniform_int_distribution<int> typePack(1, 3);
                    //Position courante du zombie
                    sf::Vector2f curPos = zombies.at(j).GetPosition();
                    //Projectile collide avec zombie, tuer le zombie
                    zombies.at(j).SetEnabled(false, curPos.x, curPos.y);
                    scatterProjectiles.at(i).SetEnable(false, curPos, 0.0f);
                    //Selon les chances, dropper un pack de projectile
                    if (genChancesMunPack(generator) > 100 - chancesPackDrop)
                    {
                        int res = typePack(generator);
                        switch (res)
                        {
                            //Flame
                        case 1:
                            for (int p = 0; p < flamePacks.size(); ++p)
                            {
                                if (flamePacks.at(p).IsEnable() == false)
                                {
                                    flamePacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                            //Missile
                        case 2:
                            for (int p = 0; p < missilePacks.size(); ++p)
                            {
                                if (missilePacks.at(p).IsEnable() == false)
                                {
                                    missilePacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                            //Scatter
                        case 3:
                            for (int p = 0; p < scatterPacks.size(); ++p)
                            {
                                if (scatterPacks.at(p).IsEnable() == false)
                                {
                                    scatterPacks.at(p).SetEnabled(true, curPos.x, curPos.y);
                                    break;
                                }
                            }
                            break;
                        default:
                            std::cout << "La génération du random des packs s'est terminée avec un erreur" << std::endl;
                            break;
                        }
                    }
                    //Briser la boucle
                    canBreak = true;
                    break;
                }
            }
        }
        if (canBreak)
            break;
    }

    //Les packs et le joueur
    //Flame
    for (int i = 0; i < flamePacks.size(); ++i)
    {
        //Vérifier s'il y a collision
        if (flamePacks.at(i).IsEnable() && player.GetCollider().verifierCollision(flamePacks.at(i).GetCollider()))
        {
            //Il y a collision entre le joueur et le pack
            //Ajouter une munition spéciale et des munitions de base
            nbProjsFlame++;
            nbProjsPlayer += 50;
            flamePacks.at(i).SetEnabled(false);
            break;
        }
    }
    //Missile
    for (int i = 0; i < missilePacks.size(); ++i)
    {
        //Vérifier s'il y a collision
        if (missilePacks.at(i).IsEnable() && player.GetCollider().verifierCollision(missilePacks.at(i).GetCollider()))
        {
            //Il y a collision entre le joueur et le pack
            //Ajouter une munition spéciale et des munitions de base
            nbProjsMissile++;
            nbProjsPlayer += 50;
            missilePacks.at(i).SetEnabled(false);
            break;
        }
    }
    //Scatter
    for (int i = 0; i < scatterPacks.size(); ++i)
    {
        //Vérifier s'il y a collision
        if (scatterPacks.at(i).IsEnable() && player.GetCollider().verifierCollision(scatterPacks.at(i).GetCollider()))
        {
            //Il y a collision entre le joueur et le pack
            //Ajouter une munition spéciale et des munitions de base
            nbProjsScatter++;
            nbProjsPlayer += 50;
            scatterPacks.at(i).SetEnabled(false);
            break;
        }
    }
    //Ajuster la caméra
    ajusterDepassementLimitesVue();
    //Updater et seter les positions de l'interface
    texte.setString("Vies: " + std::to_string(player.GetHealthPoints()) + " Munitions: " + std::to_string(nbProjsPlayer) + "\n" +
        "(1)Flammes: " + std::to_string(nbProjsFlame) + " (2)Missiles: " + std::to_string(nbProjsMissile) + " (3)Particules: " +
        std::to_string(nbProjsScatter));
    texte.setPosition(view.getCenter().x -600, view.getCenter().y - 350);
}

void Game::draw()
{
    //Toujours important d'effacer l'écran précédent
    mainWin.clear();
    mainWin.setView(view);

    mainWin.draw(terrain);
    player.Draw(mainWin);
    mainWin.draw(texte);

    //Pour chaque projectile
    for (int i = 0; i < projectiles.size(); ++i)
    {
        //Dessiner chacun des projectiles actifs
        if (projectiles.at(i).IsEnable())
            projectiles.at(i).Draw(mainWin);
    }
    //Pour chaque packs
    //Flame
    for (int i = 0; i < flamePacks.size(); ++i)
    {
        //Dessiner chacun des packs actifs
        if (flamePacks.at(i).IsEnable())
        {
            flamePacks.at(i).Draw(mainWin);
        }
    }
    //Missile
    for (int i = 0; i < missilePacks.size(); ++i)
    {
        //Dessiner chacun des packs actifs
        if (missilePacks.at(i).IsEnable())
        {
            missilePacks.at(i).Draw(mainWin);
        }
    }
    //Scatter
    for (int i = 0; i < scatterPacks.size(); ++i)
    {
        //Dessiner chacun des packs actifs
        if (scatterPacks.at(i).IsEnable())
        {
            scatterPacks.at(i).Draw(mainWin);
        }
    }
    //Pour chaque zombie
    for (int i = 0; i < zombies.capacity(); ++i)
    {
        //Dessiner chacun des zombies actifs
        if (zombies.at(i).IsEnable())
        {
            zombies.at(i).Draw(mainWin);
        }
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