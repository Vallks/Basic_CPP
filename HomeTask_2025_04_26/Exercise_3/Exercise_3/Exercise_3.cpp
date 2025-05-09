#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

int main()
{
	const int size = 5;
	const int size2 = 10;
	int sum = 0;
	srand(time(NULL));

	int ar[size][size2];
	int arr2[size][size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			ar[i][j] = rand() % 51;
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr2[i][j] = ar[i][2 * j] + ar[i][2 * j + 1];
		}
	}

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}