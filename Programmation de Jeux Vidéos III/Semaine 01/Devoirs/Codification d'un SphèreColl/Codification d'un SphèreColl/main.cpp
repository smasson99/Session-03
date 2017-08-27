#include <iostream> /*Pour la console*/
#include <string> /*Pour les cha�nes de charact�res*/
#include <cmath> /*Pour les calculs*/
#include <list> /*Pour les listes*/
#include <time.h> /*Pour le random*/


#include "CollisionSphere.h"
using namespace FormesGeo;

bool AreColliding(CollisionSphere sphere01, CollisionSphere sphere02)
{
    bool areColliding = false;

    float width = abs(sphere02.GetX() - sphere01.GetX());
    float length = abs(sphere02.GetY() - sphere01.GetY());
    float distance = sqrt(width*width + length*length);
    float distanceLimite = sphere01.GetRayon() + sphere02.GetRayon();

    if (distance < distanceLimite)
        areColliding = true;
    return areColliding;
}

//Version de la g�n�ration manuelle:
//int main()
//{
//    //D�claration des variables:
//    float posXConverted;
//    float posYConverted;
//    float gRayonConverted;
//    const int NB_SPHERES_MAX = 2;
//    int index = 0;
//    bool isPlaying = false;
//    CollisionSphere spheres[NB_SPHERES_MAX];
//
//    //Rendre le groupe de charat�res valide:
//    setlocale(LC_ALL, "");
//    //Message de d�marrage:
//    std::cout << "D�but du lancement du programme : Collisions des Cercles V1.0" << std::endl;
//    std::cout << "Voulez-vous cr�er une sph�re de collision (O/N)?" << std::endl;
//    bool hasAnswer = false;
//    while (hasAnswer == false)
//    {
//        std::string answer;
//        std::getline(std::cin, answer);
//        if (answer == "O" || answer == "o")
//        {
//            hasAnswer = true;
//        }
//        else if (answer == "N" || answer == "n")
//        {
//            hasAnswer = true;
//            return 0;
//        }
//        else
//            std::cout << "Voulez-vous cr�er une sph�re de collision (O/N)?" << std::endl;
//    }
//
//    while (index < NB_SPHERES_MAX)
//    {
//        std::cout << std::endl << "D�but de la g�n�ration de la sph�re de collision #" << index << "." << std::endl;
//        bool hasAnswer = false;
//        while (hasAnswer == false)
//        {
//            std::string posX;
//            std::cout << "Veuillez entrer la position en X de la sph�re :" << std::endl;
//            std::getline(std::cin, posX);
//            //Pas de TryParse???
//            /*if (std::stof(posX))
//            {*/
//            posXConverted = std::stof(posX);
//            hasAnswer = true;
//            /*}*/
//        }
//        hasAnswer = false;
//
//        while (hasAnswer == false)
//        {
//            std::string posY;
//            std::cout << "Veuillez entrer la position en Y de la sph�re :" << std::endl;
//            std::getline(std::cin, posY);
//            //Pas de TryParse???
//            /*if (std::stof(posY))
//            {*/
//            posYConverted = std::stof(posY);
//            hasAnswer = true;
//            /*}*/
//        }
//        hasAnswer = false;
//
//        while (hasAnswer == false)
//        {
//            std::string gRayon;
//            std::cout << "Veuillez entrer la longueur du rayon de la sph�re :" << std::endl;
//            std::getline(std::cin, gRayon);
//            //Pas de TryParse???
//            /*if (std::stof(posY))
//            {*/
//            gRayonConverted = std::stof(gRayon);
//            hasAnswer = true;
//            /*}*/
//        }
//        //Cr�er la sph�re:
//        CollisionSphere newS(posXConverted, posYConverted, gRayonConverted);
//        spheres[index] = newS;
//        index++;
//    }
//
//    bool collFound = false;
//    //Valider si les sph�res se touchent:
//    for (int i = 0; i < NB_SPHERES_MAX; i++)
//    {
//        for (int j = i+1; j < NB_SPHERES_MAX; j++)
//        {
//            if (AreColliding(spheres[i], spheres[j]))
//            {
//                //Envoyer message si collision:
//                std::cout << "Collision trouv�e entre la sph�re #" << i << " et la sph�re #" << j  << "." << std::endl;
//                collFound = true;
//            }
//        }
//    }
//    if (collFound == false)
//        std::cout << "Aucune collision n'a �t� trouv�e entre les sph�res." << std::endl;
//    system("pause");
//    std::cout << std::endl << "G�n�ration des sph�res termin�e. Voulez-vous recommencer (O/N)?" << std::endl;
//    hasAnswer = false;
//    while (hasAnswer == false)
//    {
//        std::string answer;
//        std::getline(std::cin, answer);
//        if (answer == "O" || answer == "o")
//        {
//            hasAnswer = true;
//            main();
//        }
//        else if (answer == "N" || answer == "n")
//        {
//            hasAnswer = true;
//            return 0;
//        }
//        else
//            std::cout << "G�n�ration des sph�res termin�e. Voulez-vous recommencer (O/N)?" << std::endl;
//    }
//}

