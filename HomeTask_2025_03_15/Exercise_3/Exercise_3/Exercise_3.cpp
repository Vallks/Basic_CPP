#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	
	int variant, strok, opozd;
	double dohod, shtraf, oplataStrok;
	const double cenaStroki = 50. / 100;

	
	cout << "Введите вариант: \n1 - Определить количество строк кода\n2 - Определить количество опозданий\n3 - Определить доход\n";

	cin >> variant ;

	switch (variant)
	{
	case 1:
		
		cout << "\nВведите желаемый доход: ";
		cin >> dohod;

		cout << "\nВведите количество опозданий: ";
		cin >> opozd;
		
		shtraf = opozd / 3 * 20; //тут все равно целое будет
		strok = ceil((dohod + shtraf) / cenaStroki); // округлил в большую
		
		cout << "Нужно напечатать " << strok << " строк.";

		break;
	case 2:
		
		cout << "\nВведите количество строк: ";
		cin >> strok;

		cout << "\nВведите желаемый доход: ";
		cin >> dohod;

		oplataStrok = strok * cenaStroki;

		if (oplataStrok < dohod)
		{
			cout << "Вам нельзя опаздывать! И работайте побольше!";
			return 0;
		}
		
		shtraf = oplataStrok - dohod;
		opozd = shtraf / 20 * 3;
		if (opozd % 3 == 0)
		{
			opozd += 2;
		}
		else if ((opozd + 2) % 3 == 0)
		{
			opozd++;
		}
		else
		{
			cout << opozd;
		}

		cout << "Вы можете опаздать " << opozd << " раз.";

		break;
	case 3:
		
		cout << "\nВведите количество строк: ";
		cin >> strok;

		cout << "\nВведите количество опозданий: ";
		cin >> opozd;

		shtraf = opozd / 3 * 20;
		oplataStrok = strok * cenaStroki;

		if (shtraf >= oplataStrok)
		{
			cout << "Вам не заплатят!";
			break;
		}
		cout << "Вам заплатят " << oplataStrok - shtraf << "$";
		break;
	default:
		cout << "Какой-то странный вариант";
		break;
	}

	return 0;
}