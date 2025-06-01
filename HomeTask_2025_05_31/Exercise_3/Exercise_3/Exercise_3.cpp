#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
    int arr1[size] = { 1,2,3,4,5,6,7,8,9,10 };
    int arr2[size];
    int* ptrArr1 = arr1;
    int* ptrArr2 = arr2;

    for (int i = 0; i < size; i++)
    {
        *(ptrArr2 + size - 1 - i) = *(ptrArr1 + i);
    }

    for (int i = 0; i < size; i++)
    {
        cout << *(ptrArr1 + i) << '\t';
    }

    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << *(ptrArr2 + i) << '\t';
    }

    return 0;
}
