#include <iostream>
#include <cstring>
using namespace std;



void myFunk(char* str, char sym)
{
	int j = 0, i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sym)
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

int main()
{
	setlocale(LC_ALL, "RU");

	const int SIZE = 256;
	char str[SIZE];
	char sym;

	cout << "Введите строку: ";
	cin.getline(str, SIZE);

	cout << "Введите мивол для удаления: ";
	cin >> sym;

	myFunk(str, sym);

	cout << str;

	return 0;
}