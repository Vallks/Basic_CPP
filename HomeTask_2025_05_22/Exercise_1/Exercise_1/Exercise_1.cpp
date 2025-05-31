#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

const int SIZE = 10; 

void initMtx(int ar[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            ar[i][j] = rand() % 100;
        }
    }
}

void printMtx(int ar[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << ar[i][j] << '\t';
        }
        cout << endl;
    }
}

void minMaxDiagonal(int ar[SIZE][SIZE], int& min, int& max)
{
    min = ar[0][0];
    max = ar[0][0];
    for (int i = 1; i < SIZE; ++i) {
        if (ar[i][i] < min) min = ar[i][i];
        if (ar[i][i] > max) max = ar[i][i];
    }
}

void sortRow(int row[SIZE]) 
{
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = 0; j < SIZE - i - 1; ++j) {
            if (row[j] > row[j + 1]) {
                int temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

void initMtx(double ar[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            ar[i][j] = (double)(rand() % 100) / 100;
        }
    }
}

void printMtx(double ar[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << ar[i][j] << '\t';
        }
        cout << endl;
    }
}

void minMaxDiagonal(double ar[SIZE][SIZE], double& min, double& max)
{
    min = ar[0][0];
    max = ar[0][0];
    for (int i = 1; i < SIZE; ++i) {
        if (ar[i][i] < min) min = ar[i][i];
        if (ar[i][i] > max) max = ar[i][i];
    }
}

void sortRow(double row[SIZE])
{
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = 0; j < SIZE - i - 1; ++j) {
            if (row[j] > row[j + 1]) {
                double temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

void initMtx(char ar[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            ar[i][j] = rand() % 100;
        }
    }
}

void printMtx(char ar[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << ar[i][j] << '\t';
        }
        cout << endl;
    }
}

void minMaxDiagonal(char ar[SIZE][SIZE], char& min, char& max)
{
    min = ar[0][0];
    max = ar[0][0];
    for (int i = 1; i < SIZE; ++i) {
        if (ar[i][i] < min) min = ar[i][i];
        if (ar[i][i] > max) max = ar[i][i];
    }
}

void sortRow(char row[SIZE])
{
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = 0; j < SIZE - i - 1; ++j) {
            if (row[j] > row[j + 1]) {
                char temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int intmtr[SIZE][SIZE];
    int intMin, intMax;
    initMtx(intmtr);
    printMtx(intmtr);
    minMaxDiagonal(intmtr, intMin, intMax);
    cout << "min " << intMin << " max " << intMax << endl;
    for (int i = 0; i < SIZE; i++)
    {
        sortRow(intmtr[i]);
    }
    printMtx(intmtr);

    cout << endl;

    double dblmtr[SIZE][SIZE];
    double dblMin, dblMax;
    initMtx(dblmtr);
    printMtx(dblmtr);
    minMaxDiagonal(dblmtr, dblMin, dblMax);
    cout << "min " << dblMin << " max " << dblMax << endl;
    for (int i = 0; i < SIZE; i++)
    {
        sortRow(dblmtr[i]);
    }
    printMtx(dblmtr);

    cout << endl;

    char chmtr[SIZE][SIZE];
    char chMin, chMax;
    initMtx(chmtr);
    printMtx(chmtr);
    minMaxDiagonal(chmtr, chMin, chMax);
    cout << "min " << chMin << " max " << chMax << endl;
    for (int i = 0; i < SIZE; i++)
    {
        sortRow(chmtr[i]);
    }
    printMtx(chmtr);
}

