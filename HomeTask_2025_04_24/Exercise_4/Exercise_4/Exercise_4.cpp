#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int array_size = 1000;
    const int tests_count = 10;
    srand(time(NULL));

    int total_bubble_swaps = 0;
    int total_selection_swaps = 0;

    for (int test = 0; test < tests_count; test++)
    {
        int arr1[array_size], arr2[array_size];
        for (int i = 0; i < array_size; i++) 
        {
            int val = rand();
            arr1[i] = val;
            arr2[i] = val;
        }

        int bubble_swaps = 0;
        for (int i = 0; i < array_size - 1; i++) 
        {
            int swp = 0;
            for (int j = 0; j < array_size - i - 1; j++) 
            {
                if (arr1[j] > arr1[j + 1]) {
                    swap(arr1[j], arr1[j + 1]);
                    bubble_swaps++;
                    swp++;
                }
            }
            if (swp == 0)
            {
                break;
            };
        }
        total_bubble_swaps += bubble_swaps;

        int selection_swaps = 0;
        for (int i = 0; i < array_size - 1; i++) 
        {
            int min_idx = i;
            for (int j = i + 1; j < array_size; j++) 
            {
                if (arr2[j] < arr2[min_idx]) 
                {
                    min_idx = j;
                }
            }
            if (min_idx != i) 
            {
                swap(arr2[i], arr2[min_idx]);
                selection_swaps++;
            }
        }
        total_selection_swaps += selection_swaps;

        cout << "Тест " << test + 1 << ": Пузырек = " << bubble_swaps
            << ", Выбор = " << selection_swaps << endl;
    }

    double avg_bubble = static_cast<double>(total_bubble_swaps) / tests_count;
    double avg_selection = static_cast<double>(total_selection_swaps) / tests_count;

    cout << "\nСреднее количество перестановок:\n";
    cout << "Сортировка пузырьком: " << avg_bubble << endl;
    cout << "Сортировка выбором: " << avg_selection << endl;

    return 0;
}