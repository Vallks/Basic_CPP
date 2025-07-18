#include <iostream>
#include <string>
using namespace std;

enum class Transmission
{
    MANUAL,
    AUTOMATIC
};

struct Car
{
    double length;
    double clearance;
    double engineVolume;
    int enginePower;
    double wheelDiameter;
    string color;
    Transmission transmission;
};

void setCar(Car* car)
{
    cout << "Введите характеристики автомобиля:\n";

    cout << "Длина (м): "; cin >> car->length;
    cout << "Клиренс (м): "; cin >> car->clearance;
    cout << "Объем двигателя (л): "; cin >> car->engineVolume;
    cout << "Мощность двигателя (л.с.): "; cin >> car->enginePower;
    cout << "Диаметр колес (дюймов): "; cin >> car->wheelDiameter;

    cout << "Цвет: ";
    cin.ignore();
    getline(cin, car->color);

    cout << "Тип коробки передач (0-Механическая, 1-Автоматическая): ";
    int trans;
    cin >> trans;
    if (trans == 1)
    {
        car->transmission = Transmission::AUTOMATIC;
    }
    else
    {
        car->transmission = Transmission::MANUAL; // пренебрегаем неправильными значениями
    }
    cout << endl << endl;
}

void printCar(Car& car)
{
    cout << "Характеристики автомобиля:\n";
    cout << "Длина: " << car.length << " м\n";
    cout << "Клиренс: " << car.clearance << " м\n";
    cout << "Объем двигателя: " << car.engineVolume << " л\n";
    cout << "Мощность двигателя: " << car.enginePower << " л.с.\n";
    cout << "Диаметр колес: " << car.wheelDiameter << " дюймов\n";
    cout << "Цвет: " << car.color << "\n";
    cout << "Коробка передач: ";
    switch (car.transmission) {
    case Transmission::MANUAL: cout << "Механическая"; break;
    case Transmission::AUTOMATIC: cout << "Автоматическая"; break;
    }
    cout << "\n\n";
}

void findCars(Car* cars, int count, string& fieldName, string& value)
{
    bool foundAny = false;
    for (int i = 0; i < count; i++)
    {
        bool found = false;
        if (fieldName == "length" && cars[i].length == stod(value))
        {
            found = true;
        }
        else if (fieldName == "clearance" && cars[i].clearance == stod(value))
        {
            found = true;
        }
        else if (fieldName == "engineVolume" && cars[i].engineVolume == stod(value))
        {
            found = true;
        }
        else if (fieldName == "enginePower" && cars[i].enginePower == stoi(value))
        {
            found = true;
        }
        else if (fieldName == "wheelDiameter" && cars[i].wheelDiameter == stod(value))
        {
            found = true;
        }
        else if (fieldName == "color" && cars[i].color == value)
        {
            found = true;
        }
        else if (fieldName == "transmission")
        {
            Transmission tmp;
            if (value == "0") { tmp = Transmission::MANUAL; }
            else if (value == "1") { tmp = Transmission::AUTOMATIC; }
            else { continue; } // пропускаем неверные значения

            if (cars[i].transmission == tmp) {
                found = true;
            }
        }

        if (found)
        {
            printCar(cars[i]);
            foundAny = true;
        }
    }

    if (!foundAny)
    {
        cout << "Автомобили с указанными характеристиками не найдены.\n";
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    const int CAR_COUNT = 5;
    Car cars[CAR_COUNT];
    string name, value;

    for (int i = 0; i < CAR_COUNT; i++)
    {
        setCar(&cars[i]);
    }

    cin.ignore();
    cout << "Введите имя характеристики (length,clearance,engineVolume,enginePower,wheelDiameter,color,transmission): " << endl;
    getline(cin, name);

    cout << "Введите значение характеристики (для transmission 0 или 1): " << endl;
    getline(cin, value);

    findCars(cars, CAR_COUNT, name, value);
    return 0;
}