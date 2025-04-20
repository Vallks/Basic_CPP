#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	const int size = 10;
	int min, max;
	srand(time(NULL)); 
	int ar[size];

	for (size_t i = 0; i < size; i++)
	{
		ar[i] = rand();
		cout << ar[i] << " ";
	}

	cout << endl;

	min = ar[0];
	max = ar[0];

	for (size_t i = 0; i < size; i++)
	{
		if (ar[i] > max)
		{
			max = ar[i];
		}
		if (ar[i] < min)
		{
			min = ar[i];
		}
	}

	cout << "min " << min << " max " << max;
	return 0;
}

