#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int num;

    cout << "Введите целое число: ";

    cin >> num;

    num = abs(num);  // для отрицательных

    for (int i = 1; i < num; i++) // считаем что само на себя не проверяем
    {
        if (num % i == 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}
