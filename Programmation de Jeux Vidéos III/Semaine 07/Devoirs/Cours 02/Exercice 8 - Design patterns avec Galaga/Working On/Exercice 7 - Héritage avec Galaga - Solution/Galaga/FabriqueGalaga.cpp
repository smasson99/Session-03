#include "FabriqueGalaga.h"

using namespace galaga;

Vector2f FabriqueGalaga::position = Vector2f();
int FabriqueGalaga::vitesse = 1;
int FabriqueGalaga::nbrNiveaux = 1;
int FabriqueGalaga::nbrAnims = 1;
RenderWindow* FabriqueGalaga::renderWindow = nullptr;


void FabriqueGalaga::ChargerData(int vitesseG, int nbrNiveauxG, int nbrAnimsG,
    RenderWindow * renderWindowG)
{
    FabriqueGalaga::vitesse = vitesseG;
    FabriqueGalaga::nbrNiveaux = nbrNiveauxG;
    FabriqueGalaga::nbrAnims = nbrAnimsG;
    FabriqueGalaga::renderWindow = renderWindowG;
}

void galaga::FabriqueGalaga::SetPosition(float x, float y)
{
    FabriqueGalaga::position = Vector2f(x, y);
}

void galaga::FabriqueGalaga::SetPosition(sf::Vector2f positionG)
{
    FabriqueGalaga::position = positionG;
}

Galaga * FabriqueGalaga::FabriquerGalaga(Galagas type)
{
    if (type == BUTTERFLY)
    {
        Butterfly* res = new Butterfly(position.x, position.y, 1, (int)BUTTERFLY,
            nbrNiveaux, nbrAnims, renderWindow);
        res->ajustementsVisuels();
        return res;
    }
    if (type == CATCHER)
    {
        Catcher* res = new Catcher(position.x, position.y, 1, (int)CATCHER,
            nbrNiveaux, nbrAnims, renderWindow);
        res->ajustementsVisuels();
        return res;
    }
    if (type == WASP)
    {
        Wasp* res = new Wasp(position.x, position.y, 1, (int)WASP,
            nbrNiveaux, nbrAnims, renderWindow);
        res->ajustementsVisuels();
        return res;
    }
    return nullptr;
}
