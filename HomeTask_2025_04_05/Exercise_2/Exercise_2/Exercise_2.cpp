#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    unsigned r = 0;
    char s1, s2;

    cout << "Введите размер клетки: ";
    cin >> r;

    for (int i = 0; i < 8; i++)
    {
        for (int z = 0; z < r; z++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i % 2 == 0)
                {
                    s1 = '*';
                    s2 = '-';
                }
                else
                {
                    s1 = '-';
                    s2 = '*';
                }
                for (int k = 0; k < r; k++)
                {
                    cout << s1;
                }
                for (int k = 0; k < r; k++)
                {
                    cout << s2;
                }
            }
            cout << endl;
        }
    }

    return 0;
}

