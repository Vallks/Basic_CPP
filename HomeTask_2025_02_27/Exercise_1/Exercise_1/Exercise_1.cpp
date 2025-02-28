#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");

    int seconds, minutes, hours;
    minutes = hours = 0;

    cout << "Введите количество секунд : ";
    cin >> seconds;

    hours = seconds / 3600;

    minutes = seconds % 3600 / 60;

    seconds = seconds % 60;

    cout << ((hours < 0)?"Минус ":"") << abs(hours) << " часов "  << abs(minutes) << " минут " << abs(seconds) << " секунд ";
    //Тренарник чтоб было наглядно видно когда минусовое значение, а модуль для красивого вывода. Жаль не знаю как склонения по падежам сделать.

    return 0;
}

