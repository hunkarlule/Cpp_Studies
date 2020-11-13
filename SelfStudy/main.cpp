#include <iostream>
using namespace std;
class X
{
public:
	void display();
	void set(int);
private:
	int a;
};


void X::set(int val)
{
	cout << "X::set() called" << endl;
	cout << "this = " << this << endl;
	a = val;
}

void X::display()
{
	cout << "X::display() called!" << endl;
	cout << "this= " << this << endl;
	cout << "a = " << a << endl;
}

int main()
{
	X myx;
	cout << "&myx = " << &myx << endl;
	myx.set(10);
	myx.display();

	X* ptr = &myx;

	ptr->display();

	return 0;
}