#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	const int size = 10;
	srand(time(NULL));
	int ar[size];

	for (int i = 0; i < size; i++)
	{
		ar[i] = rand();
		cout << ar[i] << " ";
	}

	cout << endl;

    int swp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        swp = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                swap(ar[j], ar[j + 1]);
                swp++;
            }
        }
        if (swp == 0)
        {
           break;
        }
    }

    for (int i = 0; i < size; i++)
    {
       cout << ar[i] << " ";
    }

	return 0;
}
