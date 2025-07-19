#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

const int MAX_BOOKS = 10;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;

    void print() const {
        cout << "Название: " << setw(30) << left << title
            << " Автор: " << setw(20) << left << author
            << " Издательство: " << setw(15) << left << publisher
            << " Жанр: " << genre << endl;
    }
};

void printAllBooks(const Book books[], int count) {
    cout << "\nСписок всех книг:\n";
    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ". ";
        books[i].print();
    }
    cout << endl;
}

void editBook(Book books[], int count) {
    printAllBooks(books, count);
    cout << "Введите номер книги для редактирования: ";
    int index;
    cin >> index;
    cin.ignore(); 

    if (index > 0 && index <= count) {
        Book& book = books[index - 1];
        cout << "Редактирование книги: ";
        book.print();

        cout << "Новое название (оставьте пустым чтобы не менять): ";
        string input;
        getline(cin, input);
        if (!input.empty()) book.title = input;

        cout << "Новый автор (оставьте пустым чтобы не менять): ";
        getline(cin, input);
        if (!input.empty()) book.author = input;

        cout << "Новое издательство (оставьте пустым чтобы не менять): ";
        getline(cin, input);
        if (!input.empty()) book.publisher = input;

        cout << "Новый жанр (оставьте пустым чтобы не менять): ";
        getline(cin, input);
        if (!input.empty()) book.genre = input;

        cout << "Книга успешно отредактирована!\n";
    }
    else {
        cout << "Неверный номер книги.\n";
    }
}

void searchByAuthor(const Book books[], int count) {
    cout << "Введите автора для поиска: ";
    string author;
    getline(cin, author);

    bool found = false;
    for (int i = 0; i < count; ++i) {
        string bookAuthorLower = books[i].author;
        transform(bookAuthorLower.begin(), bookAuthorLower.end(), bookAuthorLower.begin(), ::tolower);
        string authorLower = author;
        transform(authorLower.begin(), authorLower.end(), authorLower.begin(), ::tolower);

        if (bookAuthorLower.find(authorLower) != string::npos) {
            if (!found) {
                cout << "\nНайденные книги:\n";
                found = true;
            }
            books[i].print();
        }
    }

    if (!found) {
        cout << "Книги данного автора не найдены.\n";
    }
    cout << endl;
}

void searchByTitle(const Book books[], int count) {
    cout << "Введите название книги для поиска: ";
    string title;
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < count; ++i) {
        string bookTitleLower = books[i].title;
        transform(bookTitleLower.begin(), bookTitleLower.end(), bookTitleLower.begin(), ::tolower);
        string titleLower = title;
        transform(titleLower.begin(), titleLower.end(), titleLower.begin(), ::tolower);

        if (bookTitleLower.find(titleLower) != string::npos) {
            if (!found) {
                cout << "\nНайденные книги:\n";
                found = true;
            }
            books[i].print();
        }
    }

    if (!found) {
        cout << "Книги с таким названием не найдены.\n";
    }
    cout << endl;
}

bool compareByTitle(const Book& a, const Book& b) {
    string aTitleLower = a.title;
    string bTitleLower = b.title;
    transform(aTitleLower.begin(), aTitleLower.end(), aTitleLower.begin(), ::tolower);
    transform(bTitleLower.begin(), bTitleLower.end(), bTitleLower.begin(), ::tolower);
    return aTitleLower < bTitleLower;
}

bool compareByAuthor(const Book& a, const Book& b) {
    string aAuthorLower = a.author;
    string bAuthorLower = b.author;
    transform(aAuthorLower.begin(), aAuthorLower.end(), aAuthorLower.begin(), ::tolower);
    transform(bAuthorLower.begin(), bAuthorLower.end(), bAuthorLower.begin(), ::tolower);
    return aAuthorLower < bAuthorLower;
}

bool compareByPublisher(const Book& a, const Book& b) {
    string aPublisherLower = a.publisher;
    string bPublisherLower = b.publisher;
    transform(aPublisherLower.begin(), aPublisherLower.end(), aPublisherLower.begin(), ::tolower);
    transform(bPublisherLower.begin(), bPublisherLower.end(), bPublisherLower.begin(), ::tolower);
    return aPublisherLower < bPublisherLower;
}

int main() {
    setlocale(LC_ALL, "RU");

    Book books[MAX_BOOKS] = {
        {"Война и мир", "Лев Толстой", "Эксмо", "Роман"},
        {"Преступление и наказание", "Фёдор Достоевский", "АСТ", "Роман"},
        {"1984", "Джордж Оруэлл", "Penguin", "Антиутопия"},
        {"Мастер и Маргарита", "Михаил Булгаков", "Азбука", "Роман"},
        {"Гарри Поттер и философский камень", "Джоан Роулинг", "Росмэн", "Фэнтези"},
        {"Три товарища", "Эрих Мария Ремарк", "Иностранка", "Роман"},
        {"Маленький принц", "Антуан де Сент-Экзюпери", "Эксмо", "Притча"},
        {"Анна Каренина", "Лев Толстой", "АСТ", "Роман"},
        {"Собачье сердце", "Михаил Булгаков", "Эксмо", "Повесть"},
        {"Улисс", "Джеймс Джойс", "Азбука", "Модернизм"}
    };
    int bookCount = MAX_BOOKS;

    while (true) {
        cout << "\nМеню Библиотеки:\n";
        cout << "1. Редактировать книгу\n";
        cout << "2. Печать всех книг\n";
        cout << "3. Поиск книг по автору\n";
        cout << "4. Поиск книги по названию\n";
        cout << "5. Сортировка массива по названию книг\n";
        cout << "6. Сортировка массива по автору\n";
        cout << "7. Сортировка массива по издательству\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1:
            editBook(books, bookCount);
            break;
        case 2:
            printAllBooks(books, bookCount);
            break;
        case 3:
            searchByAuthor(books, bookCount);
            break;
        case 4:
            searchByTitle(books, bookCount);
            break;
        case 5:
            sort(books, books + bookCount, compareByTitle);
            cout << "Книги отсортированы по названию.\n";
            printAllBooks(books, bookCount);
            break;
        case 6:
            sort(books, books + bookCount, compareByAuthor);
            cout << "Книги отсортированы по автору.\n";
            printAllBooks(books, bookCount);
            break;
        case 7:
            sort(books, books + bookCount, compareByPublisher);
            cout << "Книги отсортированы по издательству.\n";
            printAllBooks(books, bookCount);
            break;
        case 0:
            cout << "До свидания!\n";
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}