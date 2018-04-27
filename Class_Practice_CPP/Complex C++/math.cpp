#include "Complex.h"
#include <iostream>


int main()
{
	Complex x(5, 23);
	Complex y(9, -4);
	
	Complex z = x + y;
	Complex a = x * y;
	Complex b = x - y;
	
	cout << "z: " << z << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	
	return 0;
}
