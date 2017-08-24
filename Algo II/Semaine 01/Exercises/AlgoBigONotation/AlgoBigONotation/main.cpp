#include <iostream>
#include <sstream>

using namespace std;


void printIsNumberEven(int number)
{
    //Prendre le nombre en entrée et indiquer si, oui ou non, le nombre est pair en effectuant un "cout".
    if (number)
    {
        if (number % 2 == 0)
        {
            cout << "Le nombre : " << number << " est pair." << endl;
        }
        else
        {
            cout << "Le nombre : " << number << " est impair." << endl;
        }
    }
    //Exemple de cout :
    //cout << "Hello World!" << " Un \"cout\" peut contenir plusieurs parties et même " << 1 << " ou plusieurs chiffres." << endl;
}

void printAllEvenNumbersBetweenInclusive(int start, int end)
{
    cout << endl << "Version 01 de nombres pairs entre " << start << " et " << end << "." << endl;
    std::string ligne = "";
    std::string separator = ", ";
    //Imprimer à l'écran tous les nombres pairs entre "start" et "end" inclusivement.
    for (int i = start; i <= end; ++i)
    {
        if (i % 2 == 0)
        {
            ligne += std::to_string(i);
            if (i < end)
                ligne += separator;
            else
                ligne += ".";
        }
    }
    cout << ligne << endl;
}

void printQuantityOfEvenNumbersBetweenInclusiveV1(int start, int end)
{
    //Imprimer à l'écran le nombre de nombres pairs entre "start" et "end" inclusivement.
    //Déclaration des variables:
    int compteur = 0;
    for (int i = start; i <= end; ++i)
    {
        if (i % 2 == 0)
        {
            compteur++;
        }
    }
    cout << "Nombre de nombres pairs entre " << start << " et " << end << " : " <<  compteur << "." << endl;
}

void printQuantityOfEvenNumbersBetweenInclusiveV2(int start, int end)
{
    //Imprimer à l'écran le nombre de nombres pairs entre "start" et "end" inclusivement.
    //Pour cette version, ne pas utiliser de boucle.

    //Déclaration des variables:
    int nombre = 0;
    if (start > end)
    {
        cout << nombre;
    }
    else if (start % 2 == 0)
    {
        nombre++;
        printQuantityOfEvenNumbersBetweenInclusiveV2(start++, end);
    }
    else
    {
        printQuantityOfEvenNumbersBetweenInclusiveV2(start++, end);
    }
}


void printArrayContainsDuplicate(int numbers[], int size)
{
    //Indiquer si le tableau en entrée contient un doublon.
    //En C++, on ne peut pas savoir directement la taille d'un tableau comme en C#.
    //Cela vous est donc envoyé en entrée avec le tableau.
}

//Deux options. Si l'index est plus petit ou égal à 2, alors on est en O(1).
//				Sinon, il y a une boucle en O(n - 1).
//
//Donc...
//
//O(1) en meilleur cas, O(n) en pire cas
void printFibonnacciAtIndexV1(int index)
{
    //Donner le n ieme nombre de la suite de Fibonacci.
    //Voici quelques valeurs de la suite.
    //
    //   +---------+---+---+---+---+---+---+---+----+----+-----+
    //   |  Index  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7  | 8  | ... |
    //   +---------+---+---+---+---+---+---+---+----+----+-----+
    //   | Valeur  | 0 | 1 | 1 | 2 | 3 | 5 | 8 | 13 | 21 | ... |
    //   +---------+---+---+---+---+---+---+---+----+----+-----+

}

int fibonacciRecursive(int index)
{
    //Voir printFibonnacciAtIndexV2
    return 0;
}


