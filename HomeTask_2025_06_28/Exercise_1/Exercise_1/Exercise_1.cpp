#include <iostream>
using namespace std;

void initArr(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i * i;
	}
	return;
}

void printArr(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << '\n';
	return;
}

int main()
{
	setlocale(LC_ALL, "RU");

	unsigned int size;
	cout << "Введите размер массива: ";
	cin >> size;

	int* arr = new int[size];
	initArr(arr, size);
	printArr(arr, size);

	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	cout << sum;
	delete[] arr;
	return 0;
}

