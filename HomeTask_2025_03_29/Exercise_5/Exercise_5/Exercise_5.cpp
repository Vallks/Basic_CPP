#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int num, sum = 0, tmp;

    cout << "Введите целое число: ";

    cin >> num;

    tmp = abs(num);  // для отрицательных
     
    while (tmp > 0)
    {
        sum += tmp % 10;
        tmp /= 10;
    }
  
    if (sum * sum * sum == num * num)
    {
        cout << "Ровнятеся!";
    }
    else
    {
        cout << "Не ровнятеся!";
    }

    return 0;
}
