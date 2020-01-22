#pragma once
#include <iostream>
using namespace std;

class Mathematics {
private:
	int max_of_two_numbers(int number_1, int number_2) {
		if (number_1 > number_2)
			return number_1;
		else
			return number_2;
	}

	int check_for_negative_and_position(LongNumber number_1, LongNumber number_2) {
		/*
		number_1	number_2	return
		100			200			1
		200			100			2
		-100		200			3
		200			-100		4
		100			-200		5
		-200		100			6
		-100		-200		7
		-200		-100		8
		*/
		if (number_1.get_negative())
			if (number_2.get_negative())
				if (number_1.is_it_more_or_equal_modular(number_2))
					return 8;
				else
					return 7;
			else
				if (number_1.is_it_more_or_equal_modular(number_2))
					return 6;
				else
					return 3;
		else
			if (number_2.get_negative())
				if (number_1.is_it_more_or_equal_modular(number_2))
					return 4;
				else
					return 5;
			else
				if (number_1.is_it_more_or_equal_modular(number_2))
					return 2;
				else
					return 1;
	}
	
	vector <int> shift(vector<int> number_in_vector, int shift) {
		vector <int> number_in_vector_with_shift(number_in_vector.size() + shift, 0);
		for (int i = 0; i < number_in_vector.size(); i++) {
			number_in_vector_with_shift[i] = number_in_vector[i];
		}
		return number_in_vector_with_shift;
	}

	vector <int> clear_all_zeros(vector<int> number_in_vector) {
		int i = 0;
		while (number_in_vector[i] == 0 && i < number_in_vector.size() - 1) {
			i++;
		}
		vector <int> number(number_in_vector.size() - i, 0);
		for (int j = 0; j < number_in_vector.size() - i; j++)
		{
			number[j] = number_in_vector[j + i];
		}
		return number;
	}

