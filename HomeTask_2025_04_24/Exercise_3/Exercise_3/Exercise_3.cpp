#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int pancakes[] = { 3, 1, 4, 2 };
    const int size = 4;

    cout << "Исходная стопка: ";
    for (int i = 0; i < size; i++) {
        cout << pancakes[i] << " ";
    }
    cout << endl;

    for (int current_size = size; current_size > 1; current_size--)
    {
        int max_pos = 0;
        for (int i = 1; i < current_size; i++)
        {
            if (pancakes[i] > pancakes[max_pos]) 
            {
                max_pos = i;
            }
        }

        if (max_pos != current_size - 1)
        {
            if (max_pos != 0) 
            {
                for (int i = 0; i <= max_pos / 2; i++) 
                {
                    swap(pancakes[i], pancakes[max_pos - i]);
                }
            }

            for (int i = 0; i < current_size / 2; i++) {
                swap(pancakes[i], pancakes[current_size - 1 - i]);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << pancakes[i] << " ";
    }
   
    return 0;
}
