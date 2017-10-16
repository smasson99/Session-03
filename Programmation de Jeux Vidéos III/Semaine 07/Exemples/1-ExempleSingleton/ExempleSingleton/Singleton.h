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

		//M�thodes port�es par ce singleton en particulier
		std::string stringQuelconque() const;
		int getContenu() const;
		void setContenu(const int valeur);

	private:
		//Ceci est dans tous les singletons
		Singleton();				       // constructeur priv�
		static Singleton *instance;        // pointeur statique vers le singleton

		Singleton(const Singleton&);       // d�clarer (sans les d�finir) les op�rations de
		void operator=(const Singleton&);  // copie en private, pour emp�cher leur utilisation
		
		//Attributs port�es par ce singleton en particulier
		int contenu;
	};
}

