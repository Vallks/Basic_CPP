#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    double pizza1 = 5.5, pizza2 = 6.5, pizza3 = 7.5, pizza4 = 8.5, pizzaCost = 0, drink1 = 0.5, drink2 = 1.5, drink3 = 2.5, drinkCost = 0;
    int pizzaInd, drinkInd, pizzaCount, pizzaFreeCount, drinkCount;

    cout << "Выберите пиццу и колчиство через пробел:\n"
        << "1 - Мартгарита $" << pizza1 << "\n"
        << "2 - Тропикана $" << pizza2 << "\n"
        << "3 - 4 сыра $" << pizza3 << "\n"
        << "4 - Пиперони $" << pizza4 << "\n";


    cin >> pizzaInd >> pizzaCount;

    if(pizzaInd < 1 || pizzaInd > 4)
    {
        cout << "Вы выбрали не тот товар.";
        return 1;
    }
    if (pizzaCount < 0)
    {
        cout << "Вы выбрали не правильное количество.";
        return 2;
    }

    cout << "Выберите напиток и колчиство через пробел:\n"
        << "1 - Кола $" << drink1 << "\n"
        << "2 - Фанта $" << drink2 << "\n"
        << "3 - Вятский квас $" << drink3 << "\n";

    cin >> drinkInd >> drinkCount;
   
    if (drinkInd < 1 || drinkInd > 3)
    {
        cout << "Вы выбрали не тот товар";
        return 3;
    }
    if (drinkCount < 0)
    {
        cout << "Вы выбрали не правильное количество.";
        return 4;
    }

    cout << "Ваш заказ\n";

    pizzaFreeCount = pizzaCount / 5;

    if (pizzaInd == 1)
    {
        pizzaCost = pizzaCount * pizza1 - pizzaFreeCount * pizza1;
        cout << "Мартгарита - " << pizzaCount << " - $" << pizza1 << endl;
    }
    else if (pizzaInd == 2)
    {
        pizzaCost = pizzaCount * pizza2 - pizzaFreeCount * pizza2;
        cout << "Тропикана - " << pizzaCount << " - $" << pizza2 << endl;
    }
    else if (pizzaInd == 3)
    {
        pizzaCost = pizzaCount * pizza3 - pizzaFreeCount * pizza3;
        cout << "4 сыра - " << pizzaCount << " - $" << pizza3 << endl;
    }
    else
    {
        pizzaCost = pizzaCount * pizza4 - pizzaFreeCount * pizza4;
        cout << "Пиперони - " << pizzaCount << " - $" << pizza4 << endl;
    }


    if (drinkInd == 1)
    {
        if (drinkCount > 3)
        {
            drinkCost = drink1 * drinkCount * 0.85;
        }
        else
        {
            drinkCost = drink1 * drinkCount;
        }
        cout << "Кола - " << drinkCount << " - $" << drink1 << endl;
    }
    else if (drinkInd == 2)
    {
        if (drinkCount > 3)
        {
            drinkCost = drink2 * drinkCount * 0.85;
        }
        else
        {
            drinkCost = drink2 * drinkCount;
        }
        cout << "Фанта - " << drinkCount << " - $" << drink2 << endl;
    }
    else
    {
        drinkCost = drink3 * drinkCount * 0.85; // Поскольку заранее знаем цену сразу применил скидку
        cout << "Вятский квас - " << drinkCount << " - $" << drink3 << endl;
    }

   
    cout << "Итого к оплате: " << ((pizzaCost + drinkCost) > 50.0?(pizzaCost + drinkCost)*0.8:(pizzaCost + drinkCost));

     return 0;
}

