#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	enum otvet { pizza = 1, katofel = 2, sprite = 3, cola = 4, vyhod = 5 };
    unsigned colKlient = 0, sum = 0, poz, col, pizzaCost = 5, katofelCost = 4, spriteCost = 3, colaCost = 2;
	cout << "На сколько персон заказ? ";
	cin >> colKlient;

	for (size_t i = 0; i < colKlient; i++)
	{
		do
		{
			cout << "Выберите товар:" << endl;
			cout << "1 - Пицца" << endl;
			cout << "2 - картофель фри" << endl;
			cout << "3 - спрайт" << endl;
			cout << "4 - кола" << endl;
			cout << "5 - выход" << endl;
			cin >> poz;
			switch (poz)
			{
			case pizza:
					cout << "Введите количество ";
					cin >> col;
					sum += col * pizzaCost;
					break;
			case katofel:
					cout << "Введите количество ";
					cin >> col;
					sum += col * katofelCost;
					break;
			case sprite:
				cout << "Введите количество ";
				cin >> col;
				sum += col * spriteCost;
				break;
			case cola:
				cout << "Введите количество ";
				cin >> col;
				sum += col * colaCost;
				break;
			case vyhod:
				break;
			default:
				cout << "Неверный ввод" << endl;
				break;
			}


		} while (poz != 5);
	}

	cout << "Сумма вшего заказа - " << sum;
	return 0;
}
