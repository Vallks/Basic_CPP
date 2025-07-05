#include <iostream>
#include <cctype>
using namespace std;

double prioritet3(const char*&); //иначе не смог соблюсти порядок вызова

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
    
    if (*str == '\0') 
    {
        cout << "Ошибка: Пустая строка\n";
        return false;
    }

    if (*str == '*' || *str == '/') 
    {
        cout << "Ошибка: Выражение не может начинаться с '" << *str << "'\n";
        return false;
    }

    const char* end = str + strlen(str) - 1;
    if (*end == '+' || *end == '-' || *end == '*' || *end == '/') 
    {
        cout << "Ошибка: Выражение не может заканчиваться операцией '" << *end << "'\n";
        return false;
    }

    const char* ptr = str;
    bool flagDec = false;
    while (*ptr) 
    {
        if (!isdigit(*ptr) && *ptr != '+' && *ptr != '-' && *ptr != '*' && *ptr != '/' && *ptr != '(' && *ptr != ')' && *ptr != '.')
        {
            cout << "Ошибка: Недопустимый символ '" << *ptr << "'\n";
            return false;
        }

        if (*ptr == '.') 
        {
            if (flagDec) 
            {
                cout << "Ошибка: Несколько точек в числе\n";
                return false;
            }
            flagDec = true;
            if (!(ptr > str && isdigit(*(ptr - 1)) || !(*(ptr + 1) && isdigit(*(ptr + 1))))) 
            {
                cout << "Ошибка: Некорректное использование точки\n";
                return false;
            }
        }
        else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/' ||
            *ptr == '(' || *ptr == ')') {
            flagDec = false; // Сброс флага точки при операторе или скобке
        }

        if (*ptr == '*' || *ptr == '/')
        {
            const char next = *(ptr + 1);
            if (next == '*' || next == '/' || next == '+' || next == '-') 
            {
                cout << "Ошибка: Некорректная комбинация операций '" << *ptr << next << "'\n";
                return false;
            }
        }

        if ((*ptr == '+' || *ptr == '-') && (*(ptr + 1) == '*' || *(ptr + 1) == '/'))
        {
            cout << "Ошибка: Некорректная комбинация операций '" << *ptr << *(ptr + 1) << "'\n";
            return false;
        }

        if (*ptr == '(') 
        {
            const char* cptr = ptr + 1; //Первый знак после первой скобки
            int balance = 1;

            if (*cptr == ')')
            {
                cout << "Ошибка: Пустые скобки '()'\n";
                return false;
            }

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

double parseNumber(const char*& ptr)
{
    //skipSpaces(ptr);
    double num = 0.;
    double decNum = 0.0;
    double div = 10.0;
    while (isdigit(*ptr)) 
    {
        num = num * 10.0 + (*ptr - '0'); // Можно было бы сделать чере atoi но этот вариант я стырил и он мне понравился больше, не надо создавать доп переменную со строкой да и нет ошибки по 0 если не разобралось
        ptr++;
    }
    //return num;

    if (*ptr == '.') {
        ptr++;
        while (isdigit(*ptr)) {
            decNum += (*ptr - '0') / div;
            div *= 10.0;
            ptr++;
        }
    }
    return num + decNum;
}

double prioritet1(const char*& ptr) // 1 приоритет для скобок и унарных знаков
{
    //skipSpaces(ptr);
    int znak = 1;

    if (*ptr == '+' || *ptr == '-') 
    {
        znak = (*ptr == '-') ? -1 : 1;
        ptr++;
        //skipSpaces(ptr);
    }

    double result;
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

double prioritet2(const char*& ptr) // 2 приоритет это * и /
{
    double result = prioritet1(ptr);
    //skipSpaces(ptr);

    while (*ptr == '*' || *ptr == '/') 
    {
        char znak = *ptr++;
        //skipSpaces(ptr);
        double res = prioritet1(ptr);

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

double prioritet3(const char*& ptr) // 3 приоритет это + и -
{
    double result = prioritet2(ptr);
    //skipSpaces(ptr);

    while (*ptr == '+' || *ptr == '-') 
    {
        char znak = *ptr++;
        //skipSpaces(ptr);
        double res = prioritet2(ptr);

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
    cout << "Введите выражение (доступны числа, +, -, *, /, унарные +-, скобки): ";
    cin.getline(str, sizeof(str)); // стринг не хотелось использовать
    
    removeSpaces(str); //Удаляем пробелы и табы для проверки валидации строки, через скипспейс уже не получится проверить
    if (!validation(str))
    {
        return 1; 
    }

    const char* ptr = str;
    double result = prioritet3(ptr);
    cout << "Результат: " << result << "\n";

    return 0;
}