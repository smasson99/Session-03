#include <vld.h>
#include "FabriqueMcDo.h"
#include <iostream>

using namespace Fabrique;

void main()
{
	setlocale(LC_ALL, "");

	//Imaginez que le snack est un sac.  On ouvre le sac et on découvre ce qu'on a.
	SnackMcDo* sac1 = FabriqueMcDo::createSnackMcDo(FabriqueMcDo::Burger);
	SnackMcDo* sac2 = FabriqueMcDo::createSnackMcDo(FabriqueMcDo::Gravy);
	SnackMcDo* sac3 = FabriqueMcDo::createSnackMcDo(FabriqueMcDo::Dessert);

	std::cout << sac1->getSnack() << std::endl;
	std::cout << sac2->getSnack() << std::endl;
	std::cout << sac3->getSnack() << std::endl;

	delete sac1;
	delete sac2;
	delete sac3;

	system("pause");
}