#include "workInConsole/demoWork/demon.h"
#include "workInConsole/standardUserWork/DatabaseConsole.h"

int main_Lab_2_1() {
    BinaryDatabase::refresh_file();
    cout << endl;
    BinaryDatabase::saveTrain(createRandomTrain());
    BinaryDatabase::saveTrain(createRandomTrain());
    BinaryDatabase::saveTrain(createRandomTrain());
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << BinaryDatabase::getTrains();
}
