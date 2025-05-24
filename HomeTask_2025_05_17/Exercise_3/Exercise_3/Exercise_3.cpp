#include <iostream>

using namespace std;

int binaryToDecimal(int x) {
    int y = 0;    
    int a = 1;    

    while (x > 0) {
        int d = x % 10; 

        if (d != 0 && d != 1) {
            cout << "Ошибка: введено не двоичное число!" << endl;
            return -1;
        }

        y += d * a;
        a *= 2;                   
        x /= 10;             
    }

    return y;
}

int main() {
    setlocale(LC_ALL, "RU");
    int x;
    cout << "Введите двоичное число: ";
    cin >> x;

    int y = binaryToDecimal(x);
    if (y != -1) {
        cout << "Десятичное представление: " << y << endl;
    }
  
    return 0;
}