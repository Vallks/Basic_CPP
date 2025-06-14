#include <iostream>
#include <time.h>

using namespace std;

void init_array(int* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(ptr + i) = rand() % 200 - 100;
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
void razbit_arr(int* arr, int size)
{
    int size0 = 0, size_pos = 0, size_neg = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0) size_pos++;
        if (arr[i] < 0) size_neg++;
        if (arr[i] == 0) size0++;       
    }
    int indx0 = 0, indx_pos = 0, indx_neg = 0;
    int* arr0 = new int[size0];
    int* arr_pos = new int[size_pos];
    int* arr_neg = new int[size_neg];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            *(arr_pos+indx_pos) = arr[i];
            indx_pos++;
        }
        if (arr[i] < 0) 
        {
            *(arr_neg + indx_neg) = arr[i];
            indx_neg++;
        }
        if (arr[i] == 0) 
        {
            *(arr0 + indx0) = arr[i];
            indx0++;
        }
    }
    cout << "Положительные " << endl;
    print_array(arr_pos, size_pos);
    cout << "Отрицательыне " << endl;
    print_array(arr_neg, size_neg);
    cout << "Нулевые " << endl;
    print_array(arr0, size0);
    return;
}
int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    const int size = 100;
    int arr[size];
    init_array(arr, size);

    cout << "Исходный массив" << endl;
    print_array(arr, size);

    razbit_arr(arr, size);
    return 0;
}