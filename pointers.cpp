#include <iostream>
using namespace std;

void pass_by_value(int k){
	k = 10;
}

void pass_by_pointer(int *k){
	*k = 10; // modifies x by dereferencing pointer
	// k same as address of x
}

void pass_by_reference(int &k){
	k = 10;
}

int main(){
	int x; // type: integer
	x = 5;
	int *z; // pointer to integer
	z = &x; // stores the address of x into z
	cout << x << " " << &x << " " << z << " " << &z << endl;
	//pointer dereference
	// if z == &x then *z is the same as x itself;
	cout << "*z is: " << *z << endl;
	*z = 7; // same as: x = 7;
	z += 50000;

	x = 5;
	pass_by_value(x);
	cout << "x is: " << x << endl;
	pass_by_pointer(&x);
	cout << "x is: " << x << endl;
	pass_by_reference(x);

	int *values = new int[x];

	return 0;
}
