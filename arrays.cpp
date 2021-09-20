#include <iostream>
using namespace std;

void display_array(int array[], int length){
	for(int i = 0; i < length; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

void display_array_ptr(int *array, int length){
	for(int *p = array; p < array + length; p++){			//p increments by size of array
		cout << *p << " ";
	}
	cout << endl;
}

int main(){
	int x = 10;
	int *values = new int[x];
	for(int i = 0; i < x; i++){
		*(values + i) = i;
		values[i] = i;
	}
	display_array(values, x);
	display_array_ptr(values, x);

	delete [] values; //deallocate memory of array

}