void printFibonnacciAtIndexV2(int index)
{
    //Donner le n ieme nombre de la suite de Fibonacci. Cette fois, utiliser une méthode récursive.
    //Voici quelques valeurs de la suite.
    //
    //   +---------+---+---+---+---+---+---+---+----+----+-----+
    //   |  Index  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7  | 8  | ... |
    //   +---------+---+---+---+---+---+---+---+----+----+-----+
    //   | Valeur  | 0 | 1 | 1 | 2 | 3 | 5 | 8 | 13 | 21 | ... |
    //   +---------+---+---+---+---+---+---+---+----+----+-----+
}

void printIsNumberPrime(int number)
{
    //Indiquer si, oui ou non, un nombre est premier.
}

void printQuantityOfPrimesBeforeV1(int end)
{
    //Compter combien de nombres premiers il y a entre 0 et "end" inclusivement.
}

void printQuantityOfPrimesBeforeV2(int end)
{
    //Compter combien de nombres premiers il y a entre 0 et "end" inclusivement.
    //Utiliser l'algorithme vu en classe.
}

void printSortedArrayContainsElementV1(int numbers[], int size, int elementToFind)
{
    //Indiquer si, oui ou non, le tableau trié reçu en entrée contient la valeur.
}

void printSortedArrayContainsElementV2(int numbers[], int size, int elementToFind)
{
    //Indiquer si, oui ou non, le tableau trié reçu en entrée contient la valeur.
    //Utiliser l'algoritme vu en classe.
}

int main(int argc, int* argv)
{
    //Commentez et décomentez les fonctions pour essayer les algorithmes.
    //
    //Notez le caractère « ' » dans 100'000. C'est tout simplement un
    //séparateur pour les miliers, de sorte à rendre ça plus lisible. Cool non ?

    printIsNumberEven(2);
    printIsNumberEven(3);
    printIsNumberEven(10);
    printIsNumberEven(121);

    printAllEvenNumbersBetweenInclusive(1, 100);

    printQuantityOfEvenNumbersBetweenInclusiveV1(1, 100'000);

    printQuantityOfEvenNumbersBetweenInclusiveV2(1, 100/*'000*/);

    /*printArrayContainsDuplicate(new int[5]{5,2,5,1,3}, 5);
    printArrayContainsDuplicate(new int[5]{5,2,4,1,3}, 5);

    printFibonnacciAtIndexV1(0);
    printFibonnacciAtIndexV1(1);
    printFibonnacciAtIndexV1(2);
    printFibonnacciAtIndexV1(3);
    printFibonnacciAtIndexV1(4);
    printFibonnacciAtIndexV1(5);
    printFibonnacciAtIndexV1(6);
    printFibonnacciAtIndexV1(7);
    printFibonnacciAtIndexV1(8);
    printFibonnacciAtIndexV1(9);
    printFibonnacciAtIndexV1(10);

    printFibonnacciAtIndexV2(0);
    printFibonnacciAtIndexV2(1);
    printFibonnacciAtIndexV2(2);
    printFibonnacciAtIndexV2(3);
    printFibonnacciAtIndexV2(4);
    printFibonnacciAtIndexV2(5);
    printFibonnacciAtIndexV2(6);
    printFibonnacciAtIndexV2(7);
    printFibonnacciAtIndexV2(8);
    printFibonnacciAtIndexV2(9);
    printFibonnacciAtIndexV2(10);

    printIsNumberPrime(5);
    printIsNumberPrime(10);

    printQuantityOfPrimesBeforeV1(100'000);

    printQuantityOfPrimesBeforeV2(100'000);

    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 2);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 7);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 9);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 20);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 25);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 55);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 75);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 100);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 200);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 500);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 1);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 5);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 8);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 12);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 22);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 30);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 60);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 80);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 150);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 250);
    printSortedArrayContainsElementV1(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 1000);

    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 2);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 7);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 9);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 20);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 25);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 55);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 75);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 100);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 200);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 500);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 1);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 5);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 8);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 12);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 22);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 30);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 60);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 80);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 150);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 250);
    printSortedArrayContainsElementV2(new int[10]{2,7,9,20,25,55,75,100,200,500}, 10, 1000);*/

    system("pause");
}
