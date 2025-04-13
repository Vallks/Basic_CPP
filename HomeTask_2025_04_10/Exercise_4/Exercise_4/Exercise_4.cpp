#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	double sumItog = 0, zp;

	for (size_t i = 1; i < 13 ; i++)
	{
		double sum = 0;
		for (size_t j = 4; j < 7; j++)
		{
			cout << "Введите зарплату сотрудника номер " << i << " за месяц " << j << " ";
			cin >> zp;

			sum += zp;
		}
		cout << "Зарплата сотрудника номер " << i << " за квартал  = " << sum << endl;
		sumItog += sum;
	}
	cout << "Итог " << sumItog;

	return 0;
}

