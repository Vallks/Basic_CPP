#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");

    int days;
    
    cout << "Введите количество дней :";
    cin >> days;

    if (days < 0) //Проверка чисто для тренировки, можно было бы сделать и через модуль чтоб красиво выводилось.
    {
        cout << "Введено отрицательное число!";
        return 1;
    }

    cout << "Недель " << days / 7 << " дней " << days % 7; // пример первой задачи без переменных

    return 0;
}


