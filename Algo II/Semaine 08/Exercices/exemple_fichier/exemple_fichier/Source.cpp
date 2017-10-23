#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	{
		ofstream oFich("toto.txt");

		for (int i = 1; i < 10; ++i)
			oFich << i << " " << "a " << i + 10  << endl;
	}
	
	{
		ifstream iFich("toto.txt");
		string line;
		
		while (getline(iFich, line))
		{
			stringstream l(line);
			int elem1, elem2;
			string junk;
			
			l >> elem1 >> junk >> elem2;

			cout << elem1 << " " << elem2 << endl;
		}
	}
	return 0;
}