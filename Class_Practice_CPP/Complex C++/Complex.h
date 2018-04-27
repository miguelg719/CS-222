#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex
{
	double real;
	double imaginary;
	
public:
	Complex(double realValue = 0, double imaginaryValue = 0);
	~Complex(void);
	
	double getReal();
	double getImaginary();
	Complex& operator=(const Complex& complex);
	Complex operator+(const Complex& complex) const;
	Complex operator-(const Complex& complex) const;
	Complex operator-() const;
	Complex operator*(const Complex& complex) const;
	
	friend ostream& operator<<(ostream& out, const Complex& complex);
};


#endif
