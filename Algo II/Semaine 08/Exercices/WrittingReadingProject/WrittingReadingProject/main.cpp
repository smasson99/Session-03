// WrittingReadingProject.cpp : définit le point d'entrée pour l'application console.

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	/*{
		ofstream oFich("toto.txt");

		for (int i = 1; i < 10; ++i)
			oFich << i << " " << "a " << i + 10 << endl;
	}

	{
		ifstream iFich("toto.txt");
		string line;

		while (getline(iFich, line))
		{
			stringstream l(line);
			int elem1, elem2;
			string junk;

			l >> elem1 >> junk >> elem2;

			cout << elem1 << " " << elem2 << endl;
		}
	}*/


	//Path vers le fichier
	string path = "labo1.txt";
	
	//Début écriture
	/*{
		ofstream ecritureFichier(path);
	}*/
	

	/*Trier: sort <type>(vecteur.begin(), vecteur.end())*/

    //Vecteur de float contenant les additions
    vector<float> additions;
	//Début lecture
	{
		//Handler de lecture du fichier
		ifstream lectureFichier(path);
		//String dans lequel le contenu de la ligne courante sera stocké
		string ligne;

        /*Lire toutes les lignes du fichier.*/
		while (getline(lectureFichier, ligne))
		{
            //Déclaration des variables
			stringstream ligneCourante(ligne);
            float elem1, elem2, elem3, elem4, elem5;
            //Assignation des éléments de la ligne courante
            ligneCourante >> elem1 >> elem2 >> elem3 >> elem4 >> elem5;
            //Ajout de l'addition des éléments courants
            additions.push_back(elem1 + elem2 + elem3 + elem4 + elem5);
		}
	//Fin lecture
	}
    //Vecteur d'entiers représentant le nombre de fois qu'une des additions des données des lignes est répétée
    vector<int> nbFois;
    //Assigner les valeurs par défauts
    for (size_t i = 0; i < additions.size(); ++i)
    {
        nbFois.push_back(0);
    }
    //Détecter le nombre de fois qu'une addition est répétée pour chacune d'elles
    for (size_t i = 0; i < additions.size(); ++i)
    {
        for (size_t j = i + 1; i < additions.size(); ++j)
        {
            if (additions.at(i) == additions.at(j))
            {
                ++nbFois.operator[](i);
                ++nbFois.operator[](j);
            }
        }
    }


    //Début écriture
    {
        ofstream ecritureFichier(path);
    }
	


    return 0;
}

