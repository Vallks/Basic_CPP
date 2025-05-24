#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void initMas(int ar[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		ar[i] = rand();
	}
}

void printMas(int ar[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << ar[i] << " ";
	}
}

void bSort(int ar[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (ar[j] > ar[j + 1]) {
				int temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
		}
	}
}

int bSearch(int ar[], int size, int znc) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (ar[mid] == znc) {
			return mid;
		}
		else if (ar[mid] < znc) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1; 
}

int main()
{
	setlocale(LC_ALL, "RU");

	const int size = 10;
	srand(time(NULL));
	int ar[size];
	int znc;

	initMas(ar, size);
	bSort(ar, size);
	printMas(ar, size);

	cout << endl << "Введите значение для поиска ";
	cin >> znc;

	int res = bSearch(ar, size, znc);
	if (res == -1)
	{
		cout << "Не найдено!";
	}
	else
	{
		cout << "Индекс = " << res;
	}
	return 0;
}