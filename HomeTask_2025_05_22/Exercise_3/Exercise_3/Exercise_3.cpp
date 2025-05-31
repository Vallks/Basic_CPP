#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool unik(int number) {
    int digits[4];
    for (int i = 0; i < 4; i++) {
        digits[i] = number % 10;
        number /= 10;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (digits[i] == digits[j]) {
                return true; 
            }
        }
    }

    return false; 
}

int generateNumber() {
    int number;
    do {
        number = 1000 + rand() % 9000;
    } while (unik(number));
    return number;
}

void playGame(int chisl, int popytk) {
    int res;
    cout << "Попытка " << popytk << ". Введите 4-значное число без повторяющихся цифр: ";
    cin >> res;

    if (res < 1000 || res > 9999) {
        cout << "Число должно быть 4-значным" << endl;
        playGame(chisl, popytk);
        return;
    }

    if (unik(res)) {
        cout << "Цифры не должны повторяться" << endl;
        playGame(chisl, popytk);
        return;
    }

    int bulls = 0;
    int cows = 0;
    int chislCopy = chisl;
    int resCopy = res;

    for (int i = 0; i < 4; i++) {
        if (chislCopy % 10 == resCopy % 10) {
            bulls++;
        }
        chislCopy /= 10;
        resCopy /= 10;
    }

    chislCopy = chisl;
    for (int i = 0; i < 4; i++) {
        int ugadChisl = chislCopy % 10;
        chislCopy /= 10;

        int tRes = res;
        bool found = false;
        for (int j = 0; j < 4; j++) {
            if (tRes % 10 == ugadChisl) {
                found = true;
                break;
            }
            tRes /= 10;
        }

        if (found) {
            cows++;
        }
    }
    cows -= bulls; 

    cout << "Быки - " << bulls << ", Коровы - " << cows << endl;

    if (bulls == 4) {
        cout << "Вы угадали " << chisl << " за " << popytk << " попыток.\n";
        return;
    }

    playGame(chisl, popytk + 1);
}

int main() 
{
    setlocale(LC_ALL, "RU");
    srand(time(0));
    int Number = generateNumber();

    cout << "Игра началась";

    playGame(Number, 1);

    return 0;
}