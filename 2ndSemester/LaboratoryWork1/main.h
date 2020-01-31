#include <iostream>
#include "dadaStructures/Train.h"
#include "dadaStructures/SaveToFileCONSTANTS.h"
#include "lib/DataBase.h"
#include <fstream>

int main_Lab_2_1() {
    addToFile("../2ndSemester/LaboratoryWork1/test.txt",
              Train("0001", "myName", NEARCITY,
                    Date(0, 0, 0, 0, 1900),
                    Date(1, 1, 1, 1, 1991),
                    1.0));
}
