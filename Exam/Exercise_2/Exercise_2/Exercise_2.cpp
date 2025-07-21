#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

const int MAX_TASKS = 100;

struct Task
{
    string title;
    int priority;
    string description;
    int year, month, day, hour, minute;
};

int currentYear, currentMonth, currentDay, currentWeekDay;

bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

bool isValidDate(int year, int month, int day) {
    if (year < 1) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;

    int daysInMonth;
    switch (month) {
    case 2:
        daysInMonth = isLeapYear(year) ? 29 : 28;
        break;
    case 4: case 6: case 9: case 11:
        daysInMonth = 30;
        break;
    default:
        daysInMonth = 31;
    }

    return day <= daysInMonth;
}

void inputDateWithValidation(int& year, int& month, int& day) {
    while (true) {
        cout << "Год: "; 
        cin >> year;
        cout << "Месяц (1-12): "; 
        cin >> month;
        cout << "День: "; 
        cin >> day;

        if (isValidDate(year, month, day)) {
            break;
        }
        cout << "Некорректная дата! Пожалуйста, введите снова.\n";
        cin.clear();
        cin.ignore();
    }
}

void printMenu()
{
    cout << "\n=== Список дел ===\n";
    cout << "1. Добавить дело\n";
    cout << "2. Удалить дело\n";
    cout << "3. Редактировать дело\n";
    cout << "4. Поиск дел\n";
    cout << "5. Показать дела\n";
    cout << "6. Выход\n";
    cout << "Выберите действие: ";
}

void addTask(Task tasks[], int& count) {
    if (count >= MAX_TASKS)
    {
        cout << "Достигнуто максимальное количество дел!\n";
        return;
    }

    cout << "\nДобавление нового дела:\n";
    cout << "Название: ";
    cin.ignore();
    getline(cin, tasks[count].title);

    cout << "Приоритет (1-высокий, 2-средний, 3-низкий): ";
    while (!(cin >> tasks[count].priority) || tasks[count].priority < 1 || tasks[count].priority > 3) 
    {
        cout << "Некорректный приоритет! Введите число от 1 до 3: ";
        cin.clear();
        cin.ignore();
    }

    cout << "Описание: ";
    cin.ignore();
    getline(cin, tasks[count].description);

    cout << "Дата и время исполнения:\n";
    inputDateWithValidation(tasks[count].year, tasks[count].month, tasks[count].day);

    cout << "Час (0-23): ";
    while (!(cin >> tasks[count].hour) || tasks[count].hour < 0 || tasks[count].hour > 23) 
    {
        cout << "Некорректный час! Введите число от 0 до 23: ";
        cin.clear();
        cin.ignore();
    }

    cout << "Минута (0-59): ";
    while (!(cin >> tasks[count].minute) || tasks[count].minute < 0 || tasks[count].minute > 59) 
    {
        cout << "Некорректные минуты! Введите число от 0 до 59: ";
        cin.clear();
        cin.ignore();
    }

    count++;
    cout << "Дело успешно добавлено!\n";
}
void deleteTask(Task tasks[], int& count)
{
    if (count == 0)
    {
        cout << "Список дел пуст!\n";
        return;
    }

    cout << "\nТекущий список дел:\n";
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << ". " << tasks[i].title << " (приоритет: " << tasks[i].priority << ")\n";
    }

    int index;
    cout << "Введите номер дела для удаления: ";
    cin >> index;
    index--;

    if (index < 0 || index >= count)
    {
        cout << "Неверный номер дела!\n";
        return;
    }

    for (int i = index; i < count - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }

    count--;
    cout << "Дело успешно удалено!\n";
}

