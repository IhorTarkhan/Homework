#include "src/graphs/GraphMatrix.h"
#include "src/graphs/GraphList.h"

int main_Lab_2_5() {
    GraphMatrix g1 = GraphMatrix::createRandomNotDirectedNoWeighted(10, 20);
    cout << g1.toString();

    GraphList g2 = GraphList::createRandomNotDirectedNoWeighted(10, 20);
    cout << g2.toString();

    return 0;
}
