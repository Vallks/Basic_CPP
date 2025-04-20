#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	const int size = 10;
	int min = 0, max = 0, iminotr = -1, imaxotr = -1;
	double sumotr = 0, reschet = 1, resminmax = 1, sumotrind = 0;

	srand(time(NULL));
	double ar[size];
	for (size_t i = 0; i < size; i++)
	{
		int c = rand() % 21 - 10;
		int d = rand() % 100;
		ar[i] = c + (double)d/100;
		cout << ar[i] << " ";
		if (ar[min] > ar[i])
		{
			min = i;
		}
		if (ar[max] < ar[i])
		{
			max = i;
		}
		if (ar[i] < 0)
		{
			if (iminotr == -1)
			{
				iminotr = i;
			}
			imaxotr = i;
			sumotr += ar[i];
		}
		if ((i + 1) % 2 == 0)
		{
			reschet *= ar[i];
		}
	}

	cout << endl;

	if (iminotr != -1)
	{
		for (size_t i = iminotr; i <= imaxotr; i++)
		{
			sumotrind += ar[i];
		}
	}

	if (min > max) // на случай если индекс минимального больше индекса максимального
	{
		int tmp = min;
		min = max;
		max = tmp;
	}
	for (size_t i = min; i <= max; i++)
	{
		resminmax *= ar[i];
	}

	cout << "Сумма отрицательных чисел. " << sumotr << endl;
	cout << "Произведение элементов, находящихся между min и max элементами. " << resminmax << endl; //включая
	cout << "Произведение элементов с четными номерами " << reschet << endl;
	cout << "Сумму элементов, находящихся между первым и последним отрицательными элементами " << sumotrind << endl;

	return 0;
}

