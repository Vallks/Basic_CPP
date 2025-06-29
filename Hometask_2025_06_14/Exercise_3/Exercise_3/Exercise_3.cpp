#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 256;

void myFunk(char* str, int indx, char sym)
{
	if (indx < 0 || indx > strlen(str))
	{
		cout << "Неправильный индекс";
		return;
	}
	
	for (int i = strlen(str); i >= indx; i--) {
		str[i + 1] = str[i];
	}

	str[indx] = sym;
	return;
}

int main()
{
	setlocale(LC_ALL, "RU");

	char str[SIZE];
	int indx;
	char sym;

	cout << "Введите строку: ";
	cin.getline(str, SIZE);

	cout << "Введите индекс для добавления: ";
	cin >> indx;

	cout << "Введите символ: ";
	cin >> sym;

	myFunk(str, indx, sym);

	cout << str;

	return 0;
}
