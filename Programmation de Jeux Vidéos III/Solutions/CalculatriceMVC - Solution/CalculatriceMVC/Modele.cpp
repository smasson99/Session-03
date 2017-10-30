#include "Modele.h"

using namespace MVC;

Modele::Modele()
{

}

double Modele::calcul(double nombre1, double nombre2, char operateur)
{
	switch (operateur)
	{
	case '+':
		return nombre1 + nombre2;
	case '-':
		return nombre1 - nombre2;
	case '*':
		return nombre1 * nombre2;	
	case '/':
		return nombre1 / nombre2;
	}
	return 0.0;
}



