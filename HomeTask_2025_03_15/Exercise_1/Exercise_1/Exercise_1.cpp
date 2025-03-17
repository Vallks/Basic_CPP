#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU"); //Не работает на ввод поэтому без проблем ориентируемся на латинскую аски
	
	char sym;

	cin >> sym;

	if (sym >= 65 && sym <= 90 || sym >= 97 && sym <= 122)
	{
		cout << "Буква";
	}
	else if (sym >= 48 && sym <= 57)
	{
		cout << "Цифра";
	}
	else if (sym == 33 || sym >= 44 && sym <= 46 || sym == 58 || sym == 59 || sym == 63)
	{
		cout << "Знак препинания";
	}
	else
	{
		cout << "Что-то другое";
	}

	return 0;
}

