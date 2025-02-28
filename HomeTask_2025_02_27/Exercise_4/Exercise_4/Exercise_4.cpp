#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

	double dist, time;
	int min, sec;
	const double KOEF = 3.6; // через константу для примера

	cout << "Вычисление скорости бега: " << endl;
	cout << "Введите длину дистанции: ";
	cin >> dist;
	
	cout << "Введите время(мин.сек): ";
	cin >> time;

	min = time;
	sec = (time - min) * 100;

	if (sec > 59 || sec < -59) //проверять не стал на отрицательное в случае отрицательной дистанции и отрицательного времени считаю что бежали в другу сторону ну или задом на перед)
	{
		cout << "У вас какое-то странное количество секунд!";
		return 1;
	}

	time = min * 60 + sec;

	cout << "Дистанция " << dist << endl;
	cout << "Время " << min << " мин " << sec << " сек = " << time << " сек" << endl;
	cout << "Вы бежали со скоростью " <<  fixed << setprecision(2) << abs(dist / time * KOEF) << " км/ч"; //манипуляторы для вывода как в примере  модуль для отрицательных значений.

	return 0;

}
