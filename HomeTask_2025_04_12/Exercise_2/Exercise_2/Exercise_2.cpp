#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	const int size = 20;
	int imin, imax, znch, sum = 0;
	srand(time(NULL));
	int ar[size];

	for (size_t i = 0; i < size; i++)
	{
		ar[i] = rand();
		cout << ar[i] << " ";
	}
	cout << endl;

	cout << "Введите нижнюю границу диапазона: ";
	cin >> imin;

	cout << "Введите верхнюю границу диапазона: ";
	cin >> imax;

	cout << "Введите значение для отбора: ";
	cin >> znch;

	if (imin < 1 || imin > size || imax < 1 || imax > size) //номер не индекс
	{
		cout << "Неверрный диапазон";
		return 1;
	}

	if (imin > imax) // на случай если введут ерунду
	{
		int tmp = imin;
		imin = imax;
		imax = tmp;
	}

	for (size_t i = imin-1; i < imax -1 ; i++)
	{
		if (ar[i] < znch)
		{
			sum += ar[i];
		}
	}
	cout << "Результат " << sum;
	return 0;
}

