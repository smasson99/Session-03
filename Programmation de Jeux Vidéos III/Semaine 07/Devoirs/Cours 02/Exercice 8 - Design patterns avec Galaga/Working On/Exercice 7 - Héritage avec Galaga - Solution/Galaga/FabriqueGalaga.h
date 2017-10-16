#pragma once

#include "Galaga.h"
#include "Butterfly.h"
#include "Wasp.h"
#include "Catcher.h"
#include <SFML\Graphics.hpp>

namespace galaga
{
    class FabriqueGalaga
    {
    public:
        //Enum des sprites de Galaga, selon leurs positions dans la sheet
        enum Galagas { WASP, BUTTERFLY, CATCHER };
        static void ChargerData(int vitesseG, int nbrNiveauxG, int nbrAnimsG, RenderWindow* renderWindowG);
        void SetPosition(float x, float y);
        static void SetPosition(sf::Vector2f positionG);
        static Galaga* FabriquerGalaga(Galagas type);
    private:
        static Vector2f position;
        static int vitesse;
        static int nbrNiveaux;
        static int nbrAnims;
        static RenderWindow* renderWindow;
    };
}
