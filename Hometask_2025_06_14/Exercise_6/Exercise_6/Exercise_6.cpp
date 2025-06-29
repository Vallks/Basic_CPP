#include <iostream>
#include <cstring>
using namespace std;



void myFunk(char* str)
{
	int resChisl = 0, resBukv = 0, resOther = 0;
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			resChisl++;
		}
		else if(isalpha(str[i]))
		{
			resBukv++;
		}
		else
		{
			resOther++;
		}
	}

	cout << resChisl << " цифр, " << resBukv << " букв, " << resOther << " других символов в троке.";
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

	myFunk(str);

	return 0;
}