
// Premi�re "section" d'un fichier .cpp
// ==> inclusion des fichiers d'ent�te n�cessaires
// ==> Pour que toutes les fonctions et toutes les 
//     d�clarations des classes n�cessaires soient
//     connues avant de les utiliser


// Deuxi�me section facultative: les "using"
// ==> Tous les types de donn�es et toutes les fonctions
//     globales sont dans un espace de nom.  On peut 
//     sp�cifier un "using namespace XYZ;" pour faciliter 
//     l'�criture et la lecture du code
//using namespace std;
#include <iostream>
#include <string>

// Les includes "standards" (pas ceux des fichiers que l'on 
// cr�e dans notre projet sont entre <>. Ceux provenant de 
// notre projet sont entre "".
#include "IpProvider.h"
/// Exemple de fonction globale, non rattach�e � une classe.
std::string GetIP()
{
	return "192.168.1.100";
}

/// <summary>
/// Mains this instance.
/// </summary>
void main()
{
    
    // Pour supporter les caract�res accentu�s
	setlocale(LC_ALL, "");

	// Affichage � la console
	// cout ==> Console OUTput
	//          =       ===
	std::cout << "D�but du programme\n"; 
	// Avec l'instruction using namespace std;
	//cout << "D�but du programme\n";



	//*************************
	// Version proc�durale
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