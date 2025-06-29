#include <iostream>
#include <cstring>
using namespace std;



void myFunk(char* str, char sym)
{
	int res = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == sym)
		{
			res++;
		}
	}

	cout << res << " символов в строке";
	return;
}

int main()
{
	setlocale(LC_ALL, "RU");

	const int SIZE = 256;
	char str[SIZE];
	char sym;

	cout << "Введите строку: ";
	cin.getline(str, SIZE);

	cout << "Введите мивол для подсчета: ";
	cin >> sym;

	myFunk(str, sym);

	return 0;
}