float Random_Next(int a, int b)
{
    return (float)(rand() % (b - a) + a);
}

int main()
{
    //Initialisation des variables:
    const int NB_SPHERES_GENEREES = 2;
    const int LARGEUR_X = 1360;
    const int HAUTEUR_Y = 720;
    const int G_RAYON_MIN = 20;
    const int G_RAYON_MAX = 200;
    int indexCourant = 0;
    srand(time(NULL));

    CollisionSphere spheres[NB_SPHERES_GENEREES];

    //Ajuster au syst�me de charact�res courant:
    setlocale(LC_ALL, "");
    //G�n�rer les sph�res:
    std::cout << "D�but du lancement du programme de G�n�ration de Sph�res Al�atoires: V1.0" << std::endl;
    for (int i = 0; i < NB_SPHERES_GENEREES; i++)
    {
        bool placeFound = false;
        while (placeFound == false)
        {
            //Instantier les variables temporaires
            float posX = Random_Next(0, LARGEUR_X + 1);
            float posY = Random_Next(0, HAUTEUR_Y + 1);
            float gRayon = Random_Next(G_RAYON_MIN, G_RAYON_MAX + 1);
            bool isColliding = false;

            //S'assurer que la sph�re g�n�r�es ne collide avec aucune autre, autrement, recommencer:
            if (indexCourant > 0)
            {
                for (int currentIndex = 0; currentIndex < indexCourant; currentIndex++)
                {
                    if (indexCourant > 1)
                    {
                        for (int secondIndex = currentIndex + 1; secondIndex < indexCourant; secondIndex++)
                        {
                            if (AreColliding(spheres[currentIndex], spheres[secondIndex]))
                            {
                                isColliding = true;
                                break;
                            }
                        }
                        if (isColliding)
                            break;
                    }
                    else
                        isColliding = false;
                }
            }
            else
                isColliding = false;

            //Si la sph�re ne collide avec personne, assigner la valeur:
            if (isColliding == false)
            {
                placeFound = true;
                spheres[i] = CollisionSphere(posX, posY, gRayon);
                indexCourant++;
            }
        }
    }
    std::cout << "G�n�ration des sph�res r�ussie." << std::endl << std::endl;
    std::cout << "Affichage � la console des informations concernant les sph�res:" << std::endl;
    for (int i = 0; i < NB_SPHERES_GENEREES; i ++)
    {
        std::cout << "Sph�re no:" << i << ". Pos X = " << spheres[i].GetX() << ", Pos Y = " << spheres[i].GetY() << ", Rayon = " << spheres[i].GetRayon() << "." << std::endl;
    }
}