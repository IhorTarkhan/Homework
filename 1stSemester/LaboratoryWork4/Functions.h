#pragma once
#include <iostream>
using namespace std;

double exp(double x, double eps) {
	double rez = 0.0;
	double delta = 1.0;
	int n = 1;
	do {
		rez += delta;
		delta = delta * x / n;
		n++;
	} while (delta > eps);
	cout << n << " ";
	return rez;
}

double sh(double x, double eps) {
	double rez = 0.0;
	double delta = x;
	int n = 3;
	do {
		rez += delta;
		delta = delta * x * x / (n * (n - 1));
		n = n + 2;
	} while (delta > eps);
	cout << (n - 3) / 2 << " ";
	return rez;
}
