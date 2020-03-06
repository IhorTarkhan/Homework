#include <iostream>
#include <math.h>
using namespace std;

inline int numberOf1Calculun2(int number) {
	int numberOf1 = 0;
	while (number != 0) {
		if (number % 2)
			numberOf1++;
		number = number / 2;
	}
	return numberOf1;
}

int main_Lab_1_1() {
	int n;
	cin >> n;
	int numberReturn = 1;
	int numberReturnNOf1 = numberOf1Calculun2(numberReturn);
	for (int i = 0; i <= n; i++) {
		if (numberOf1Calculun2(i) > numberReturnNOf1) {
			numberReturn = i;
			numberReturnNOf1 = numberOf1Calculun2(numberReturn);
		}
	}
	cout << numberReturn;
    return 0;
}
