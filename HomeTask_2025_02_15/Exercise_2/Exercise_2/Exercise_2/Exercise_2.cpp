#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    cout << "Каждый\n";

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\tОхотник\n";

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "\t\tЖелает\n";

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "\t\t\tЗнать\n";

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "\t\t\t\tГде\n";

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    cout << "\t\t\t\t\tСидит\n";

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    cout << "\t\t\t\t\t\tФазан\n";

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    return 0;
}
