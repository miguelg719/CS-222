#include "Complex.h"

Complex::Complex(double realValue, double imaginaryValue)
{
	real = realValue;
	imaginary = imaginaryValue;
}

Complex::~Complex(void)
{
}

double Complex::getReal()
{
	return real;
}

double Complex::getImaginary()
{
	return imaginary;
}

Complex& Complex::operator=(const Complex& complex)
{
	real = complex.real;
	imaginary = complex.imaginary;
	
	return *this;
}

Complex Complex::operator+(const Complex& complex) const
{
	Complex c;
	c.real = real + complex.real;
	c.imaginary = imaginary + complex.imaginary;
	return c;		
}

Complex Complex::operator-(const Complex& complex) const
{
	Complex c;
	c.real = real - complex.real;
	c.imaginary = imaginary - complex.imaginary;
	return c;	
}

Complex Complex::operator-() const
{
	Complex c;
	c.real = -real;
	c.imaginary = -imaginary;	
	return c;
}

Complex Complex::operator*(const Complex& complex) const
{
	Complex c;
	c.real = real * complex.real - imaginary * complex.imaginary;
	c.imaginary = real * complex.imaginary + imaginary * complex.real;
	return c;
}

ostream& operator<<(ostream& out, const Complex& complex)
{
	out << complex.real << " + " << complex.imaginary << "i";
	return out;
}
