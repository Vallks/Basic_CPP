#include <iostream>
#include <stdlib.h>
#include<time.h>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	const int size = 3;
	int sum = 0;
	srand(time(NULL));

	int ar[size][size];
	int arrSum[size];

	for (int i = 0; i < size; i++)
	{
		sum = 0;

		for (int j = 0; j < size; j++)
		{
			ar[i][j] = rand() % 10;
			cout << setw(2) << ar[i][j] << " ";
			sum += ar[i][j];
		}
		cout << "|" << " " << sum;
		cout << endl;
	}

	int len;
	len = 3 * size + 4;

	for (int i = 0; i < len; i++)
	{
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		sum = 0;
		for (int j = 0; j < size; j++)
		{
			sum += ar[j][i];
		}
		arrSum[i] = sum;
	}

	sum = 0;
	for (int i = 0; i < size; i++)
	{
		cout << setw(2) << arrSum[i] << " ";
		sum += arrSum[i];
	}
	cout << "|" << " " << sum;
	return 0;
}


