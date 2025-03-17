#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int moyOperator, oreratorSobesednika, min;
    double costBee = 10.5, costTele = 7.5, costMts = 12.5;
    
    cout << "Выбирете своего оператора: \n1 - BeeLine\n2 - Tele2\n3 - MTS\n";

    cin >> moyOperator;

    if (moyOperator < 1 || moyOperator > 3)
    {
        cout << "Вы выбрали не правильный вариант\n";
        return 1;
    }

    cout << "Выбирете оператора собеседника: \n1 - BeeLine\n2 - Tele2\n3 - MTS\n";

    cin >> oreratorSobesednika;

    if (oreratorSobesednika < 1 || oreratorSobesednika > 3)
    {
        cout << "Вы выбрали не правильный вариант\n";
        return 2;
    }

    cout << "Введите количество минут\n";
    
    cin >> min;

    if(moyOperator == oreratorSobesednika)
    {
        cout << "Бесплатно внутри сети\n";
    }
    else if(moyOperator == 1)
    {
        cout << "Вы заплатите - " << costBee * min << " р.";
    }
    else if (moyOperator == 2)
    {
        cout << "Вы заплатите - " << costTele * min << " р.";;
    }
    else // можно не указывать условие все равно мы выше проверили правильность ввода
    {
        cout << "Вы заплатите - " << costMts * min << " р.";;
    }

    return 0;
    
}