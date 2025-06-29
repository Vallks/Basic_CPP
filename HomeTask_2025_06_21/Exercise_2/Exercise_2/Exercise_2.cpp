#include <iostream>
#include <cstring>
#include <cctype> 
using namespace std;

void myFunk(char* str)
{
	int res = 0;
	bool flag = false;

	for (int i = 0; str[i] != '\0'; i++) {
		if (isspace(str[i])) {
			flag = false;
		}
		else if (!flag) {
			flag = true;
			res++;
		}
	}

	cout << res << " слов";
	return;
}

int main()
{
	setlocale(LC_ALL, "RU");

	const int SIZE = 256;
	char str[SIZE];
	int indx;

	cout << "Введите строку: ";
	cin.getline(str, SIZE);

	myFunk(str);

	return 0;
}