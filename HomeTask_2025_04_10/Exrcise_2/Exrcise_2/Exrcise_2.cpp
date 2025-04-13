#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	int size;

	cout << "Введите размер: ";

	cin >> size;

	if (size % 2 == 0 || size < 0)
	{
		cout << "Неправильный размер";
		return 1;
	}

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == j || i == size / 2  || j == size / 2  || i == size - j - 1)
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}
