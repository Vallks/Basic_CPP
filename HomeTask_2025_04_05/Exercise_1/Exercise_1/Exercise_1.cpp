#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	
	enum variant { a = 1, b = 2, c = 3, d = 4 };
	int userVyb = 0, col = 0, sum = 0, tmp, chislo;
    double srArif = 0;
	cout << "Введите число: ";
	cin >> chislo;

	do
	{
		cout << "Выберите вариант:" << endl;
		cout << "1 - количество цифр" << endl;
		cout << "2 - сумма цифр и среднее арифметическое" << endl;
		cout << "3 - количество нулей" << endl;
		cout << "4 - выход" << endl;

		cin >> userVyb;

		switch (userVyb)
		{case a:
			col = 0;
			tmp = chislo;
			while ( tmp != 0 )
			{
				col++;
				tmp /= 10;
			}
			cout << "количество цифр - " << col << endl;
			break;
		case b:
			col = 0;
			sum = 0;
			srArif = 0;
			tmp = chislo;
			while ( tmp != 0 )
			{
				sum += tmp % 10;
				col++;
				tmp /= 10;
			}
			srArif = (double)sum / col;
			cout << "сумма цифр - " << sum << " среднее арифметическое " << srArif << endl;
			break;
		case c:
			col = 0;
			tmp = chislo;
			while ( tmp != 0 )
			{
				if ( tmp % 10 == 0 )
				{
					col++;
				}
				tmp /= 10;
			}
			cout << "количество нулей - " << col << endl;
			break;
		case d:
			return 0;
		default:
			cout << "Неправильный ввод";
			break;
		}

	} while ( userVyb != 5 );

	return 0;
}
