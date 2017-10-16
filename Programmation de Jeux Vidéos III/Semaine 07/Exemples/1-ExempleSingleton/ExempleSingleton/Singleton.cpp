#include "Singleton.h"

using namespace DesignPatterns;

Singleton *Singleton::instance = nullptr;

Singleton::Singleton()
{
	contenu = 0;
}

Singleton* Singleton::getInstance()
{
	if (!instance) 
		instance = new Singleton();
	return instance;
}

void Singleton::release()
{
	delete instance;
	instance = nullptr;
}

std::string Singleton::stringQuelconque() const
{
	return "Fidoudaaaa!!!!";
}

int Singleton::getContenu() const
{
	return contenu;
}

void Singleton::setContenu(const int valeur)
{
	contenu = valeur;
}
