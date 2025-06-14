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
void delete_array(int* &arr)
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
int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    
    cout << "Введите размер массива ";
    int size;
    cin >> size;
    
    int* arr = new_array(size);
    init_array(arr, size);
    
    cout << "Исходный массив" << endl;
    print_array(arr, size);

    int vol;
    cout << "Введите число для добавления в конец массива ";
    cin >> vol;
    add_element(arr, size, vol);

    cout << "Массив с добавленным числом " << endl;
    print_array(arr, size);

    cout << "Введите число для вставки ";
    cin >> vol;
    cout << "Введите индекс для вставки ";
    int indx;
    cin >> indx;
    insert_element(arr, size, vol, indx);

    cout << "Массив с вставкой" << endl;
    print_array(arr, size);

    cout << "Введите индекс для удаления ";
    cin >> indx;
    delete_element(arr, size, indx);

    cout << "Массив после удаления" << endl;
    print_array(arr,size);
    
    delete_array(arr);
    
    return 0;
}
