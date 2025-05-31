#include <iostream>

using namespace std;

int evklid(int a, int b) 
{
    if (b == 0) {
        return a;
    }
    return evklid(b, a % b);
}

int main() 
{
    setlocale(LC_ALL, "RU");
    int num1, num2;
    cout << "Введите два числа: ";
    cin >> num1 >> num2;
    cout << evklid(abs(num1), abs(num2)) << endl;

    return 0;
}
