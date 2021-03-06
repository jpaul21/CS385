<<<<<<< HEAD
/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Joshua P. Hwang
 * Date        : 9/25/2021
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
	vector< vector<int> > ways;
	vector<int> holder;
	if(num_stairs == 1){
		return ways;
	}
	int temp = num_stairs;
	for(int i = temp; i > 0; i--){
		if(i >= 3){
			holder.push_back(3);
			i -= 2;
		}
		else if(i == 2){
			holder.push_back(2);
			i -= 1;
		} else holder.push_back(1);
	}
	return ways;
}

void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.
	int length = ways.size();
	int digits = 0;
	while(length /= 10 > 0){
		digits++;
	}
	vector<int> temp;
	for(auto i = ways.cbegin(); i != ways.cend(); ++i){
		temp = *i;
		cout << setw(digits);
		cout << i << ". " << "[";
		for(auto j = temp.cbegin(); j != temp.cend(); ++j){
			cout << *j;
			if(j != temp.cend()){
				cout << ", ";
			}
		}
		cout << "]" << endl;
	}
}

int main(int argc, char * const argv[]) {
	if(argc != 2 || (*argv[1]) < 1){
		cout << "Error: Number of stairs must be a positive integer.";
	}
	vector<vector<int>> way = get_ways(*argv[1]);
	display_ways(way);
	return 0;
}
=======
/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Joshua P. Hwang
 * Date        : 9/25/2021
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
	vector< vector<int> > ways;
	vector<int> holder;
	if(num_stairs == 1){
		return ways;
	}
	int temp = num_stairs;
	for(int i = temp; i > 0; i--){
		if(i >= 3){
			holder.push_back(3);
			i -= 2;
		}
		else if(i == 2){
			holder.push_back(2);
			i -= 1;
		} else holder.push_back(1);
	}
	return ways;
}

void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.
	int length = ways.size();
	int digits = 1;
	while(length /= 10 > 0){
		digits++;
	}
	vector<int> temp;
	if(ways.size() == 1){
		cout << "1 way to climb 1 stair.";
	} else cout << 2*ways.size() << " ways to climb " << ways.size() << " stairs.";
	for(int i = 0; i < length; ++i){
		temp = ways[i];
		cout << setw(digits);
		cout << i << ". " << "[";
		for(int j = 0; j < temp.size(); ++j){
			cout << j;
			if(j != temp.size()){
				cout << ", ";
			}
		}
		cout << "]" << endl;
	}
}

int main(int argc, char * const argv[]) {
	if(argc != 2){
		cout << "Usage: ./stairclimber <number of stairs>";
		return 0;
	}
	int num;
	istringstream iss;
	iss.str(argv[1]);
	if(!(iss >> num)){
		cout <<"Error: Number of stairs must be a positive integer."; 
		return 0;
	}

	if(num < 1){
		cout << "Error: Number of stairs must be a positive integer.";
		return 0;
	}
	vector< vector<int> > way = get_ways(num);
	display_ways(way);
	return 0;
}
>>>>>>> 0acfeca0f8335789845a8aed0891a62d2400dfb2
