#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	const int month = 12;
    int ar[month];
	int imin, imax, max, min, iminres, imaxres;

	for (size_t i = 0; i < month; i++)
	{
		cout << "Введите значение прибыли за месяц " << i + 1 << " ";
		cin >> ar[i];
	}

	cout << "Введите нижнюю границу диапазона: ";
	cin >> imin;

	cout << "Введите верхнюю границу диапазона: ";
	cin >> imax;

	if (imin < 1 || imin > month || imax < 1 || imax > month) //номер не индекс
	{
		cout << "Неверрный диапазон";
		return 1;
	}

	if (imin > imax) // на случай если введут ерунду
	{
		int tmp = imin;
		imin = imax;
		imax = tmp;
	}

	min = ar[imin];
	max = ar[imin];
	iminres = imin;
	imaxres = imin;

	for (size_t i = imin - 1; i < imax; i++)
	{
		if (ar[i] < min)
		{
			iminres = i;
			min = ar[i];
		}

		if (ar[i] > max)
		{
			imaxres = i;
			max = ar[i];
		}
	}

	cout << "Максимальная прибыль в " << imaxres + 1 << " минимальная в " << iminres + 1;
	return 0;
}
