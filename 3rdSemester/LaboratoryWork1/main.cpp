#include <iostream>
#include "List.h"
#include "ArrayList.h"

using namespace std;

int compareInt(int a, int b) {
    return a - b;
}

int main(int argc, char *argv[]) {
    cout << "Hello, world!" << endl;
    List<int> *list = new ArrayList<int>(compareInt);
    list->add(6);
    return 0;
}
