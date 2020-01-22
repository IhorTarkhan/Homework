#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "LongNumber.h"
#include "Mathematics.h"
using namespace std;

int main_Lab_1_2() {
	Mathematics calculator = Mathematics();
	string s1;
	string s2;
	LongNumber n1 = LongNumber("0");
	LongNumber n2 = LongNumber("0");

	bool s1_is_correct_number = false;

	while (true) {
		if (s1_is_correct_number) {
			cout << "number_1 = \t" << s1 << endl;
		}
		else {
			cout << "number_1 = \t";
			cin >> s1;
			if (s1 == "exit") { break; }
			if (!calculator.is_it_number(s1)) {
				cout << "Incorect number!" << endl << "------------------------------------------------------------------" << endl;
				continue;
			}
			s1_is_correct_number = true;
		}

		cout << "number_2 = \t";
		cin >> s2;
		if (s2 == "exit") { break; }
		if (!calculator.is_it_number(s2)) {
			cout << "Incorect number!" << endl << "------------------------------------------------------------------" << endl;
			continue;
		}

		n1 = LongNumber(s1);
		n2 = LongNumber(s2);
		cout << endl;
		cout << "Sum = \t\t" << calculator.addition(n1, n2).print() << endl;
		cout << "Difference = \t" << calculator.subtraction(n1, n2).print() << endl;
		cout << "Product = \t" << calculator.multiplication(n1, n2).print() << endl;
		try {
			cout << "Fraction = \t" << calculator.division(n1, n2).print() << endl;
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
		cout << "------------------------------------------------------------------" << endl;
		s1_is_correct_number = false;
	}
	cout << endl << "Thanks! Goodbye!" << endl;
	return 0;
}
