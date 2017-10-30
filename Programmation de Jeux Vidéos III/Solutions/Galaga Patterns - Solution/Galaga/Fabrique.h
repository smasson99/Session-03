#pragma once
#include "Butterfly.h"
#include "Wasp.h"
#include "Catcher.h"

namespace galaga
{
	class FabriqueGalaga
	{
	public:
		static enum Galagas { WASP, BUTTERFLY, CATCHER };

		static void chargerData(int vitesse, RenderWindow* renderWindow)
		{
			FabriqueGalaga::vitesse = vitesse;
			FabriqueGalaga::renderWindow = renderWindow;
		}

		static void setPosition(const Vector2f& position)
		{
			FabriqueGalaga::position = position;
		}

		static Galaga* createGalaga(Galagas demande)
		{
			if (demande == WASP)
			{
				Galaga* g = new Wasp(position.x, position.y, vitesse, WASP, renderWindow);
				g->ajustementsVisuels();
				return g;
			}
			else if (demande == BUTTERFLY)
			{
				Galaga* g = new Butterfly(position.x, position.y, vitesse, BUTTERFLY, renderWindow);
				g->ajustementsVisuels();
				return g;
			}
			else if (demande == CATCHER)
			{
				Galaga* g = new Catcher(position.x, position.y, vitesse, CATCHER, renderWindow);
				g->ajustementsVisuels();
				return g;
			}
			return nullptr;
		}

	private:
		FabriqueGalaga();
		static Vector2f position;
		static int vitesse;
		static RenderWindow* renderWindow;
	};

	Vector2f FabriqueGalaga::position;
	int FabriqueGalaga::vitesse;
	RenderWindow* FabriqueGalaga::renderWindow;
}
