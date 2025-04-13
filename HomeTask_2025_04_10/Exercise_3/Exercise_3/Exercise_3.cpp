#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	int time = 0;


	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			for (size_t k = 0; k < 10; k++)
			{
				if (i != j && i != k && j != k)
				{
					cout << i << j << k << endl;
					time += 3;//Считаем что на комбинации с повторяющимися цифрами не тратим время
				}
			}
		}
	}

	cout << "Время " << time << " секунд.";
	return 0;
}