void editTask(Task tasks[], int count)
{
    if (count == 0)
    {
        cout << "Список дел пуст!\n";
        return;
    }

    cout << "\nТекущий список дел:\n";
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << ". " << tasks[i].title << " (приоритет: " << tasks[i].priority << ")\n";
    }

    int index;
    cout << "Введите номер дела для редактирования: ";
    cin >> index;
    index--;

    if (index < 0 || index >= count)
    {
        cout << "Неверный номер дела!\n";
        return;
    }

    cout << "\nРедактирование дела:\n";
    cout << "Название (" << tasks[index].title << "): ";
    cin.ignore();
    getline(cin, tasks[index].title);

    cout << "Приоритет (" << tasks[index].priority << "): ";
    cin >> tasks[index].priority;

    cout << "Описание (" << tasks[index].description << "): ";
    cin.ignore();
    getline(cin, tasks[index].description);

    cout << "Дата и исполнения (" << tasks[index].year << "-" << tasks[index].month << "-" << tasks[index].day << " " << tasks[index].hour << ":" << tasks[index].minute <<"): ";
    inputDateWithValidation(tasks[index].year, tasks[index].month, tasks[index].day);

    cout << "Час (0-23): ";
    while (!(cin >> tasks[index].hour) || tasks[index].hour < 0 || tasks[index].hour > 23)
    {
        cout << "Некорректный час! Введите число от 0 до 23: ";
        cin.clear();
        cin.ignore();
    }

    cout << "Минута (0-59): ";
    while (!(cin >> tasks[index].minute) || tasks[index].minute < 0 || tasks[index].minute > 59)
    {
        cout << "Некорректные минуты! Введите число от 0 до 59: ";
        cin.clear();
        cin.ignore();
    }

    cout << "Дело успешно отредактировано!\n";
}

void searchTasks(Task tasks[], int count)
{
    if (count == 0)
    {
        cout << "Список дел пуст!\n";
        return;
    }

    cout << "\nПоиск по:\n";
    cout << "1. Названию\n";
    cout << "2. Приоритету\n";
    cout << "3. Описанию\n";
    cout << "4. Дате и времени\n";
    cout << "Выберите вариант поиска: ";

    int choice;
    cin >> choice;

    cin.ignore(); // Очистка буфера

    bool found = false;
    string searchStr;
    int searchPriority;
    int y, m, d, h, min;

    switch (choice)
    {
    case 1:
        cout << "Введите название для поиска: ";
        getline(cin, searchStr);
        for (int i = 0; i < count; i++)
        {
            if (tasks[i].title.find(searchStr) != string::npos)
            {
                cout << "Найдено: " << tasks[i].title << " (приоритет: " << tasks[i].priority << ")\n";
                found = true;
            }
        }
        break;
    case 2:
        cout << "Введите приоритет для поиска (1-3): ";
        cin >> searchPriority;
        for (int i = 0; i < count; i++) {
            if (tasks[i].priority == searchPriority)
            {
                cout << "Найдено: " << tasks[i].title << " (приоритет: " << tasks[i].priority << ")\n";
                found = true;
            }
        }
        break;
    case 3:
        cout << "Введите текст описания для поиска: ";
        getline(cin, searchStr);
        for (int i = 0; i < count; i++)
        {
            if (tasks[i].description.find(searchStr) != string::npos)
            {
                cout << "Найдено: " << tasks[i].title << " (приоритет: " << tasks[i].priority << ")\n";
                found = true;
            }
        }
        break;
    case 4:
        cout << "Введите дату и время для поиска:\n";
        cout << "Год: "; cin >> y;
        cout << "Месяц (1-12): "; cin >> m;
        cout << "День: "; cin >> d;
        cout << "Час (0-23): "; cin >> h;
        cout << "Минута (0-59): "; cin >> min;
        for (int i = 0; i < count; i++)
        {
            if (tasks[i].year == y && tasks[i].month == m && tasks[i].day == d && tasks[i].hour == h && tasks[i].minute == min)
            {
                cout << "Найдено: " << tasks[i].title << " (приоритет: " << tasks[i].priority << ")\n";
                found = true;
            }
        }
        break;
    default:
        cout << "Неверный выбор!\n";
        return;
    }

    if (!found) {
        cout << "Дела не найдены!\n";
    }
}

