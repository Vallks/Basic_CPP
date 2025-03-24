#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int x, c1, c2, c3, c4, c5, c6;
	
	cout << "Введите шестизначиное число!" << endl;
	cin >> x;
	
	if (x < 100000 || x>999999) {
		cout << "Неверный формат ввода!";
		return 1;
	}
	
	c6 = x % 10;
	x /= 10;
	c5 = x % 10;
	x /= 10;
	c4 = x % 10;
	x /= 10;
	c3 = x % 10;
	x /= 10;
	c2 = x % 10;
	c1 = x / 10;
	
	if (c1 + c2 + c3 == c4 + c5 + c6) {
		cout << "Счастливое число!";
	}
	else {
		cout << "Не счастливое чилсо!";
	}
	
	return 0;
}


