#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 10; i++) 
{
        for (char j = 'A'; j <= 'J'; j++) {
            std::cout << j << i << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

