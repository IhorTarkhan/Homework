#pragma once
#include <iostream>
using namespace std;

struct Segment {
private:
	Point p1 = Point(0, 0);
	Point p2 = Point(0, 0);

public:
	Segment(Point p1_0, Point p2_0) {
		p1 = p1_0;
		p2 = p2_0;
	}

	int lenght_X() {
		return p2.get_X() - p1.get_X();
	}

	int lenght_Y() {
		return p2.get_Y() - p1.get_Y();
	}

	double getLenght() {
		return sqrt(pow(p1.get_X() - p2.get_X(), 2) + pow(p1.get_Y() - p2.get_Y(), 2));
	}

	Point get_Point_1() {
		return p1;
	}

	Point get_Point_2() {
		return p2;
	}
};
