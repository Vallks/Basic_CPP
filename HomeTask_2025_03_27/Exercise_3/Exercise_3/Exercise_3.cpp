#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int sum = 0;

	for (int i = 1; i <= 1000; i++)
	{
		sum += i;
	}

	cout << "Результат " << (double)sum / 1000;

	return 0;
}

