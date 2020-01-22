#pragma once
#include <iostream>
using namespace std;

class LongNumber {
private:
	bool negative = false;
	vector <int> number_in_vector;

	string convert_int_to_string(int number_in_int) {
		string number_in_string;
		stringstream number_in_smth;
		number_in_smth << number_in_int;
		number_in_smth >> number_in_string;
		return number_in_string;
	}

	string clear_all_comas(string number_with_comas) {
		string to_return = "";
		for (int i = 0; i < number_with_comas.length(); i++) {
			if (number_with_comas[i] != ',') {
				to_return += number_with_comas[i];
			}
		}
		return to_return;
	}

	string clear_all_zeros(string number_with_zeros) {
		string number = "";
		int i = 0;
		if (number_with_zeros[0] == '-') {
			number += number_with_zeros[0];
			i = 1;
		}
		while (number_with_zeros[i] == '0' && i != number_with_zeros.length() - 1) {
			i++;
		}
		number += number_with_zeros.substr(i, number_with_zeros.length());
		return number;
	}

	void set_negative(string number) {
		if (number[0] == '-') {
			negative = true;
		}
	}

	void convert_string_to_vector(string number) {

		if (number[0] == '-') {
			number = number.substr(1, number.length());
		}
		int string_length = number.length();
		vector <int> new_number_in_vector(string_length, 0);
		number_in_vector = new_number_in_vector;
		for (int i = 0; i < string_length; i++) {
			number_in_vector[string_length - i - 1] = number[string_length - i - 1] - '0';
		}
	}

public:
	LongNumber(string number) {
		number = clear_all_comas(number);
		number = clear_all_zeros(number);
		set_negative(number);
		convert_string_to_vector(number);
	}

	LongNumber(bool this_negative, vector <int> this_number_in_vector) {
		negative = this_negative;

		int i = 0;
		while (this_number_in_vector[i] == 0 && i != this_number_in_vector.size() - 1) {
			i++;
		}
		int shift = i;
		vector <int> new_number_in_vector(this_number_in_vector.size() - shift, 0);
		number_in_vector = new_number_in_vector;
		for (; i < this_number_in_vector.size(); i++) {
			number_in_vector[i - shift] = this_number_in_vector[i];
		}
	}

	bool get_negative() {
		return negative;
	}

	vector <int> get_number_in_vector() {
		return number_in_vector;
	}

	bool is_it_more_or_equal_modular(LongNumber number_2) {
		bool it_more_modular_than = true;
		vector <int> number_2_in_vector = number_2.get_number_in_vector();
		if (number_in_vector.size() != number_2_in_vector.size()) {
			if (number_in_vector.size() < number_2_in_vector.size()) {
				it_more_modular_than = false;
			}
		}
		else {
			for (int i = 0; i < number_in_vector.size(); i++) {
				if (number_in_vector[i] != number_2_in_vector[i]) {
					if (number_in_vector[i] < number_2_in_vector[i]) {
						it_more_modular_than = false;
						break;
					}
					else {
						break;
					}
				}
			}
		}
		return it_more_modular_than;
	}

	string print() {
		if (number_in_vector[0] == 0)
			return "0";
		string to_print = "";
		if (negative) {
			to_print += "-";
		}
		int when_coma = number_in_vector.size() % 3;
		for (int i = 0; i < number_in_vector.size(); i++) {
			if (when_coma == 0) {
				if (i == 0) {
					when_coma = 3;
				}
				else {
					to_print += ",";
					when_coma = 3;
				}
			}
			to_print += convert_int_to_string(number_in_vector[i]);
			when_coma--;
		}
		return to_print;
	}
};
