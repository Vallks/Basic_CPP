#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void initMas(int ar[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		ar[i] = rand();
	}
}

void printMas(int ar[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
}

int serchZnc(int ar[], int size, int znc)
{
	for (int i = 0; i < size; i++)
	{
		if (ar[i] == znc)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "RU");

	const int size = 10;
	srand(time(NULL));
	int ar[size];
	int znc;
	
	initMas(ar, size);
	printMas(ar, size);

	cout << endl << "Введите значение для поиска ";
	cin >> znc;
	
	int res = serchZnc(ar, size, znc);
	if (res == -1)
	{
		cout << "Не найдено!";
	}
	else
	{
		cout << "Индекс = " << res;
	}
	return 0;
}