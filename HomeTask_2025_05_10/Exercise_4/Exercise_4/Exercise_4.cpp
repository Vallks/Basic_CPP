#include <iostream> //Половину своровал в инете со стринга переделал в чар, Русский ввод не смог прикрутить пока не хватило времени на выходных.
using namespace std;

void myFunk(int dost, char mast) {
    if (dost < 1 || dost > 13) {
        cout << "Достоинство должно быть от 1 до 13" << endl;
        return;
    }

    if (mast != 'H' && mast != 'D' && mast != 'C' && mast != 'S') {
        cout << "Неправильная масть (H, D, C, S)" << endl;
        return;
    }

    char znakDost[3] = " "; 
    if (dost == 1) znakDost[0] = 'Т';
    else if (dost >= 2 && dost <= 9) znakDost[0] = '0' + dost;
    else if (dost == 10) { znakDost[0] = '1'; znakDost[1] = '0'; }
    else if (dost == 11) znakDost[0] = 'В';
    else if (dost == 12) znakDost[0] = 'Д';
    else if (dost == 13) znakDost[0] = 'К';

    char mastSymbol;
    switch (mast) {
    case 'H': mastSymbol = 'Ч'; break;
    case 'D': mastSymbol = 'Б'; break;
    case 'C': mastSymbol = 'К'; break;
    case 'S': mastSymbol = 'П'; break;
    }

    bool isTen = (dost == 10);

    cout << "+-----+" << endl;
    cout << "|" << znakDost << (isTen ? "" : " ") << "   |" << endl;
    cout << "|  " << mastSymbol << "  |" << endl;
    if (isTen) {
        cout << "|   " << znakDost << "|" << endl;
    }
    else {
        cout << "|   " << (isTen ? "" : " ")  << znakDost[0] << "|" << endl;
    }
    cout << "+-----+" << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int dost;
    char mast;
    cout << "Введите номенал карты от 1 до 13 ";
    cin >> dost;
    cout << "Введите масть (H, D, C, S) ";
    cin >> mast;
    myFunk(dost, mast);
    return 0;
}