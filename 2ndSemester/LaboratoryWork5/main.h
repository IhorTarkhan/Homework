#include "src/graphs/Converter.h"

int main_Lab_2_5() {
    GraphList g1 = GraphList::createRandomNotDirectedNoWeighted(4, 5);
//    GraphList g1(4, true);
    g1.addEdge(4, 3);
    cout << g1.toString();

    GraphMatrix g2 = Converter::toGraphMatrix(g1);
    cout << g2.toString();

    return 0;
}
