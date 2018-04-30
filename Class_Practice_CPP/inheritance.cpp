#include <iostream>

using namespace std;

class A
{
public: 
	virtual void print()
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public: 
	void print()
	{
		cout << "B" << endl;
	}
};

int main()
{
	A a;
	B b;
	A* p;
	
	cout << "Size of A: " << sizeof(A) << endl;
	a.print();
	b.print();
	
	p = &a;
	p->print();
	p = &b;
	p->print();
	
	B* q = &b;
	q->print();
	
	
	
	return 0;
}
