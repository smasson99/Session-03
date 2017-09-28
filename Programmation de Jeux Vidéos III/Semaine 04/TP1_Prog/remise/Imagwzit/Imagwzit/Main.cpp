#include <vld.h>
#include "Game.h"

/// <summary>
/// Fonction dont le rôle est de lancer le programme
/// </summary>
/// <returns>Entier vallant 0 si tout s'est bien fonctionné et un autre chiffre si un problème est survenu</returns>
int main()
{
	Game game;
	return game.run();
}