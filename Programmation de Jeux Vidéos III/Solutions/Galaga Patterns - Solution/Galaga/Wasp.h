#pragma once
#include "Galaga.h"

namespace galaga
{
	class Wasp : public Galaga
	{
	public:
		Wasp(const float posX, const float posY, const float speed, const int niveau, RenderWindow* const renderWindow);
		~Wasp();

		void deplacement();

	private:
		int vague;  //Marqueur de où se trouve dans notre vague par rapport au  centre en x
		int direction;  //Gauche ou droite (-1 / 1)
	};
}
