#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    
    int a, b;

    long long res = 1;

    cout << "Введите 2 числа через пробел :";
    cin >> a >> b;

    if (b < 0)
    {
        cout << "Расчет только положительных степеней!";
        return 0;
    }

    for (int i = 0; i < b; i++)
    {
        res *= a;
    }

    cout << a << " в степени " << b << " = " << res;

    return 0;
}

