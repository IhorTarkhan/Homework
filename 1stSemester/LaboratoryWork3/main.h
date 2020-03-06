#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include "Point.h"
#include "Segment.h"
#include "Square.h"
using namespace std;

inline bool is_to_point_equil(Point p1, Point p2) {
	if (p1.get_X() == p2.get_X() && p1.get_Y() == p2.get_Y())
		return true;
	return false;
}

inline Square get_square_from_4_segments(Segment s1, Segment s2, Segment s3, Segment s4) {
	vector <Point> square_in_points;
	square_in_points.push_back(s1.get_Point_1());
	square_in_points.push_back(s1.get_Point_2());
	bool b;
	b = true;
	for (int i = 0; i < square_in_points.size(); i++) {
		if (is_to_point_equil(s2.get_Point_1(), square_in_points[i])) {
			b = false;
			break;
		}
	}
	if (b) square_in_points.push_back(s2.get_Point_1());

	b = true;
	for (int i = 0; i < square_in_points.size(); i++) {
		if (is_to_point_equil(s2.get_Point_2(), square_in_points[i])) {
			b = false;
			break;
		}
	}
	if (b) square_in_points.push_back(s2.get_Point_2());

	b = true;
	for (int i = 0; i < square_in_points.size(); i++) {
		if (is_to_point_equil(s3.get_Point_1(), square_in_points[i])) {
			b = false;
			break;
		}
	}
	if (b) square_in_points.push_back(s3.get_Point_1());

	b = true;
	for (int i = 0; i < square_in_points.size(); i++) {
		if (is_to_point_equil(s3.get_Point_2(), square_in_points[i])) {
			b = false;
			break;
		}
	}
	if (b) square_in_points.push_back(s3.get_Point_2());

	b = true;
	for (int i = 0; i < square_in_points.size(); i++) {
		if (is_to_point_equil(s4.get_Point_1(), square_in_points[i])) {
			b = false;
			break;
		}
	}
	if (b) square_in_points.push_back(s4.get_Point_1());

	b = true;
	for (int i = 0; i < square_in_points.size(); i++) {
		if (is_to_point_equil(s4.get_Point_2(), square_in_points[i])) {
			b = false;
			break;
		}
	}
	if (b) square_in_points.push_back(s4.get_Point_2());

	return Square(square_in_points[0], square_in_points[1], square_in_points[2], square_in_points[3]);
}

inline bool is_perpendicular(Segment s1, Segment s2) {
	if (s1.lenght_X() * s2.lenght_X() + s1.lenght_Y() * s2.lenght_Y() == 0)
		return true;
	return false;
}

inline bool is_equal(Segment s1, Segment s2) {
	if (s1.getLenght() == s2.getLenght())
		return true;
	return false;
}

inline bool is_rectangle(Segment s1, Segment s2, Segment s3, Segment s4) {
	if (is_perpendicular(s1, s2) && is_perpendicular(s1, s3) && is_perpendicular(s4, s2) && is_perpendicular(s4, s3))
		return true;
	if (is_perpendicular(s1, s3) && is_perpendicular(s1, s4) && is_perpendicular(s2, s3) && is_perpendicular(s2, s4))
		return true;
	if (is_perpendicular(s1, s4) && is_perpendicular(s1, s2) && is_perpendicular(s1, s4) && is_perpendicular(s1, s2))
		return true;
	return false;
}

int main_Lab_1_3() {
	int n;
	cin >> n;

	vector <Point> vector_of_Points;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vector_of_Points.push_back(Point(x, y));
	}

	vector <Segment> vector_of_Segments;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			vector_of_Segments.push_back(Segment(vector_of_Points[i], vector_of_Points[j]));
		}
	}

	n = vector_of_Segments.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (vector_of_Segments[j].getLenght() > vector_of_Segments[j + 1].getLenght()) {
				Segment swap = vector_of_Segments[j + 1];
				vector_of_Segments[j + 1] = vector_of_Segments[j];
				vector_of_Segments[j] = swap;
			}
		}
	}

	vector <Square> vector_of_Squares;
	for (int i = 0; i < n - 3; i++) {
		if (is_equal(vector_of_Segments[i], vector_of_Segments[i + 1]) && is_equal(vector_of_Segments[i + 1], vector_of_Segments[i + 2]) && is_equal(vector_of_Segments[i + 2], vector_of_Segments[i + 3])) {
			if (is_rectangle(vector_of_Segments[i], vector_of_Segments[i + 1], vector_of_Segments[i + 2], vector_of_Segments[i + 3])) {
				vector_of_Squares.push_back(get_square_from_4_segments(vector_of_Segments[i], vector_of_Segments[i + 1], vector_of_Segments[i + 2], vector_of_Segments[i + 3]));
			}
		}
	}
	Square s1 = Square(Point(vector_of_Points[0]), Point(vector_of_Points[0]), Point(vector_of_Points[0]), Point(vector_of_Points[0]));
	for (int i = 1; i < vector_of_Squares.size(); i++) {
		if (vector_of_Squares[i].get_area() > s1.get_area())
			s1 = vector_of_Squares[i];
	}

	cout << endl << s1.toString();
    return 0;
}
