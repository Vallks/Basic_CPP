#include <iostream>
#include <cstring>
using namespace std;



void myFunk(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '.')
		{
			str[i] = '!';
		}
	}
	return;
}

int main()
{
	setlocale(LC_ALL, "RU");

	const int SIZE = 256;
	char str[SIZE];
	int indx;

	cout << "Введите строку: ";
	cin.getline(str, SIZE);

	myFunk(str);

	cout << str;

	return 0;
}
