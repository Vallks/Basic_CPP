#include <iostream>
#include <cctype>
using namespace std;

int prioritet3(const char*&); //иначе не смог соблюсти порядок вызова

void skipSpaces(const char*& ptr) // можно было бы конечно обходом сначала убрать всю строку и убрать пробелы, но не стал. Пропускает всегда при преходе
{
    while (*ptr == ' ')
    {
        ptr++;
    }
}

int parseNumber(const char*& ptr) 
{
    skipSpaces(ptr);
    int num = 0;
    while (isdigit(*ptr)) {
        num = num * 10 + (*ptr - '0'); // Можно было бы сделать чере atoi но этот вариант я стырил и он мне понравился больше, не надо создавать доп переменную со строкой да и нет ошибки по 0 если не разобралось
        ptr++;
    }
    return num;
}

int prioritet1(const char*& ptr) // 1 приоритет для скобок и унарных знаков
{
    skipSpaces(ptr);
    int znak = 1;

    if (*ptr == '+' || *ptr == '-') 
    {
        znak = (*ptr == '-') ? -1 : 1;
        ptr++;
        skipSpaces(ptr);
    }

    int result;
    if (*ptr == '(') 
    {
        ptr++;
        result = prioritet3(ptr); //Переход вверх по приоритету при преодалении скобки
        skipSpaces(ptr);
        if (*ptr != ')') 
        {
            cout << "Нет закрывающей скобки\n";
            exit(1); // только так иначе расчет не правильный будет
        }
        ptr++;
    }
    else
    {
        result = parseNumber(ptr);
    }

    return znak * result;
}

int prioritet2(const char*& ptr) // 2 приоритет это * и /
{
    int result = prioritet1(ptr);
    skipSpaces(ptr);

    while (*ptr == '*' || *ptr == '/') 
    {
        char znak = *ptr++;
        skipSpaces(ptr);
        int res = prioritet1(ptr);

        if (znak == '*')
        {
            result *= res;
        }
        else
        {
            result /= res;
        }
        skipSpaces(ptr);
    }
    return result;
}

int prioritet3(const char*& ptr) // 3 приоритет это + и -
{
    int result = prioritet2(ptr);
    skipSpaces(ptr);

    while (*ptr == '+' || *ptr == '-') 
    {
        char znak = *ptr++;
        skipSpaces(ptr);
        int res = prioritet2(ptr);

        if (znak == '+')
        {
            result += res;
        }
        else
        {
            result -= res;
        }

        skipSpaces(ptr);
    }
    return result;
}

int main() 
{
    setlocale(LC_ALL, "RU");
    
    char str[256];
    cout << "Введите выражение (доступны +, -, *, /, унарные +-, скобки): ";
    cin.getline(str, sizeof(str)); // стринг не хотелось использовать

    const char* ptr = str;
    int result = prioritet3(ptr);
    cout << "Результат: " << result << "\n";

    return 0;
}