	bool is_first_more_than_second_or_equal_modular(vector<int> number_1_in_vector, vector<int> number_2_in_vector) {
		number_1_in_vector = clear_all_zeros(number_1_in_vector);
		number_2_in_vector = clear_all_zeros(number_2_in_vector);
		bool it_more_modular_than = true;
		if (number_1_in_vector.size() != number_2_in_vector.size()) {
			if (number_1_in_vector.size() < number_2_in_vector.size()) {
				it_more_modular_than = false;
			}
		}
		else {
			for (int i = 0; i < number_1_in_vector.size(); i++) {
				if (number_1_in_vector[i] != number_2_in_vector[i]) {
					if (number_1_in_vector[i] < number_2_in_vector[i]) {
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

	vector <int> adding_two_modules_numbers_in_vectors(vector<int> number_1_in_vector, vector<int> number_2_in_vector) {
		int max_length_of_two_numbers = max_of_two_numbers(number_1_in_vector.size(), number_2_in_vector.size());
		vector <int> sum_in_vector(max_length_of_two_numbers + 1, 0);

		for (int i = 0; i < max_length_of_two_numbers; i++) {
			int i1 = (number_1_in_vector.size() - i - 1);
			int i2 = (number_2_in_vector.size() - i - 1);
			int element_from_number_1 = 0;
			int element_from_number_2 = 0;

			if (i1 >= 0)
				element_from_number_1 = number_1_in_vector[i1];
			if (i2 >= 0) {
				element_from_number_2 = number_2_in_vector[i2];
			}

			sum_in_vector[max_length_of_two_numbers - i] += element_from_number_1 + element_from_number_2;

			if (sum_in_vector[max_length_of_two_numbers - i] > 9) {
				sum_in_vector[max_length_of_two_numbers - i - 1]++;
				sum_in_vector[max_length_of_two_numbers - i] -= 10;
			}
		}
		return sum_in_vector;
	}

	vector <int> subtraction_two_modules_numbers_in_vectors(vector<int> number_1_in_vector, vector<int> number_2_in_vector) {
		int max_length_of_two_numbers = max_of_two_numbers(number_1_in_vector.size(), number_2_in_vector.size());

		vector <int> difference_in_vector(max_length_of_two_numbers, 0);
		for (int i = 0; i < max_length_of_two_numbers; i++) {
			difference_in_vector[i] = 0;
		}

		for (int i = 0; i < max_length_of_two_numbers; i++) {

			int i1 = (number_1_in_vector.size() - i - 1);
			int i2 = (number_2_in_vector.size() - i - 1);
			int element_from_number_1 = 0;
			int element_from_number_2 = 0;

			if (i1 >= 0)
				element_from_number_1 = number_1_in_vector[i1];
			if (i2 >= 0) {
				element_from_number_2 = number_2_in_vector[i2];
			}

			difference_in_vector[max_length_of_two_numbers - i - 1] += element_from_number_1 - element_from_number_2;
			if (max_length_of_two_numbers - i - 1 > 0)
				if (difference_in_vector[max_length_of_two_numbers - i - 1] < 0) {
					difference_in_vector[max_length_of_two_numbers - i - 2]--;
					difference_in_vector[max_length_of_two_numbers - i - 1] += 10;
				}
		}
		return difference_in_vector;
	}

	vector <int> multiplication_two_modules_numbers_in_vectors(vector<int> number_1_in_vector, vector<int> number_2_in_vector) {
		vector <int> composition_in_vector = { 0 };
		for (int i = 0; i < number_2_in_vector.size(); i++) {
			for (int j = 0; j < number_2_in_vector[i]; j++) {
				composition_in_vector = adding_two_modules_numbers_in_vectors(composition_in_vector, shift(number_1_in_vector, number_2_in_vector.size() - i - 1));
			}
		}
		return composition_in_vector;
	}

	vector <int> division_two_modules_numbers_in_vectors(vector<int> number_1_in_vector, vector<int> number_2_in_vector) {
		if (number_2_in_vector[0] == 0) {
			throw "Fraction = \tDivision by zero condition!";
		}
		vector <int> difference_in_vector = { 0 };
		int shift_of_number_2 = 0;
		while (is_first_more_than_second_or_equal_modular(number_1_in_vector, number_2_in_vector)) {
			while (is_first_more_than_second_or_equal_modular(number_1_in_vector, shift(number_2_in_vector, shift_of_number_2))) {
				shift_of_number_2++;
			}
			shift_of_number_2--;
			vector <int> rez = { 0 };
			while (is_first_more_than_second_or_equal_modular(number_1_in_vector, shift(number_2_in_vector, shift_of_number_2))) {					rez[0]++;
				number_1_in_vector = subtraction_two_modules_numbers_in_vectors(number_1_in_vector, shift(number_2_in_vector, shift_of_number_2));
			}
			difference_in_vector = adding_two_modules_numbers_in_vectors(difference_in_vector, shift(rez, shift_of_number_2));
			shift_of_number_2 = 0;
		}
		return difference_in_vector;
	}

	LongNumber positive_long_number(vector <int> v) {
		return LongNumber(false, v);
	}

	LongNumber negative_long_number(vector <int> v) {
		return LongNumber(true, v);
	}

public:
	bool is_it_number(string s) {
		bool contain_numbers = false;
		for (int i = 0; i < s.size(); i++) {
			if (isdigit(s[i])) {
				contain_numbers = true;
				break;
			}
		}
		if (!contain_numbers)
			return false;
	
		int i = 0;
		if (s[i] == '-')
			i++;
		for (; i < s.size(); i++)
			if (!(isdigit(s[i]) || s[i] == ','))
				return false;
		return true;
}

	LongNumber addition(LongNumber number_1, LongNumber number_2) {
		vector <int> sum_in_vector = adding_two_modules_numbers_in_vectors(number_1.get_number_in_vector(), number_2.get_number_in_vector());
		vector <int> difference_1_in_vector = subtraction_two_modules_numbers_in_vectors(number_1.get_number_in_vector(), number_2.get_number_in_vector());
		vector <int> difference_2_in_vector = subtraction_two_modules_numbers_in_vectors(number_2.get_number_in_vector(), number_1.get_number_in_vector());
		switch (check_for_negative_and_position(number_1, number_2)) {
		case 1:
		case 2:
			return positive_long_number(sum_in_vector);
		case 3:
			return positive_long_number(difference_2_in_vector);
		case 4:
			return positive_long_number(difference_1_in_vector);
		case 5:
			return negative_long_number(difference_2_in_vector);
		case 6:
			return negative_long_number(difference_1_in_vector);
		case 7:
		case 8:
			return negative_long_number(sum_in_vector);
		}
	}

	LongNumber subtraction(LongNumber number_1, LongNumber number_2) {
		vector <int> sum_in_vector = adding_two_modules_numbers_in_vectors(number_1.get_number_in_vector(), number_2.get_number_in_vector());
		vector <int> difference_1_in_vector = subtraction_two_modules_numbers_in_vectors(number_1.get_number_in_vector(), number_2.get_number_in_vector());
		vector <int> difference_2_in_vector = subtraction_two_modules_numbers_in_vectors(number_2.get_number_in_vector(), number_1.get_number_in_vector());
		switch (check_for_negative_and_position(number_1, number_2)) {
		case 1:
			return negative_long_number(difference_2_in_vector);
		case 2:
			return positive_long_number(difference_1_in_vector);
		case 3:
			return negative_long_number(sum_in_vector);
		case 4:
		case 5:
			return positive_long_number(sum_in_vector);
		case 6:
			return negative_long_number(sum_in_vector);
		case 7:
			return positive_long_number(difference_2_in_vector);
		case 8:
			return negative_long_number(difference_1_in_vector);
		}
	}

	LongNumber multiplication(LongNumber number_1, LongNumber number_2) {
		vector <int> composition_in_vector = multiplication_two_modules_numbers_in_vectors(number_1.get_number_in_vector(), number_2.get_number_in_vector());
		switch (check_for_negative_and_position(number_1, number_2)) {
		case 1:
		case 2:
		case 7:
		case 8:
			return positive_long_number(composition_in_vector);
		case 3:
		case 4:
		case 5:
		case 6:
			return negative_long_number(composition_in_vector);
		}
	}
	
	LongNumber division(LongNumber number_1, LongNumber number_2) {
		vector <int> difference_in_vector = division_two_modules_numbers_in_vectors(number_1.get_number_in_vector(), number_2.get_number_in_vector());
		switch (check_for_negative_and_position(number_1, number_2)) {
		case 2:
		case 8:
			return positive_long_number(difference_in_vector);
		case 4:
		case 6:
			return negative_long_number(difference_in_vector);
		case 1:
		case 3:
		case 5:
		case 7:
			return LongNumber("0");
		}
	}
};
