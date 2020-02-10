#include "workInConsole/demoWork/demon.h"
#include "workInConsole/standardUserWork/DatabaseConsole.h"

int main_Lab_2_1() {
    BinaryDatabase::clearTrains();
    BinaryDatabase::saveTrain(createRandomTrain());
    BinaryDatabase::saveTrain(createRandomTrain());
    BinaryDatabase::saveTrain(createRandomTrain());
    cout << BinaryDatabase::getTrainsWithID();
}
