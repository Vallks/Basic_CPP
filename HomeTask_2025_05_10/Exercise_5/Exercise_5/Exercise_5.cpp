#include <iostream>
using namespace std;

bool isLuckyNumber(int number) {
    if (number < 100000 || number > 999999) {
        return false;
    }

    int digit1 = number / 100000;         
    int digit2 = (number / 10000) % 10;   
    int digit3 = (number / 1000) % 10;    
    int digit4 = (number / 100) % 10;      
    int digit5 = (number / 10) % 10;       
    int digit6 = number % 10;              

    int resLeft = digit1 + digit2 + digit3;
    int resRight = digit4 + digit5 + digit6;

    return resLeft == resRight;
}

int main() {
    setlocale(LC_ALL, "RU");
    int number;
    cout << "Введите шестизначное число: ";
    cin >> number;

    if (isLuckyNumber(number)) {
        cout << number << " - это счастливое число!" << endl;
    }
    else {
        cout << number << " - это обычное число." << endl;
    }

    return 0;
}