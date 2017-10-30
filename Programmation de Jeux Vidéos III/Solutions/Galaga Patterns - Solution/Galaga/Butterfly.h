#pragma once
#include "Galaga.h"

namespace galaga
{
	class Butterfly : public Galaga
	{
	public:
		Butterfly(const float posX, const float posY, const float speed, const int niveau, RenderWindow* const renderWindow);
		~Butterfly();

		void deplacement();
	};
}
