#include <iostream>
using namespace std;

void func(); //global func();


class X
{
public:
	void foo(int);
	void func();
private:
	int a;
};


void X::foo(int x)
{
	a = x; //this a is parameter a
	{
		int a = 30;
		cout << a << endl; //  this a is a that s defined inside the block
	}

	cout << a << endl;  //this a is parameter a

	func(); // this call is member function func().
}

void X::func()
{
	cout << "X class's func member function" << endl;
}

void func()
{
	cout << "Global func function" << endl;
}

int main()
{
	X myx;
	myx.foo(10);

	return 0;
}