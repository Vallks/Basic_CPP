#include <iostream>

using namespace std;

int main()
{
    for (int row = 0; row < 10; row++) {
        for (char col = 'A'; col <= 'J'; col++) {
            std::cout << col << row << " ";
        }
        std::cout << "\n";
    }
}

