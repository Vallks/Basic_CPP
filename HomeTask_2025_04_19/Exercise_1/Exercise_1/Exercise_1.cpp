#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	
	int chisl;
	cout << "Введите число :";
	cin >> chisl;

	const int SIZE = 3;
	int arr[SIZE][SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			arr[i][j] = chisl;
			cout << arr[i][j] << " ";
			chisl *= 2;
		}
		cout << endl;
	}

	return 0;
}
