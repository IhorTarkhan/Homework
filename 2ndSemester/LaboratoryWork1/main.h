#include "workInConsole/standardUserWork/memoryDatabaseFunctions/Standard.h"
#include "workInConsole/standardUserWork/textDatabaseFunctions/Standard.h"

#include "workInConsole/standardUserWork/memoryDatabaseFunctions/Tasks.h"
#include "workInConsole/standardUserWork/textDatabaseFunctions/Tasks.h"

#include "workInConsole/demoWork/demo.h"

int main_Lab_2_1() {
    Train t = createRandomTrain();
    saveTrainInMemory(t);
    printMemory();

}
