#include "Game.h"

Game::Game()
{
    //On place dans le contructeur ce qui permet à la game elle-même de fonctionner
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
    //Initialisation des timers
    clockCM.restart();
    clockScore.restart();
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
    //Début de l'initialisation des ressources

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
        //Initialisation des valeurs par défaut selon le type de projectile
        flameProjectiles.at(i).SetSpeed(12.0f);
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

    //Initialisation du terrain
    if (!terrainT.loadFromFile("Sprites\\Terrain.jpg"))
    {
        return false;
    }

    //Initialisation du joueur
    if (player.Init("Sprites\\FreeArt\\Joueur.png") == false)
    {
        return false;
    }

    //Initialisation de la police de caractères
    if (!police.loadFromFile("Polices\\segoepr.ttf"))
    {
        return false;
    }

    //Initialisation de la musique de fond du jeu
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

    /*Initialisation du texte du jeu*/
    texte.setFont(police);
    texte.setCharacterSize(30);
    texte.setFillColor(Color::Red);

    //musique.play();
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

    //Changer les munitions si le bouton est pressé et que le temps de délais est passé
    if (changeMunition && clockCM.getElapsedTime().asSeconds() > cMunitionDelay.asSeconds())
    {
        curProj++;
        if (curProj > 3)
            curProj = 0;
        clockCM.restart();
        switch (curProj)
        {
        case 0:
            munitionCourante = "Basique";
            break;
        case 1:
            munitionCourante = "Flammes";
            break;
        case 2:
            munitionCourante = "Missiles";
            break;
        case 3:
            munitionCourante = "Particules";
            break;
        }
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
                    int scatterPos = 0;
                    for (int i = 0; i < scatterProjectiles.capacity(); ++i)
                    {
                        if (scatterProjectiles.at(i).IsEnable() == false && scatterPos < 3)
                        {
                            switch (scatterPos)
                            {
                            case 0:
                                scatterProjectiles.at(i).SetEnable(true, player.GetPosition(), player.GetAngle());
                                ++scatterPos;
                                break;
                            case 1:
                                scatterProjectiles.at(i).SetEnable(true, player.GetPosition(), player.GetAngle() + 20);
                                ++scatterPos;
                                break;
                            case 2:
                                scatterProjectiles.at(i).SetEnable(true, player.GetPosition(), player.GetAngle() - 20);
                                ++scatterPos;
                                break;
                            }
                        }
                        else if (scatterPos >= 3)
                            break;
                    }
                }
                nbProjsScatter--;
                if (nbProjsScatter < 0)
                    nbProjsScatter = 0;
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
                float spawnX;
                float spawnY;
                bool hasFound = false;
                while (hasFound == false)
                {
                    spawnX = genZombiePosX(generator);
                    if (spawnX < player.GetPosition().x - 100 || spawnX > player.GetPosition().x + 100)
                    {
                        hasFound = true;
                    }
                }
                hasFound = false;
                while (hasFound == false)
                {
                    spawnY = genZombiePosX(generator);
                    if (spawnY < player.GetPosition().y - 100 || spawnY > player.GetPosition().y + 100)
                    {
                        hasFound = true;
                    }
                }
                zombies.at(i).SetEnabled(true, spawnX, spawnY);
                clockZR.restart();
                break;
            }
        }
    }
    //Si le timer est passé et qu'il est possible de le faire, accélérer le spawn des zombies
    if (canChangeSpawn && clockRateChange.getElapsedTime().asSeconds() > rateChangeDelay.asSeconds())
    {
        clockRateChange.restart();
        zSpawnDelay = sf::seconds(zSpawnDelay.asSeconds() + VARIATION_RATE_CHANGE);
        if (zSpawnDelay.asSeconds() <= MAX_VARIATION_RATE_CHANGE)
            canChangeSpawn = false;
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
            flameProjectiles.at(i).aScaleFrom(0.05f);
        }
        //Dans le cas d'une sortie de zone
        if (flameProjectiles.at(i).GetX() < 0 ||
            flameProjectiles.at(i).GetY() < 0 ||
            flameProjectiles.at(i).GetX() > terrainT.getSize().x ||
            flameProjectiles.at(i).GetY() > terrainT.getSize().y)
        {
            //Désactiver les projectiles
            flameProjectiles.at(i).SetEnable(false, player.GetPosition(), player.GetAngle());
            flameProjectiles.at(i).ResetScale();
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
        if (zombies.at(i).IsEnable() && !player.IsImmortal() && player.GetCollider().verifierCollision(zombies.at(i).GetCollider()))
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
                    //Updater le score du jeu
                    UpdaterScoreJeu();
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
                    //Updater le score du jeu
                    UpdaterScoreJeu();
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
                    //Updater le score du jeu
                    UpdaterScoreJeu();
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
                    //Projectile collide avec zombie, tuer le zombie et désactiver le projectile
                    zombies.at(j).SetEnabled(false, curPos.x, curPos.y);
                    scatterProjectiles.at(i).SetEnable(false, curPos, 0.0f);
                    //Updater le score du jeu
                    UpdaterScoreJeu();
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
            nbProjsPlayer += 75;
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
            nbProjsMissile += 6;
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
            nbProjsScatter += 10;
            nbProjsPlayer += 60;
            scatterPacks.at(i).SetEnabled(false);
            break;
        }
    }

    //Vérifier si le score a atteind une tranche
    if (currentScore >= trancheCourante)
    {
        //Ajouter un point de vie et avancer la tranche
        player.AddHealthPoints(1);
        trancheCourante += TRANCHE_POINTS;
    }

    //Ajuster la caméra
    ajusterDepassementLimitesVue();
    //Updater et seter les positions de l'interface
    texte.setString("Vies: " + std::to_string(player.GetHealthPoints()) + "\tChanger de Munition: Q" +
        "\tMunitions: " + std::to_string(nbProjsPlayer) + "\tScore: " + std::to_string(currentScore) +
        "\n" + "Flammes: " + std::to_string(nbProjsFlame) + "\tMissiles: " + std::to_string(nbProjsMissile) +
        "\tParticules: " + std::to_string(nbProjsScatter) + "\tMunition courante: " + munitionCourante);
    texte.setPosition(view.getCenter().x - 600, view.getCenter().y - 350);
}

