// Dans un .cpp, on inclut le .h correspondant
// On peut ajouter les autres .h n�cessaires au besoin
#include "IpProvider.h"

// D�finition d'une m�thode
// Toujours la m�me syntaxe: TypeRetour Port�e::NomM�thode
IPProvider::IPProvider()
{
  // Quand on passe l'{, TOUTES les propri�t�s ont �t� initialis�es. Si on ne fait
  // rien, c'est le constructeur sans param�tre de chaque type qui est appel�.

  // On peut choisir d'appeler un autre constructeur si on le d�sire.

  // En C++, il est TRES important d'initialiser toutes les propri�t�s
  ip = "192.168.1.100";
}

std::string IPProvider::GetIP()
{
  return ip;
}