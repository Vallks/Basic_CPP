#include <iostream>
#include <string> // Решал через строки 

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    
    int num;
    
    cout << "Введите целое число: ";
    
    cin >> num;

    string numStr = to_string(num);  //число в строку
    string res;

    for (char ch : numStr) 
    {
        if (ch != '3' && ch != '6') 
        {
            res += ch;
        }
    }

    if (res.empty()) 
    {
        cout << 0 << std::endl;
    }
    else 
    {
        int num = stoi(res); //строку в число

        cout << num << endl;
    }

    return 0;
}