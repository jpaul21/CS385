/*******************************************************************************
 * Name        : student.cpp
 * Author      : Joshua P. Hwang
 * Date        : 9/9/2021
 * Description : Student Class
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor Code.
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Student{
public:
	//Constructor
	Student(string first, string last, float gpa, int id) :
			first_(first), last_(last), gpa_(gpa), id_(id) {}

	//Mutator (setter)
	void set_first(string first){
		first_ = first;
	}
	void set_last(string last){
		last_ = last;
	}
	void set_gpa(float gpa){
		gpa_ = gpa;
	}
	void set_id(int id){
		id_ = id;
	}

	//Accessor (getter)
	string first_name() const{
		return first_;
	}
	string last_name() const{
		return last_;
	}
	float gpa() const{
		return gpa_;
	}
	int id() const{
		return id_;
	}


	//methods
	string full_name() const{
		return (first_ + " " + last_);
	}
	void print_info() const{
		cout << full_name() << ", GPA: ";
		cout.precision(2);
		cout.setf(ios::fixed, ios::floatfield);
		cout << gpa();
		cout << ", ID: " << id();
	}

private:
	string first_, last_;
	float gpa_;
	int id_;

};

vector<Student> find_failing_students(const vector<Student> students){
		vector<Student>failing_students;
		//Iterates through the students vector, appending each student whose gpa is
		//less than 1.0 to the failing_students vector.
		for(Student i : students){
			if(i.gpa() < 1.0){
				failing_students.push_back(i);
			}
		}
		return failing_students;
	}
/**
 * Takes a vector of Student objects and prints them to the screen.
 */

void print_students(const vector<Student> &students){
	//Iterates through the students vector, calling print_info() for each student.
	for(Student i : students){
		i.print_info();
		cout << endl;
	}
}

int main() {
	string first_name, last_name;
	float gpa;
	int id;
	char repeat;
	vector<Student> students;

	do {
		cout << "Enter student's first name: ";
		cin >> first_name;
		cout << "Enter student's last name: ";
		cin >> last_name;
		gpa = -1;
		while(gpa < 0 || gpa > 4){
			cout << "Enter student's GPA (0.0-4.0): ";
			cin >> gpa;
		}
		cout << "Enter student's ID: ";
		cin >> id;
		students.push_back(Student(first_name,last_name,gpa,id));
		cout<<"Add another student to database (Y/N)? ";
		cin>>repeat;
	} while(repeat == 'Y' || repeat == 'y');

	cout << endl << "All students:" << endl;
	print_students(students);

	cout << endl << "Failing students:";
	//TODO
	//Print a space and the word 'None' on the same line if no students are
	//failing.
	//Otherwise, print each failing student on a separate line.
	if (find_failing_students(students).size() == 0){
		cout << " None" << endl;
	} else {
		cout << endl;
		print_students(find_failing_students(students));
	}
	return 0;

}
