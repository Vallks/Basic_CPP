#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	for (size_t i = 2; i <=100 ; i++)
	{
		int count = 0;

		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0)
			{
				count++;
			}

			if (count > 1)
			{
				break;
			}
		}

		if (count == 1)
		{
			cout << i << " ";
		}
	}

	return 0;
}

