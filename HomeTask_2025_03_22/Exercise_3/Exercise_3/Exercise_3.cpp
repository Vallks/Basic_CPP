#include <iostream>
#include <algorithm>

using namespace std;

enum {countAr = 7}; // пример использования перечисления без объявления вместо define

int getMax(int* ar)
{
	int max = ar[0];

	for (int i = 1; i < countAr; i++)
	{
		if (ar[i] > max)
		{
			max = ar[i];
		}
	}

	return max;
}

int main()
{
	setlocale(LC_ALL, "RU");

	cout << "Введите 7 числел через пробел" << endl;

	int* ar = new int[countAr];
	int max;

	for (int i = 0; i < countAr; i++)
	{
		cin >> ar[i];
	}

	cout << getMax(ar) << " перебором" << endl; // можно было бы прям тут сделать, и еще и for (int x : ar) перебором, но не стал тк тренируюсь в указатели 

	int* maxPtr = max_element(ar, ar + countAr);

	cout << *maxPtr << " используя STL" << endl; //взял функцию из algorithm просто для тренировки

	return 0;
}

