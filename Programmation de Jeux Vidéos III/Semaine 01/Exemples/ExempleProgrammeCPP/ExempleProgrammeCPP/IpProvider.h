#pragma once
// ou
#ifndef IP_PROVIDER_H_
#define IP_PROVIDER_H_

#include <string>
class IPProvider
{
// Attention! Pas besoin de plusieurs "public"
// Le dernier sp�cifi� est celui qui pr�vaut 
// par la suite tant qu'un autre n'est pas sp�cifi�
public:
  // Constructeur sans param�tre
  IPProvider();
  // M�thode "standard"
  std::string GetIP();

private:
  std::string ip;
};

#endif // IP_PROVIDER_H_
