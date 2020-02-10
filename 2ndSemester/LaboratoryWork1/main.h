#include "workInConsole/standardUserWork/DatabaseConsole.h"
#include "workInConsole/demoWork/demon.h"
#include "workInConsole/benchmarkWork/bench.h"

int main_Lab_2_1() {
    bench<MemoryDatabase>();
    cout << endl;
    bench<TextDatabase>();
    cout << endl;
    bench<BinaryDatabase>();
}
