#include <vector>

// Mettre apres les autres includes
#include <vld.h>


void main()
{
	std::vector<int*> v1;

	// Allocation de 5 pointeur sur des entiers
	for (unsigned int i = 0; i < 5; i++)
	{
		int * nombre = new int(i);
		v1.push_back(nombre);
	}

	// Libration de seulement 2 pointeurs ! 
	for (unsigned int i = 0; i < 2; i++)
	{
		delete v1[i];
	}
	system("pause");

	// 3 pointeurs n'ont pas été libérés ! 
}

