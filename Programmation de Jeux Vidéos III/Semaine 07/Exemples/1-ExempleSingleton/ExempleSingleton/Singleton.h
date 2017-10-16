#pragma once
#pragma once

#include <string>

namespace DesignPatterns
{
	class Singleton
	{
	public:
		//Ceci est dans tous les singletons
		static Singleton *getInstance();
		static void release();

		//Méthodes portées par ce singleton en particulier
		std::string stringQuelconque() const;
		int getContenu() const;
		void setContenu(const int valeur);

	private:
		//Ceci est dans tous les singletons
		Singleton();				       // constructeur privé
		static Singleton *instance;        // pointeur statique vers le singleton

		Singleton(const Singleton&);       // déclarer (sans les définir) les opérations de
		void operator=(const Singleton&);  // copie en private, pour empêcher leur utilisation
		
		//Attributs portées par ce singleton en particulier
		int contenu;
	};
}

