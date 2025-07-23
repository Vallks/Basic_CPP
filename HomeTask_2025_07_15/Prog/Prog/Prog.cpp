#include<iostream>
#include<stdlib.h>
#include <time.h>
#include <string>
#define N 10
#define INTEGER
#define DOUBLE
#define STRING
#include "function.h"

using namespace std;

int main()
{

#undef DOUBLE
#undef STRING
#ifdef INTEGER
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int ptr[N];
	RandomNumberInteger(ptr, N);
	PrintInteger(ptr, N);
	cout << " Минимальное число из массива \t" << MinInteger(ptr, N) << endl;
	cout << " Максимальное число из массива \t" << MaxInteger(ptr, N) << endl;
	sortInteger(ptr, N);
	PrintInteger(ptr, N);
	editInteger(ptr, N);
	PrintInteger(ptr, N);
	cout << endl;
#endif
#undef INTEGER
#define	DOUBLE
#ifdef DOUBLE
	double doubleptr[N];
	RandomNumberInteger(doubleptr, N);
	PrintInteger(doubleptr, N);
	cout << " Минимальное число из массива \t" << MinIntegerD(doubleptr, N) << endl;
	cout << " Максимальное число из массива \t" << MaxInteger(doubleptr, N) << endl;
	sortInteger(doubleptr, N);
	PrintInteger(doubleptr, N);
	editInteger(doubleptr, N);
	PrintInteger(doubleptr, N);
	cout << endl;
#endif 
#undef DOUBLE
#define STRING
#ifdef STRING	
	string stringptr[N];
	RandomNumberInteger(stringptr, N);
	PrintInteger(stringptr, N);
	cout << " Минимальное число из массива \t" << MinInteger(stringptr, N) << endl;
	cout << " Максимальное число из массива \t" << MaxInteger(stringptr, N) << endl;
	sortInteger(stringptr, N);
	PrintInteger(stringptr, N);
	editInteger(stringptr, N);
	PrintInteger(stringptr, N);
#endif  
	return 0;
}