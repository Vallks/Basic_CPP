#include <iostream>
#include <iomanip>

int main()
{
	setlocale(LC_ALL, "RU");

	const int SECONDS_WORK_DAY = 3600*8;
	int seconds_in, hours, minutes, seconds, seconds_before_raschet;

	std::cout << "Введите количество секунд: ";

	std::cin >> seconds_in;

	seconds_in = abs(seconds_in % SECONDS_WORK_DAY); //если отрицательное или больше чем рабочий день то приведем к нормальному виду
	seconds_before_raschet = SECONDS_WORK_DAY - seconds_in;

	hours = seconds_before_raschet / 3600;
	minutes = seconds_before_raschet % 3600 / 60;
	seconds = seconds_before_raschet % 60;

	std::cout << "До конца рабочего дня осталось " << std::setfill('0')	<< std::setw(2) << hours 
				<< ":" << std::setfill('0')	<< std::setw(2) << minutes 
				<< ":" << std::setfill('0') << std::setw(2) << seconds << std::endl; //манипуляторы для красивого вывода 0 значений

	return 0;
}