bool compareByPriority(const Task& a, const Task& b)
{
    return a.priority < b.priority;
}

bool compareByDate(const Task& a, const Task& b)
{
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    if (a.day != b.day) return a.day < b.day;
    if (a.hour != b.hour) return a.hour < b.hour;
    return a.minute < b.minute;
}

void sortTasks(Task tasks[], int count, bool (*compare)(const Task&, const Task&))
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (!compare(tasks[j], tasks[j + 1]))
            {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

bool isTaskInCurrentWeek(const Task& task)
{
    int taskDays = task.year * 365 + task.month * 30 + task.day;
    int currentDays = currentYear * 365 + currentMonth * 30 + currentDay;
    int diff = taskDays - currentDays;

    return (diff >= 0 && diff < 7);
}

void displayTasks(Task tasks[], int count)
{
    if (count == 0)
    {
        cout << "Список дел пуст!\n";
        return;
    }

    cout << "\nПоказать:\n";
    cout << "1. На сегодня (" << currentDay << "." << currentMonth << "." << currentYear << ")\n";
    cout << "2. На неделю (начиная с " << currentDay << "." << currentMonth << "." << currentYear << ")\n";
    cout << "3. На месяц (" << currentMonth << "." << currentYear << ")\n";
    cout << "4. Все дела\n";
    cout << "Выберите вариант: ";

    int choice;
    cin >> choice;

    cout << "\nСортировать по:\n";
    cout << "1. Приоритету\n";
    cout << "2. Дате и времени\n";
    cout << "Выберите вариант сортировки: ";

    int sortChoice;
    cin >> sortChoice;

    Task tempTasks[MAX_TASKS];
    for (int i = 0; i < count; i++)
    {
        tempTasks[i] = tasks[i];
    }

    if (sortChoice == 1)
    {
        sortTasks(tempTasks, count, compareByPriority);
    }
    else if (sortChoice == 2) {
        sortTasks(tempTasks, count, compareByDate);
    }
    else 
    {
        cout << "Неверный выбор сортировки!\n";
        return;
    }

    cout << "\nСписок дел:\n";
    for (int i = 0; i < count; i++) {
        bool show = false;

        switch (choice) {
        case 1: // На сегодня
            show = (tempTasks[i].year == currentYear &&
                tempTasks[i].month == currentMonth &&
                tempTasks[i].day == currentDay);
            break;
        case 2: // На неделю
            show = isTaskInCurrentWeek(tempTasks[i]);
            break;
        case 3: // На месяц
            show = (tempTasks[i].year == currentYear &&
                tempTasks[i].month == currentMonth);
            break;
        case 4: // Все дела
            show = true;
            break;
        default:
            cout << "Неверный выбор!\n";
            return;
        }

        if (show)
        {
            cout << "Название: " << tempTasks[i].title << "\n";
            cout << "Приоритет: " << tempTasks[i].priority << "\n";
            cout << "Описание: " << tempTasks[i].description << "\n";
            cout << "Дата и время: " << tempTasks[i].year << "-" << tempTasks[i].month << "-" << tempTasks[i].day
                << " " << tempTasks[i].hour << ":" << tempTasks[i].minute << "\n";
            cout << "----------------------------\n";
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите текущую дату:\n";
    inputDateWithValidation(currentYear, currentMonth, currentDay);

    cout << "День недели (1-Пн, 2-Вт, ..., 7-Вс): ";
    while (!(cin >> currentWeekDay) || currentWeekDay < 1 || currentWeekDay > 7)
    {
        cout << "Некорректный день недели! Введите число от 1 до 7: ";
        cin.clear();
        cin.ignore();
    }

    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do
    {
        printMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask(tasks, taskCount);
            break;
        case 2:
            deleteTask(tasks, taskCount);
            break;
        case 3:
            editTask(tasks, taskCount);
            break;
        case 4:
            searchTasks(tasks, taskCount);
            break;
        case 5:
            displayTasks(tasks, taskCount);
            break;
        case 6:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    } while (choice != 6);

    return 0;
}