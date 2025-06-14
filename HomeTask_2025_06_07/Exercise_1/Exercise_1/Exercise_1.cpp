#include <iostream>
#include <time.h>

using namespace std;

int* new_array(int size)
{
    int* tmp = new int[size];
    return tmp;
}
void init_array(int* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(ptr + i) = rand() % 100;
    }
    return;
}
void print_array(int* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << '\t';
    }
    cout << endl;
    return;
}
void delete_array(int*& arr)
{
    if (arr) {
        delete[]arr;
        arr = nullptr;
        cout << "Осчистили массив \n";
    }
    else
    {
        cout << " Массив уже пуст \n";
    }
    return;
}
void add_element(int*& ptr, int& size, int vol)
{
    int* tmp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        *(tmp + i) = *(ptr + i);
    }
    *(tmp + size) = vol;
    delete_array(ptr);
    ptr = tmp;
    size = size + 1;
    return;
}
void insert_element(int*& ptr, int& size, int vol, int indx)
{
    if (indx > size)
    {
        cout << "Ошибка индекса" << endl;
        return;
    }
    int* tmp = new int[size + 1];
    for (int i = 0; i < indx; i++)
    {
        *(tmp + i) = *(ptr + i);
    }
    *(tmp + indx) = vol;
    for (int i = indx + 1; i < size + 1; i++)
    {
        *(tmp + i) = *(ptr + i - 1);
    }
    delete_array(ptr);
    ptr = tmp;
    size = size + 1;
    return;
}
void delete_element(int*& ptr, int& size, int indx)
{
    if (indx > size - 1)
    {
        cout << "Ошибка индекса" << endl;
        return;
    }
    int* tmp = new int[size - 1];
    for (int i = 0; i < indx; i++)
    {
        *(tmp + i) = *(ptr + i);
    }
    for (int i = indx + 1; i < size + 1; i++)
    {
        *(tmp + i - 1) = *(ptr + i);
    }
    delete_array(ptr);
    ptr = tmp;
    size = size - 1;
    return;
}
void sum_arr(int* arr1, int* arr2, int* arr3, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr3 + i) = *(arr1 + i) + *(arr2 + i);
    }
    return;
}
int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    cout << "Введите размер массива ";
    int size;
    cin >> size;

    int* arr1 = new_array(size);
    init_array(arr1, size);

    cout << "Исходный массив 1" << endl;
    print_array(arr1, size);

    int* arr2 = new_array(size);
    init_array(arr2, size);

    cout << "Исходный массив 2" << endl;
    print_array(arr2, size);

    int* arr3 = new_array(size);
    
    sum_arr(arr1, arr2, arr3, size);
    cout << "Результат" << endl;
    print_array(arr3, size);

    delete_array(arr1);
    delete_array(arr2);
    delete_array(arr3);

    return 0;
}

