#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void initArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = static_cast<T>(rand() % 100); 
    }
    return;
}

template <typename T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<"\t";
    }

    cout << endl;
    return;
}

void initArray(bool arr[], int size)
{
    cout << "Ошибка.";
    return;

}

void printArray(bool arr[], int size)
{
    cout << "Ошибка.";
    return;

}

int main()
{
    setlocale(LC_ALL, "RU");
    const size_t size = 5;

    int intArr[size];
    initArray(intArr, size);
    printArray(intArr, size);

    double doubleArr[size];
    initArray(doubleArr, size);
    printArray(doubleArr, size);

    char charArr[size];
    initArray(charArr, size);
    printArray(charArr, size);

    short shortArr[size];
    initArray(shortArr, size);
    printArray(shortArr, size);

    long longArr[size];
    initArray(longArr, size);
    printArray(longArr, size);

    long long llongArr[size];
    initArray(llongArr, size);
    printArray(llongArr, size);

    bool boolArr[size];
    initArray(boolArr, size); 
    printArray(boolArr, size);

    return 0;
}

