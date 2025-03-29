#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    cout << "Введите начальное число :";
    int a,sum=0;

    cin >> a;
    cout << endl;

    if (a < 0 || a > 500)
    {
        cout << "Нерпавильный ввод!";
        return 0;
    }

    for (int i = a; i <= 500; i++)
    {
        sum += i;
    }

    cout << "Результат :" << sum;

    return 0;
}
