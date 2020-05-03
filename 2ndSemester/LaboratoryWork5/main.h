#include "src/Converter.h"

int main_Lab_2_5() {
    GraphList g1 = GraphList::createRandomNotDirectedNoWeighted(10, 27);
//    GraphMatrix g1(4, true);
//    g1.addEdge(4, 3);
    cout << g1.toString();
//    cout << g1.isConnectivity();

    vector<int> a = g1.distanceFromToEvery(1);

    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }

//    GraphMatrix g2 = Converter::toGraphMatrix(g1);
//    cout << g2.toString();

    return 0;
}
