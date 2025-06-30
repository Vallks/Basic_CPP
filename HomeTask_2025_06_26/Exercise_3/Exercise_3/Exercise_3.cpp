#include <iostream>
#include <ctime>
using namespace std;

void printArray(int** arr, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

void shiftRows(int** arr, int rows, int cols, int direction, int shiftCount) {
    shiftCount %= rows;
    if (shiftCount < 0)
    {
        shiftCount += rows;
    }
    if (shiftCount == 0)
    {
        return;
    }

    int* temp = new int[cols];

    if (direction == 0) 
    {
        for (int s = 0; s < shiftCount; ++s) 
        {
            for (int j = 0; j < cols; j++)
            {
                temp[j] = arr[0][j];
            }

            for (int i = 0; i < rows - 1; i++)
            {
                for (int j = 0; j < cols; ++j)
                {
                    arr[i][j] = arr[i + 1][j];
                }
            }
            
            for (int j = 0; j < cols; j++)
            {
                arr[rows - 1][j] = temp[j];
            }
        }
    }
    else 
    {
        for (int s = 0; s < shiftCount; s++) 
        {
            for (int j = 0; j < cols; j++)
            {
                temp[j] = arr[rows - 1][j];
            }

            for (int i = rows - 1; i > 0; i--)
            {
                for (int j = 0; j < cols; j++)
                {
                    arr[i][j] = arr[i - 1][j];
                }
            }
            
            for (int j = 0; j < cols; j++)
            {
                arr[0][j] = temp[j];
            }
        }
    }
    delete[] temp;
}

void shiftColumns(int** arr, int rows, int cols, int direction, int shiftCount) 
{
    shiftCount %= cols;
    if (shiftCount < 0)
    {
        shiftCount += cols;
    }
    if (shiftCount == 0)
    {
        return;
    }

    int* temp = new int[rows];

    if (direction == 0) 
    {
        for (int s = 0; s < shiftCount; s++)
        {
            for (int i = 0; i < rows; i++)
            {
                temp[i] = arr[i][0];
            }

            for (int j = 0; j < cols - 1; j++)
            {
                for (int i = 0; i < rows; i++)
                {
                    arr[i][j] = arr[i][j + 1];
                }
            }
            
            for (int i = 0; i < rows; i++)
            {
                arr[i][cols - 1] = temp[i];
            }
        }
    }
    else 
    { 
        for (int s = 0; s < shiftCount; s++) 
        {
            for (int i = 0; i < rows; i++)
            {
                temp[i] = arr[i][cols - 1];
            }

            for (int j = cols - 1; j > 0; j++)
            {
                for (int i = 0; i < rows; i++)
                {
                    arr[i][j] = arr[i][j - 1];
                }
            }
            
            for (int i = 0; i < rows; i++)
            {
                arr[i][0] = temp[i];
            }
        }
    }
    delete[] temp;
}

int main() {
    setlocale(LC_ALL, "RU");

    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    srand(time(0));

    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 10;
        }
    }

    printArray(arr, rows, cols);

    int choice, direction, shiftCount;
    cout << "Выберите операцию:\n" << "1 - Сдвиг строк\n" << "2 - Сдвиг столбцов\n";
    cin >> choice;

    if (choice == 1) 
    {
        cout << "Направление (0 - вверх, 1 - вниз): ";
        cin >> direction;
        cout << "Количество сдвигов: ";
        cin >> shiftCount;
        shiftRows(arr, rows, cols, direction, shiftCount);
    }
    else if (choice == 2) 
    {
        cout << "Направление (0 - влево, 1 - вправо): ";
        cin >> direction;
        cout << "Количество сдвигов: ";
        cin >> shiftCount;
        shiftColumns(arr, rows, cols, direction, shiftCount);
    }
    else 
    {
        cout << "Неверный выбор!\n";
    }

    printArray(arr, rows, cols);

    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}