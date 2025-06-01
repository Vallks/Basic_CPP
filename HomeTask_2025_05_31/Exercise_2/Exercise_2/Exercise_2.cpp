#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
    int arr[size] = { 1,2,3,4,5,6,7,8,9,10 };

    int* start = arr;
    int* end = arr + size - 1;

    for (int i = 0; i < size; i++)
    {
        cout << *(start + i) << '\t';
    }
    
    cout << endl;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    start = arr;

    for (int i = 0; i < size; i++)
    {
        cout << *(start + i) << '\t';
    }

    return 0;
}
