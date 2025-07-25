﻿#include <iostream>
#include <ctime>
using namespace std;

void printArray(int** arr, int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void addColumn(int**& arr, int rows, int& cols, int insertPos) 
{
    if (insertPos < 0 || insertPos > cols) 
    {
        std::cout << "Ошибка: недопустимая позиция для вставки!\n";
        return;
    }

    int newCols = cols + 1;

    int** newArr = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        newArr[i] = new int[newCols];
    }

   for (int i = 0; i < rows; ++i) 
   {
        for (int j = 0, k = 0; j < newCols; ++j) 
        {
            if (j == insertPos) 
            {
                newArr[i][j] = rand() % 10;
            }
            else 
            {
                newArr[i][j] = arr[i][k++];
            }
        }
    }

    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newArr;
    cols = newCols;
}

int main() 
{
    setlocale(LC_ALL, "RU");

    int rows, cols, pos;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;
    srand(time(0));

    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            arr[i][j] = rand() % 10;  
        }
    }
    printArray(arr, rows, cols);

    cout << "Введите позицию: ";
    cin >> pos;

    addColumn(arr, rows, cols, pos);
    printArray(arr, rows, cols);

    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}