#include <iostream>

using namespace std;

double getSal(double prod) // лень писать 3 раза ифа
{
    if (prod < 500)
    {
        return 200 + prod * 0.03;
    }
    else if(prod < 1000)
    {
        return 200 + prod * 0.05;
    }
    else
    {
        return 200 + prod * 0.08;
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");

    double prod1, prod2, prod3, sal1, sal2, sal3;

    cout << "Введите продажи менеджеров через пробел: ";
    cin >> prod1 >> prod2 >> prod3;

    if (prod1 < 0 || prod2 < 0 || prod3 < 0)
    {
        cout << "Не правильно ввели продажи!";
        return 1;
    }
    
    sal1 = getSal(prod1);
    sal2 = getSal(prod2);
    sal3 = getSal(prod3);

    if (prod1 > prod2 && prod1 > prod3)
    {
        sal1 += 200;
    }
    if (prod2 > prod1 && prod2 > prod3)
    {
        sal2 += 200;
    }
    if (prod3 > prod2 && prod3 > prod1)
    {
        sal3 += 200;
    }
    // если у кого-то равны то ни кто не получит
    
    cout << "Зарплата менеджера 1 = " << sal1 << endl
        << "Зарплата менеджера 2 = " << sal2 << endl
        << "Зарплата менеджера 3 = " << sal3 << endl;

    return 0;
}
