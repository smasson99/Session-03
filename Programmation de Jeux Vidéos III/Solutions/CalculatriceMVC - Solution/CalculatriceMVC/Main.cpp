#include "Vue.h"
#include <iostream>
#include <time.h> 

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	MVC::Vue v;
	v.executer();

	system("pause");

	return 0;
}