#pragma once
#include<iostream>
using namespace std;

#ifdef INTEGER
void RandomNumber(int* ptr, const int size);
void Print(int* ptr, const int size);
int Max(int* ptr, const int size);
int Min(int* ptr, const int size);
void sort(int* ptr, const int size);
void edit(int* ptr, const int size);
#define RandomNumberInteger RandomNumber
#define PrintInteger Print
#define MinInteger Min
#define MaxInteger Max
#define sortInteger sort
#define editInteger edit
#endif

#ifdef DOUBLE
void RandomNumber(double* ptr, const int size);
void Print(double* ptr, const int size);
double Max(double* ptr, const int size);
double Min(double* ptr, const int size);
void sort(double* ptr, const int size);
void edit(double* ptr, const int size);
#define RandomNumberInteger RandomNumber
#define PrintInteger Print
#define MinIntegerD Min
#define MaxIntegerD Max
#define sortInteger sort
#define editInteger edit
#endif

#ifdef STRING
void RandomNumber(string* ptr, const int size);
void Print(string* ptr, const int size);
string Max(string* ptr, const int size);
string Min(string* ptr, const int size);
void sort(string* ptr, const int size);
void edit(string* ptr, const int size);
#define RandomNumberInteger RandomNumber
#define PrintInteger Print
#define MinInteger Min
#define MaxInteger Max
#define sortInteger sort
#define editInteger edit
#endif