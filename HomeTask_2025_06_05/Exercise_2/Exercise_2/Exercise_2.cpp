#include <iostream>

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
        *(ptr + i) = i;
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
bool is_simpl(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
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
int* delete_simpl(int* ptr,int &size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (!is_simpl(*(ptr + i)))
        {
            count++;
        }
    }
    int* tmp = new int[count];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (!is_simpl(*(ptr + i)))
        {
            *(tmp + j) = *(ptr + i);
            j++;
        }
    }
    delete_array(ptr);
    size = count;
    return tmp;
}
int main()
{
    setlocale(LC_ALL, "RU");
    
    cout << "Введите размер массива ";
    int size;
    cin >> size;

    int* arr = new_array(size);
    init_array(arr, size);

    cout << "Исходный массив" << endl;
    print_array(arr, size);

    arr = delete_simpl(arr, size);

    cout << "Массив без простых чисел" << endl;
    print_array(arr, size);
    delete_array(arr);
    return 0;
}