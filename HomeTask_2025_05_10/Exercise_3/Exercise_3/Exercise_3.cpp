#include<iostream>
#include <algorithm>
using namespace std;

void myFunk(int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        int sum = 1;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
                sum = sum + j;

        }
        if (sum == i)
            cout << i << "\t";
    }
}

int main()
{
    int left, right;
    setlocale(LC_ALL, "RU");
    cout << "Введите левую границу ";
    cin >> left;
    cout << "Введите правую границу ";
    cin >> right;
    if (left > right)
        swap(left, right);
    cout << "Результат:";
    myFunk(left, right);
    return 0;
}