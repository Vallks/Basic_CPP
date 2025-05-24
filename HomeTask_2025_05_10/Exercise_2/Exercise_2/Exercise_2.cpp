#include <iostream>
#include <algorithm>
using namespace std;

int myFunk(int a, int b) {
    if (a > b) {
        std::swap(a, b);
    }
    int sum = 0;
    for (int i = a + 1; i < b; ++i) {
        sum += i;
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int x, y, res;
    cout << "Введите 2 числа :";
    cin >> x >> y;
    res = myFunk(x, y);
    cout << "Результат " << res;
    return 0;
}

