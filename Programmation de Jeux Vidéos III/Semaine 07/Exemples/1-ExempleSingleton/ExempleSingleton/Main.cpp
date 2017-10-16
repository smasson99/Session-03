#include <vld.h>
#include "Singleton.h"
#include <iostream>

using namespace DesignPatterns;

void main()
{
	std::cout << Singleton::getInstance()->getContenu() <<std::endl;        //On crée l'instance en même temps que l'on va lire le contenu à 0.
	Singleton::getInstance()->setContenu(77);                               //On met le contenu 77.
	std::cout << Singleton::getInstance()->getContenu() << std::endl;       //L'instance est présente: contenu à 77
	std::cout << Singleton::getInstance()->stringQuelconque() << std::endl; 
	Singleton::getInstance()->release();                                    //On libère l'instance
	std::cout << Singleton::getInstance()->getContenu() << std::endl;       //On en crée une nouvelle: contenu à 0
	Singleton::getInstance()->release();                                    //On libère l'instance à nouveau: rôle de destructeur pour éviter les leaks                                                                      
	system("pause");
}