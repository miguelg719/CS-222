#include <iostream>

using namespace std;

void stuff(double a, int b)
{
	cout << "Yo!" << endl;
}

void stuff(int a, double b)
{
	cout << "Hey!" << endl;
}

int main()
{
	cout << "Hello, world!" << endl;
	
	stuff(3, 4.5);
	stuff(1.1, 1);
	
	return 0;
}
