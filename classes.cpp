#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class MyPoint{
public:
	//constructor that uses an initializer list.
	MyPoint(int x, int y, float z) : x_{x}, y_{y}, z_{z} { }

	//const promises to not modify member variables.
	void print_corrds() const {
		cout << "(x, y, z) = (" << x_ << ", " << y_ << ", " << fixed
				<< setprecision(2) << z_ << ")" << endl;
	}
private:
	int x_, y_;
	float z_;
};

//Pass by reference, and using an iterator (which is an object
//that can be used essentially as if it were a pointer):
void display_points(const vector<MyPoint> &points){
	for(auto it = points.cbegin(); it!= points.cend(); it++){
		it->print_coords(); //Same as: (*it).print_coords();
	}
}

void display_points_v2(const vector<MyPoint> &points){
	for(size_t i = 0; i < points.size(); i++){
		points[i].print_coords();
	}
}

int main(){
	int x, y;

	//Objects allocated on the stack:
	MyPoint point1(5, 7, 1.9823412);
	MyPoint point2(1, 2, 3);
	MyPoint point3(4, 5, 6);
	point2.print_coords();

	vector<MyPoint> points;
	points.push_back(point1);
	points.push_back(point2);
	points.push_back(point3);

	vector<MyPoint> points_above_two;
	//For-each loop (using a reference so there is no copy):
	for(const auto &point : points){
	//& uses references; new name for something that already exists
		if(point.get_x() > 2){
			points_above_two.push_back(point);
		}
	}
	display_points(points_above_two);

	cout << "Input x: ";
	cin >> x;

	cout << "input y: ";
	cin >> y;

	//Object allocated on the heap:
	MyPoint *point4 = new MyPoint(x, y, 7); // address is stored in pointer
	//Calling the method using the pointer to the object.
	point4->print_coords(); // same as: (*point4).print_coords();
	delete point4;

	return 0;
}
