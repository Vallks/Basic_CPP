#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	const int MAX_CONTACTS = 100;

	long long mobileNumbers[MAX_CONTACTS];
	long long homeNumbers[MAX_CONTACTS];
	int contactCount = 0;

    mobileNumbers[contactCount] = 89151234567;
    homeNumbers[contactCount] = 51046;
    contactCount++;

    mobileNumbers[contactCount] = 89031112233;
    homeNumbers[contactCount] = 49182;
    contactCount++;

    mobileNumbers[contactCount] = 89267778899;
    homeNumbers[contactCount] = 12345;
    contactCount++;

    int choice;
    do {
        cout << "Меню справочника:\n";
        cout << "1. Отсортировать по мобильным номерам\n";
        cout << "2. Отсортировать по домашним номерам\n";
        cout << "3. Вывести все контакты\n";
        cout << "4. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < contactCount - 1; i++) {
                for (int j = 0; j < contactCount - i - 1; j++) {
                    if (mobileNumbers[j] > mobileNumbers[j + 1]) {
                        swap(mobileNumbers[j], mobileNumbers[j + 1]);
                        swap(homeNumbers[j], homeNumbers[j + 1]);
                    }
                }
            }
            cout << "Контакты отсортированы по мобильным номерам.\n";
            break;

        case 2:
            for (int i = 0; i < contactCount - 1; i++) {
                for (int j = 0; j < contactCount - i - 1; j++) {
                    if (homeNumbers[j] > homeNumbers[j + 1]) {
                        swap(homeNumbers[j], homeNumbers[j + 1]);
                        swap(mobileNumbers[j], mobileNumbers[j + 1]);
                    }
                }
            }
            cout << "Контакты отсортированы по домашним номерам.\n";
            break;

        case 3:
            cout << "Контакты:\n";
            cout << "№\tМобильный\tДомашний\n";
            for (int i = 0; i < contactCount; i++) {
                cout << i + 1 << "\t" << mobileNumbers[i] << "\t" << homeNumbers[i] << endl;
            }
            break;

        case 4:
            break;

        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 4);


    return 0;
}
