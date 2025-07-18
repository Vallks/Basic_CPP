#include <iostream>
using namespace std;

struct Complex
{
	double real; 
	double imag;
};

Complex addComplex(const Complex& a, const Complex& b) 
{
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subComplex(const Complex& a, const Complex& b) 
{
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex multComplex(const Complex& a, const Complex& b) 
{
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex divideComplex(const Complex& a, const Complex& b) 
{
    Complex result;
    double del = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / del;
    result.imag = (a.imag * b.real - a.real * b.imag) / del;
    return result;
}

void printComplex(const Complex& c) 
{
    cout << "(" << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i)";
    return;
}

int main()
{
    setlocale(LC_ALL, "RU");
    Complex a, b;
    cout << "Введите действительную часть первого числа" << '\n';
    cin >> a.real;
    cout << "Введите мнимую часть первого числа" << '\n';
    cin >> a.imag;

    cout << "Введите действительную часть второго числа" << '\n';
    cin >> b.real;
    cout << "Введите мнимую часть второго числа" << '\n';
    cin >> b.imag;

    cout << "Сумма ";
    printComplex(addComplex(a, b));
    cout << endl;

    cout << "Разность ";
    printComplex(subComplex(a, b));
    cout << endl;

    cout << "Произведение ";
    printComplex(multComplex(a, b));
    cout << endl;

    cout << "Частное ";
    printComplex(divideComplex(a, b));
    cout << endl;

    return 0;
}