void Game::draw()
{
    //Effacer l'écran précédent
    mainWin.clear();
    mainWin.setView(view);
    //Dessiner le nouvel écran
    mainWin.draw(terrain);
    player.Draw(mainWin);
    mainWin.draw(texte);

    //Pour chaque projectile
    //Bullet
    for (int i = 0; i < projectiles.size(); ++i)
    {
        //Dessiner chacun des projectiles actifs
        if (projectiles.at(i).IsEnable())
            projectiles.at(i).Draw(mainWin);
    }
    //Flame
    for (int i = 0; i < flameProjectiles.size(); ++i)
    {
        //Dessiner chacun des projectiles actifs
        if (flameProjectiles.at(i).IsEnable())
            flameProjectiles.at(i).Draw(mainWin);
    }
    //Missile
    for (int i = 0; i < missileProjectiles.size(); ++i)
    {
        //Dessiner chacun des projectiles actifs
        if (missileProjectiles.at(i).IsEnable())
            missileProjectiles.at(i).Draw(mainWin);
    }
    //Scatter
    for (int i = 0; i < flameProjectiles.size(); ++i)
    {
        //Dessiner chacun des projectiles actifs
        if (scatterProjectiles.at(i).IsEnable())
            scatterProjectiles.at(i).Draw(mainWin);
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
    for (int i = 0; i < zombies.size(); ++i)
    {
        //Dessiner chacun des zombies actifs
        if (zombies.at(i).IsEnable())
        {
            zombies.at(i).Draw(mainWin);
        }
    }

    //Afficher l'écran
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

void Game::UpdaterScoreJeu()
{
    //Updater le score du jeu
    if (clockScore.getElapsedTime().asSeconds() < scoreDelay.asSeconds())
    {
        //Dans ce cas-ci nous avons déjà tué un zombie dans l'intervalle
        if (delayVariation <= MAX_DELAY_POINTS)
        {
            currentScore += inDelayKillPoints;
            delayVariation += inDelayKillPoints;
        }
    }
    else
    {
        //Tandis que dans ce cas-ci nous n'avons pas tué de zombie dans l'intervalle
        currentScore += basicKillPoints;
        delayVariation = 0;
        clockScore.restart();
    }
}
