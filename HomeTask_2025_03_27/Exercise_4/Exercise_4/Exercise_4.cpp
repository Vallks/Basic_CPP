#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    cout << "Введите начальное число :";
    int a;
    long long res = 1;

    cin >> a;
    cout << endl;

    if (a < 1 || a > 20)
    {
        cout << "Нерпавильный ввод!";
        return 0;
    }

    for (int i = a; i <= 20; i++)
    {
        res *= i;
    }

    cout << "Результат :" << res;

    return 0;
}
