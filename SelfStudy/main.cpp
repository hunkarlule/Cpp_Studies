#include <iostream>
using namespace std;

void func(); //global func();
int a = 10; // global variable

class X
{
public:
	void foo(int);
	void func();
private:
	int a;
};


void X::foo(int a)
{
	std::cout << a << endl;  //this a is parameter a
	std::cout << this->a << endl; // this data member a
	this->a = a + 1; // first one(on the left) is data member a and right one is parameter a.
	{
		int a = 30;
		std::cout << a << endl; //  this a is a that s defined inside the block
		std::cout << ::a << endl; // global a
		std::cout << this->a << endl; // data member a
	}

	std::cout << a << endl;  //this a is parameter a

	func(); // member function func() is called.
	::func(); // gloabl function func() is called.
}

void X::func()
{
	std::cout << "X class's func member function" << endl;
}

void func()
{
	std::cout << "Global func function" << endl;
}

int main()
{
	int a = 20;
	std::cout << a << endl;  // local a
	std::cout << ::a << endl;  // global a

	::a = 50; // global a
	a = 40; // local a

	std::cout << a << endl;  // local a
	std::cout << ::a << endl;  // global a

	X myx;
	myx.foo(a); // local a passed
	myx.foo(::a); // global a passed

	return 0;
}