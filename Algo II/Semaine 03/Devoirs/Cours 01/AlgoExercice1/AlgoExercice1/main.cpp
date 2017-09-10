#include "console.h"
#include "sortArray.h"

using namespace std;

int main(char* argv, int argc)
{
	/*
	* Exp�rimentations avec les pointeurs (num�ros 1.1 � 1.4)
	*/

    setlocale(LC_ALL, "");

    /*Les variables courantes*/
    short monShort = 1;
    int monInt = 1;
    long int monLongInt = 1;
    long long int monLongLongInt = 1;
    unsigned long long int monUnsignedLongLongInt = 1;
    bool monBool = true;

    cout << "LES VARIABLES NORMALES" << endl;
    cout << "Taille d'un short (en bits) : " << sizeof(monShort) * 8 << endl;
    cout << "Taille d'un int (en bits) : " << sizeof(monInt) * 8 << endl;
    cout << "Taille d'un long int (en bits) : " << sizeof(monLongInt) * 8 << endl;
    cout << "Taille d'un long long int (en bits) : " << sizeof(monLongLongInt) * 8 << endl;
    cout << "Taille d'un unsigned long long int (en bits) : " << sizeof(monUnsignedLongLongInt) * 8 << endl;
    cout << "Taille d'un bool�en (en bits) : " << sizeof(monBool) * 8 << endl;

    /*Exp�rimentation sur la grandeur des pointeurs*/
    short* monShort2;
    int* monInt2;
    long int* monLongInt2;
    long long int* monLongLongInt2;
    unsigned long long int* monUnsignedLongLongInt2[5];
    bool* monBool2;

    cout << endl << "LES VARIABLES POINTEURS" << endl;
    cout << "Taille d'un pointeur short (en bits) : " << sizeof(monShort2) * 8 << endl;
    cout << "Taille d'un pointeur int (en bits) : " << sizeof(monInt2) * 8 << endl;
    cout << "Taille d'un pointeur long int (en bits) : " << sizeof(monLongInt2) * 8 << endl;
    cout << "Taille d'un pointeur long long int (en bits) : " << sizeof(monLongLongInt2) * 8 << endl;
    cout << "Taille d'un tableau de pointeurs unsigned long long int (en bits) : " << sizeof(monUnsignedLongLongInt2) * 8 << endl;
    cout << "Taille d'un pointeur bool�en (en bits) : " << sizeof(monBool2) * 8 << endl;
    
    /*Exp�rimentation sur l'adresse des pointeurs*/
    float pi = 3.1416;
    float* piPointeur = &pi;
    float** piPointeurPointeur = &piPointeur;

    cout << endl << "LES ADRESSES DE POINTEUR" << endl;
    cout << "Valeur de PI : " << pi << endl;
    cout << "Valeur de PIPointeur : " << *piPointeur << endl;
    cout << "Adresse de PI : " << piPointeur << endl;
    cout << "Adresse de PIPointeur : " << piPointeurPointeur << endl;

    /*Exp�rimentation sur les tableaux de caract�res*/
    char* characters = new char[100];
    char* helloText = "Bonjour � vous!";

    cout << endl << "LES TABLEAUX DE CARACT�RES" << endl;
    cout << "Le hello text: " << helloText << endl;
    delete characters;
    //delete helloText;
	
	/*Exp�rimentations avec les tableaux dynamiques (num�ros 1.5 et suivants)*/
	/*Exp�rimentation sur les tableaux d'entiers*/
    int* size = new int();
    cout << endl << "LES TABLEAUX D'ENTIERS" << endl;
    *size = readInt("Combien de nombres?", "Erreur, la valeur entr�e n'est pas un nombre.");
    int* tabInts = readIntArray(*size, "Entrez un nombre :", "Erreur, la valeur entr�e n'est pas un nombre.");
    showIntArray(tabInts, size);
    

    cout << "D�but du trie du tableau d'entiers:" << endl;
    tabInts = SortArray(tabInts, size);
    showIntArray(tabInts, size);

	delete size;
    delete tabInts;
	showMessage("Appuyez sur une touche pour terminer le programme...");

	//Fin du programme. En C++, si la fonction "main" retourne 0, cela
	//veut dire que le programme a termin� correctement.
	//
	//S'il retourne 1, cela veut dire que le programme ne s'est pas 
	//termin� correctement.

	return 0;
}
