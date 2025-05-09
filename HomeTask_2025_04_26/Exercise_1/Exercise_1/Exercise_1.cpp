#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	const int size = 3;
	int min, max;
	long sum = 0;
	double srArif;

	srand(time(NULL));

	int ar[size][size];
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			ar[i][j] = rand();
			cout << ar[i][j] << '\t';
		}
		cout << endl;
	}

	min = ar[0][0];
	max = ar[0][0];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			sum += ar[i][j];

			if (min > ar[i][j])
			{
				min = ar[i][j];
			}
			if (max < ar[i][j])
			{
				max = ar[i][j];
			}
		}
	}

	srArif = (double)sum / (size * size);

	cout << "Минимум " << min << endl;
	cout << "Максимум " << max << endl;
	cout << "Сумма " << sum << endl;
	cout << "Среднее арифметическое " << srArif << endl;

	return 0;
}

