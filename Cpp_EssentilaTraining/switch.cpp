
#include <iostream>

using std::cout;

int main() {
	const auto ONE = 1;
	const auto TWO = 2;
	const auto THREE = 3;
	const auto FOUR = 4;

	int x{ 3 };
	// here matchin case will be evaluated if non of them is matched then defautl will be evaluated.
	// in this case x = 3 so case THREE: will be executed and swithc will be exited at point becuase we have break; statment there.
	switch (x) {
	case ONE:
		cout << "one\n";
		break;
	case TWO:
		cout << "two\n";
		break;
	case THREE:
		cout << "three\n";
		break;
	case FOUR:
		cout << "four\n";
		break;
	default:
		cout << "default\n";
		break;
	}

	cout << "after1\n";

	switch (x) {
	case ONE:
		cout << "one\n";
		break;
	case TWO:
		cout << "two\n";
		break;
	case THREE: //  x = 3 so this case will be evaluated. it will print " three". however, becuase break stament is commmented-out
		// it will excaute the remaining cases until it sees a " break" statement. this is called imlicit fall-through.
		cout << "three\n";
		//break; // if break is not used the flow of swithc fall throuh until it finds a break  statement. be careful about this!.
	case FOUR: // this will also be eecuted(even if x  is not 4) becuase the break  is commented above.
		cout << "four\n";
		break;
	default:
		cout << "default\n";
		break;
	}

	cout << "after2\n";


	switch (x) {
	case ONE:
		cout << "one\n";
		break;
	case TWO:
		cout << "two\n";
		break;
	case THREE:
		cout << "three\n";
		//break;  // instead of this imlicit fall-through. use explicit fall-through to show your intent(means you  are doing it on purpose)
		[[fallthrough]]; // here we made the fall-throuh explicit.
	case FOUR:
		cout << "four\n";
		break;
	default:
		cout << "default\n";
		break;
	}

	cout << "after3\n";


	x = 1;
	switch (x) {
	case ONE: // here we arejoining cases one and two. so if x = 1 or x =2 same part will be executed.
	case TWO:
		cout << "two or one\n";
		break;
	case THREE:
		cout << "three\n";
		//break;  // instead of this imlicit fall-through. use explicit fall-through to show your intent(means you  are doing it on purpose)
		[[fallthrough]]; // here we made the fall-throuh explicit.
	case FOUR:
		cout << "four\n";
		break;
	default:
		cout << "default\n";
		break;
	}

	cout << "after4\n";


	x = 8; // this will cause the default case to be evaluated. because non of the cases  match this.;
	switch (x) {
	case ONE: // here we arejoining cases one and two. so if x = 1 or x = 2 same part will be executed.
	case TWO:
		cout << "two or one\n";
		break;
	case THREE:
		cout << "three\n";
		//break;  // instead of this imlicit fall-through. use explicit fall-through to show your intent(means you  are doing it on purpose)
		[[fallthrough]]; // here we made the fall-throuh explicit.
	case FOUR:
		cout << "four\n";
		break;
	default:
		cout << "default\n";
		break;
	}

	cout << "after5\n";
}
