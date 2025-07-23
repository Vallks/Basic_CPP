
#include<iostream>
#include<stdlib.h>
#include <time.h>
#include <string>

using namespace std;


void RandomNumber(int* ptr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        ptr[i] = rand() % 21;
    }

}
void RandomNumber(double* ptr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        ptr[i] = rand() % 21 + 0.25;
    }

}
void RandomNumber(string* ptr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        ptr[i] = rand() % 25 + 65;
    }

}

//функци€ вывода
void Print(int* ptr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << ptr[i] << "\t";
    }
    cout << endl;
}

void Print(double* ptr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << ptr[i] << "\t";
    }
    cout << endl;
}

void Print(string* ptr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << ptr[i] << "\t";
    }
    cout << endl;
}

int Max(int* ptr, const int size)
{
    int max = ptr[0];
    for (int i = size - 1; i >= 0; --i)
    {
        if (ptr[i] > max)
        {
            max = ptr[i];
        }
    }
    return max;
}

double Max(double* ptr, const int size)
{
    double max = ptr[0];
    for (int i = size - 1; i >= 0; --i)
    {
        if (ptr[i] > max)
        {
            max = ptr[i];
        }
    }
    return max;
}

string Max(string* ptr, const int size)
{
    string max = ptr[0];
    for (int i = size - 1; i >= 0; --i)
    {
        if (ptr[i] > max)
        {
            max = ptr[i];
        }
    }
    return max;
}


int Min(int* ptr, const int size)
{
    int min = ptr[0];
    for (int i = 0; i < size; ++i)
    {
        if (ptr[i] < min)
        {
            min = ptr[i];
        }
    }
    return min;
}

double Min(double* ptr, const int size)
{
    double min = ptr[0];
    for (int i = 0; i < size; ++i)
    {
        if (ptr[i] < min)
        {
            min = ptr[i];
        }
    }
    return min;
}

string Min(string* ptr, const int size)
{
    string min = ptr[0];
    for (int i = 0; i < size; ++i)
    {
        if (ptr[i] < min)
        {
            min = ptr[i];
        }
    }
    return min;
}


void sort(int* ptr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (ptr[j] > ptr[j + 1])
            {
                swap(ptr[j], ptr[j + 1]);
            }
        }
    }
}

void sort(double* ptr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (ptr[j] > ptr[j + 1])
            {
                swap(ptr[j], ptr[j + 1]);
            }
        }
    }
}

void sort(string* ptr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (ptr[j] > ptr[j + 1])
            {
                swap(ptr[j], ptr[j + 1]);
            }
        }
    }
}


void edit(int* ptr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "¬ведите новое значение " << i + 1 << ": ";
        cin >> ptr[i];
    }
}

void edit(double* ptr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "¬ведите новое значение " << i + 1 << ": ";
        cin >> ptr[i];
    }
}

void edit(string* ptr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "¬ведите новое значение " << i + 1 << ": ";
        cin >> ptr[i];
    }
}

