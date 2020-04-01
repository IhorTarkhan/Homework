#include <iostream>
#include "../LaboratoryWork1/dataStructures/Train.h"

using namespace std;

int main_Lab_2_3b() {
    cout << Train("1111", "name", Destination::INTERNATIONAL,
                  Date(12, 55, 25, 10, 1955),
                  Date(12, 55, 25, 10, 1955),
                  5.6).getInText();

    cout << endl;

    cout << Train("1111", "name", Destination::FAST,
                  Date(5, 5, 5, 5, 1995),
                  Date(5, 5, 5, 5, 1995),
                  5.6).getInText();
    return 0;
}
