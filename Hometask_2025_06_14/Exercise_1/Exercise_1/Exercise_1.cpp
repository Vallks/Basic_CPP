#include <iostream>
#include <cstring>
using namespace std;



void myFunk(char* str, int indx)
{
	if (indx < 0 || indx > strlen(str))
	{
		cout << "Неправильный индекс";
		return;
	}

	for (int i = indx; str[i] != '\0';  i++)
	{
		str[i] = str[i + 1];
	}
}

int main()
{
	setlocale(LC_ALL, "RU");

	const int SIZE = 256;
	char str[SIZE];
	int indx;

	cout << "Введите строку: ";
	cin.getline(str, SIZE);

	cout << "Введите индекс для удаления символа: ";
	cin >> indx;

	myFunk(str, indx);

	cout << str;

	return 0;
}
