// Dans un .cpp, on inclut le .h correspondant
// On peut ajouter les autres .h nécessaires au besoin
#include "IpProvider.h"

// Définition d'une méthode
// Toujours la même syntaxe: TypeRetour Portée::NomMéthode
IPProvider::IPProvider()
{
  // Quand on passe l'{, TOUTES les propriétés ont été initialisées. Si on ne fait
  // rien, c'est le constructeur sans paramètre de chaque type qui est appelé.

  // On peut choisir d'appeler un autre constructeur si on le désire.

  // En C++, il est TRES important d'initialiser toutes les propriétés
  ip = "192.168.1.100";
}

std::string IPProvider::GetIP()
{
  return ip;
}