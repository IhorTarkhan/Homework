#include "dadaStructures/Train.h"
#include "workWithDatabases.h"

int main_Lab_2_1() {
    Date arrive_1 = Date(0, 0, 0, 0, 1900);
    Date departure_1 = Date(1, 1, 1, 1, 1991);
    Date arrive_2 = Date(14, 29, 5, 12, 1804);
    Date departure_2 = Date(23, 59, 31, 12, 2019);

    Train train1 = Train("0001", "myName", NEARCITY, arrive_1, departure_1, 1.0);
    Train train2 = Train("0020", "yourName", INTERNATIONAL, arrive_2, departure_2, 1.5);

//    addInMemory();
//    addInMemory();
//    addInMemory();
    getFromText();

//    getFromMemory();

}
