#include <vld.h>
#include "Singleton.h"
#include <iostream>

using namespace DesignPatterns;

void main()
{
	std::cout << Singleton::getInstance()->getContenu() <<std::endl;        //On cr�e l'instance en m�me temps que l'on va lire le contenu � 0.
	Singleton::getInstance()->setContenu(77);                               //On met le contenu 77.
	std::cout << Singleton::getInstance()->getContenu() << std::endl;       //L'instance est pr�sente: contenu � 77
	std::cout << Singleton::getInstance()->stringQuelconque() << std::endl; 
	Singleton::getInstance()->release();                                    //On lib�re l'instance
	std::cout << Singleton::getInstance()->getContenu() << std::endl;       //On en cr�e une nouvelle: contenu � 0
	Singleton::getInstance()->release();                                    //On lib�re l'instance � nouveau: r�le de destructeur pour �viter les leaks                                                                      
	system("pause");
}