
// Première "section" d'un fichier .cpp
// ==> inclusion des fichiers d'entête nécessaires
// ==> Pour que toutes les fonctions et toutes les 
//     déclarations des classes nécessaires soient
//     connues avant de les utiliser


// Deuxième section facultative: les "using"
// ==> Tous les types de données et toutes les fonctions
//     globales sont dans un espace de nom.  On peut 
//     spécifier un "using namespace XYZ;" pour faciliter 
//     l'écriture et la lecture du code
//using namespace std;
#include <iostream>
#include <string>

// Les includes "standards" (pas ceux des fichiers que l'on 
// crée dans notre projet sont entre <>. Ceux provenant de 
// notre projet sont entre "".
#include "IpProvider.h"
/// Exemple de fonction globale, non rattachée à une classe.
std::string GetIP()
{
	return "192.168.1.100";
}

/// <summary>
/// Mains this instance.
/// </summary>
void main()
{
    
    // Pour supporter les caractères accentués
	setlocale(LC_ALL, "");

	// Affichage à la console
	// cout ==> Console OUTput
	//          =       ===
	std::cout << "Début du programme\n"; 
	// Avec l'instruction using namespace std;
	//cout << "Début du programme\n";



	//*************************
	// Version procédurale
	// std::endl ==> Pour changer de ligne END of Line
	//                                     ===    =
	std::cout << GetIP() << std::endl;			
	//*************************

	//*************************
	// Version "objet"
	//*************************
  // Attention! pas de new
  IPProvider provider; 
  std::cout << provider.GetIP() << std::endl;
	std::cout << "\nFin du programme\n";
	
	
	// Avec l'instruction using namespace std;
	//cout << "\nFin du programme\n";
}