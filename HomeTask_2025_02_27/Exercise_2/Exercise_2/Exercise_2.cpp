#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");

    double sum;
    int dollar, cent;

    cout << " Введите сумму: ";
    cin >> sum;

    dollar = sum;
    cent = abs((sum - dollar) * 100); //тут тип int нам на руку, отбросим лишние знаки в дробной части. А модуль для красивого вывода числа.

    cout << dollar << " долларов " << cent << " центов ";
    
    return 0;
}
