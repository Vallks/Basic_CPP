#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");

    double vklad,procent,vyplata;
    cout << "Введите сумму вклада: ";
    cin >> vklad;
    cout << "Введите процент по вкладу: ";
    cin >> procent;
    cout << "Выплата в месяц " << fixed << setprecision(2) << vklad * procent / 100 / 12; // манипулятор для представления денежного типа

    return 0;
}
