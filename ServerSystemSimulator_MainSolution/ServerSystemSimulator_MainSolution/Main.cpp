#include <iostream>
using namespace std;

int main()
{
	cout << "Hola mundo" << endl;
	string palabra = "";
	for (size_t i = 0; i < 5; i++)
	{
		palabra = palabra + "*";
	}

	cout << palabra.c_str();

	cin.get();
	return 0;
}