#include <vld.h>
#include "UsineDeBerline.h"
//#include "UsineDePickUp.h"
//#include "UsineDeSportCar.h"
#include <iostream>

using namespace Fabrique;

void main()
{
	UsineDeVoiture* usine = new UsineDeBerline();  //UsineDeBerline : seul élément de sous-classe du lot.
	Voiture* v = usine->fabriquerVoiture();
	
	std::cout << v->getTypeVoiture() <<std::endl;
	
	delete  v;
	delete usine;
	
	system("pause");
}