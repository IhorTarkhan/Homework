#pragma once
#include <iostream>
using namespace std;

struct Point {
private:
	int x = 0;
	int y = 0;

	string convert_int_to_string(int number_in_int) {
		string number_in_string;
		stringstream number_in_smth;
		number_in_smth << number_in_int;
		number_in_smth >> number_in_string;
		return number_in_string;
	}

public:
	Point(int x0, int y0) {
		x = x0;
		y = y0;
	}

	int get_X() {
		return x;
	}

	int get_Y() {
		return y;
	}

	string toString() {
		return "(" + convert_int_to_string(x) + "; " + convert_int_to_string(y) + ")";
	}
};
