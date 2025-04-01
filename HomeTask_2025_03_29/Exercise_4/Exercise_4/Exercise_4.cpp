#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    
    int num;

    cout << "Введите целое число: ";

    cin >> num;

    num = abs(num); // отрицательное преобразуем чтоб фор нормально работал

    for (int i = 1; i < num; i++)
    {
        if ((num % (i * i) == 0) && (num % (i * i * i) != 0))
        {
            cout << i << " ";
        }
    }

    return 0;
}


