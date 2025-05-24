#include <iostream>
using namespace std;

int myPow(int, int);

int main()
{
    setlocale(LC_ALL, "RU");
    unsigned int x, y, res;
    cout << "Введите число и степень :";
    cin >> x >> y;
    res = myPow(x, y);
    cout << x << " в степени " << y << " равно " << res;
    return 0;
}

int myPow(int x, int y)
{
    int res = 1;
    for (size_t i = 1; i <= y ; i++)
    {
       res *= x;
    }
    return res;
}

