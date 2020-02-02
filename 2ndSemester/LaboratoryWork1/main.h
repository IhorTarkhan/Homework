#include "workWithDatabases.h"

int main_Lab_2_1() {
    getFromMemory();
    getFromTextToMemory();
    getFromMemory();

    Train train = Train("1234", "ddd", FAST, Date(9, 9, 9, 9, 9000), Date(13, 13, 13, 10, 13), 5.7);
    changeInText(3, train);
}
