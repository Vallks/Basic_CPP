// переделал наш пример на функции
#include <iostream> 
#include <stdlib.h>
#include <time.h>

using namespace std;

void printArr(int array[][10], int size)
{
    cout << "Исходный массив" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << '\t';
        }
        cout << endl;
    }
}

void shiftLeft(int array[][10], int size, int sdvig)
{
   
    for (int i = 0; i < size; i++) {
        for (int s = 0; s < sdvig; s++) {
            int temp = array[i][0];
            for (int j = 0; j < size - 1; j++) {
                array[i][j] = array[i][j + 1];
            }
            array[i][size - 1] = temp;
        }
    }
}

void shiftRight(int array[][10], int size, int sdvig)
{
    for (int i = 0; i < size; i++) {
        for (int s = 0; s < sdvig; s++) {
            int temp = array[i][size - 1];
            for (int j = size - 1; j > 0; j--) {
                array[i][j] = array[i][j - 1];
            }
            array[i][0] = temp;
        }
    }
}

void shiftDown(int array[][10], int size, int sdvig)
{
    for (int j = 0; j < size; j++) {
        for (int s = 0; s < sdvig; s++) {
            int temp = array[size - 1][j];
            for (int i = size - 1; i > 0; i--) {
                array[i][j] = array[i - 1][j];
            }
            array[0][j] = temp;
        }
    }
}

void shiftUp(int array[][10], int size, int sdvig)
{
     for (int j = 0; j < size; j++) {
        for (int s = 0; s < sdvig; s++) {
            int temp = array[0][j];
            for (int i = 0; i < size - 1; i++) {
                array[i][j] = array[i + 1][j];
            }
            array[size - 1][j] = temp;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    const int SIZE = 10;
    int sdvig, napr;
    int array[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            array[i][j] = rand() % 100;
        }
    }

    printArr(array, SIZE);

    while (true)
    {
        cout << "Укажите направление сдвига: 1 - влево, 2 - вправо, 3 - вверх, 4 - вниз ";
        cin >> napr;
        if (napr > 0 && napr < 5)
            break;
        else
            cout << "Некорректное значение, введите заново" << endl;
    }

    while (true)
    {
        cout << "Укажите количество сдвигов целым положительным числом больше нуля ";
        cin >> sdvig;
        if (sdvig > 0)
            break;
        else
            cout << "Некорректное значение, введите заново" << endl;
    }
   
    sdvig %= SIZE;

    switch (napr) {
    case 1: shiftLeft(array, SIZE, sdvig);
        break;
    case 2: shiftRight(array, SIZE, sdvig);
        break;
    case 3: shiftUp(array, SIZE, sdvig);
        break;
    case 4: shiftDown(array, SIZE, sdvig);
        break;
    default: cout << "Неверное направление!\n";
    }

    printArr(array, SIZE);
  
    return 0;
}