#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int num1, num2, tmp;

    cout << "Введите 2 целых числа через пробел: ";

    cin >> num1 >> num2;

    num1 = abs(num1);  // для отрицательных
    num2 = abs(num2);
    tmp = (num1 < num2) ? num1 : num2;

    for (int i = 1; i <= tmp; i++)  // а тут проверяем на само себя к примеру 5 и 20 20 делится на 5 без остатка
    {
        if ((num1 % i == 0) && (num2 % i == 0))
        {
            cout << i << " ";
        }
    }

    return 0;
}
