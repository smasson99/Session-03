#include <vld.h>
#include "Game.h"

/// <summary>
/// Fonction dont le r�le est de lancer le programme
/// </summary>
/// <returns>Entier vallant 0 si tout s'est bien fonctionn� et un autre chiffre si un probl�me est survenu</returns>
int main()
{
	Game game;
	return game.run();
}