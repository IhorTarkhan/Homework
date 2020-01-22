#pragma once
#include <iostream>
using namespace std;

struct Square {
private:
	Point p1 = Point(0, 0);
	Point p2 = Point(0, 0);
	Point p3 = Point(0, 0);
	Point p4 = Point(0, 0);

public:
	Square(Point p1_0, Point p2_0, Point p3_0, Point p4_0) {
		p1 = p1_0;
		p2 = p2_0;
		p3 = p3_0;
		p4 = p4_0;
	}

	int get_area() {
		return pow(Segment(p1, p2).getLenght(), 2);
	}

	string toString() {
		return p1.toString() + "\n" + p2.toString() + "\n" + p3.toString() + "\n" + p4.toString();
	}
};
