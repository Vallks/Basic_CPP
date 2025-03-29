#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    
    int a;
    
    std::cout << "Введите число: ";

    cin >> a;

    for (int i = 1; i < 10; i++)
    {
        cout << a << " * " << i << " = " << a * i << endl;
    }

    return 0;
}

