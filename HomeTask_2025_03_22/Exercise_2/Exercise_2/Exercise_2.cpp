#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int x, c1, c2, c3, c4, itog;

	cout << "Введите четырезначное число!" << endl;
	cin >> x;

	if (x < 1000 || x>9999) {
		cout << "Неверный формат ввода!";
		return 1;
	}

	c4 = x % 10;
	x /= 10;
	c3 = x % 10;
	x /= 10;
	c2 = x % 10;
	c1 = x / 10;

	itog = c2 * 1000 + c1 * 100 + c4 * 10 + c3;
	
	cout << "Результат - " << itog;

	return 0;
}

