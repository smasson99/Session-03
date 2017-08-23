#pragma once
// ou
#ifndef IP_PROVIDER_H_
#define IP_PROVIDER_H_

#include <string>
class IPProvider
{
// Attention! Pas besoin de plusieurs "public"
// Le dernier spécifié est celui qui prévaut 
// par la suite tant qu'un autre n'est pas spécifié
public:
  // Constructeur sans paramètre
  IPProvider();
  // Méthode "standard"
  std::string GetIP();

private:
  std::string ip;
};

#endif // IP_PROVIDER_H_
