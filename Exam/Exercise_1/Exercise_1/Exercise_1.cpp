#include <iostream>
#include <cctype>
using namespace std;

int prioritet3(const char*&); //иначе не смог соблюсти порядок вызова

void removeSpaces(char* str) 
{
    char* dest = str;
    while (*str != '\0') 
    {
        if (*str != ' ' && *str != '\t') 
        {
            *dest++ = *str;
        }
        str++;
    }
    *dest = '\0';
}

bool validation(const char* str) {
    // Проверка на пустую строку
    if (*str == '\0') 
    {
        cout << "Ошибка: Пустая строка\n";
        return false;
    }

    // Проверка, что строка не начинается с * или /
    if (*str == '*' || *str == '/') 
    {
        cout << "Ошибка: Выражение не может начинаться с '" << *str << "'\n";
        return false;
    }

    // Проверка, что строка не заканчивается операцией
    const char* end = str + strlen(str) - 1;
    if (*end == '+' || *end == '-' || *end == '*' || *end == '/') 
    {
        cout << "Ошибка: Выражение не может заканчиваться операцией '" << *end << "'\n";
        return false;
    }

    // Проверка на недопустимые символы и некорректные комбинации операций
    const char* ptr = str;
    while (*ptr) 
    {
        if (!isdigit(*ptr) && *ptr != '+' && *ptr != '-' && *ptr != '*' && *ptr != '/' && *ptr != '(' && *ptr != ')')
        {
            cout << "Ошибка: Недопустимый символ '" << *ptr << "'\n";
            return false;
        }

        // Проверка на некорректные комбинации операций
        if (*ptr == '*' || *ptr == '/')
        {
            const char next = *(ptr + 1);
            if (next == '*' || next == '/' || next == '+' || next == '-') 
            {
                cout << "Ошибка: Некорректная комбинация операций '" << *ptr << next << "'\n";
                return false;
            }
        }

        // Проверка на унарные операции
        if ((*ptr == '+' || *ptr == '-') && (*(ptr + 1) == '*' || *(ptr + 1) == '/'))
        {
            cout << "Ошибка: Некорректная комбинация операций '" << *ptr << *(ptr + 1) << "'\n";
            return false;
        }

        // Проверка выражений в скобках
        if (*ptr == '(') 
        {
            const char* cptr = ptr + 1; //Первый знак после первой скобки
            int balance = 1;

            if (*cptr == ')')
            {
                cout << "Ошибка: Пустые скобки '()'\n";
                return false;
            }

            // Находим закрывающую скобку
            while (*cptr != '\0' && balance > 0)
            {
                if (*cptr == '(')
                {
                    balance++;
                }
                else if (*cptr == ')')
                {
                    balance--;
                }
                cptr++;
            }

            if (balance != 0) 
            {
                cout << "Ошибка: Несбалансированные скобки\n";
                return false;
            }

            if (*(cptr - 2) == '+' || *(cptr - 2) == '-' || *(cptr - 2) == '*' || *(cptr - 2) == '/') //-2 так как двигали указатель после скобки
            {
                cout << "Ошибка: Выражение в скобках заканчивается операцией '" << *(cptr - 2) << "'\n";
                return false;
            }
        }

        ptr++;
    }

    return true;
}

/*void skipSpaces(const char*& ptr)
{
    while (*ptr == ' ')
    {
        ptr++;
    }
}*/

int parseNumber(const char*& ptr) 
{
    //skipSpaces(ptr);
    int num = 0;
    while (isdigit(*ptr)) 
    {
        num = num * 10 + (*ptr - '0'); // Можно было бы сделать чере atoi но этот вариант я стырил и он мне понравился больше, не надо создавать доп переменную со строкой да и нет ошибки по 0 если не разобралось
        ptr++;
    }
    return num;
}

int prioritet1(const char*& ptr) // 1 приоритет для скобок и унарных знаков
{
    //skipSpaces(ptr);
    int znak = 1;

    if (*ptr == '+' || *ptr == '-') 
    {
        znak = (*ptr == '-') ? -1 : 1;
        ptr++;
        //skipSpaces(ptr);
    }

    int result;
    if (*ptr == '(') 
    {
        ptr++;
        result = prioritet3(ptr); //Переход вверх по приоритету при преодалении скобки
        //skipSpaces(ptr);
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
    //skipSpaces(ptr);

    while (*ptr == '*' || *ptr == '/') 
    {
        char znak = *ptr++;
        //skipSpaces(ptr);
        int res = prioritet1(ptr);

        if (znak == '*')
        {
            result *= res;
        }
        else
        {
            result /= res;
        }
        //skipSpaces(ptr);
    }
    return result;
}

int prioritet3(const char*& ptr) // 3 приоритет это + и -
{
    int result = prioritet2(ptr);
    //skipSpaces(ptr);

    while (*ptr == '+' || *ptr == '-') 
    {
        char znak = *ptr++;
        //skipSpaces(ptr);
        int res = prioritet2(ptr);

        if (znak == '+')
        {
            result += res;
        }
        else
        {
            result -= res;
        }

        //skipSpaces(ptr);
    }
    return result;
}

int main() 
{
    setlocale(LC_ALL, "RU");
    
    char str[256];
    cout << "Введите выражение (доступны целые числа, +, -, *, /, унарные +-, скобки): ";
    cin.getline(str, sizeof(str)); // стринг не хотелось использовать
    
    removeSpaces(str); //Удаляем пробелы и табы для проверки валидации строки, через скипспейс уже не получится проверить
    if (!validation(str))
    {
        return 1; 
    }

    const char* ptr = str;
    int result = prioritet3(ptr);
    cout << "Результат: " << result << "\n";

    return 0;
}