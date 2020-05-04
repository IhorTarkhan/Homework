#ifndef HOMEWORK_INTERFASE_LAB_5_H
#define HOMEWORK_INTERFASE_LAB_5_H

#include "Converter.h"

class Interface_lab_5 {
private:
    GraphMatrix *graphMatrix;
    GraphList *graphList;

public:
    void dialog() {
        int n0 = 0;
        cout << "Available options:" << endl;
        cout << "Choice 1 : create new graph by Matrix" << endl;
        cout << "Choice 2 : output Matrix graph" << endl;
        cout << "Choice 3 : add new Edge" << endl;
        cout << "Choice 4 : create random generated Matrix graph" << endl;
        cout << "Choice 5 : is Matrix graph connectivity" << endl;
        cout << "Choice 6 : crawl deep by number" << endl;
        cout << "Choice 7 : crawl deep by weight" << endl;
        cout << "Choice 8 : get distance from requested vertex to every vertex" << endl;
        cout << endl;
        cout << "Available options:" << endl;
        cout << "Choice 11: create new graph by List" << endl;
        cout << "Choice 12: output List graph" << endl;
        cout << "Choice 13: add new Edge" << endl;
        cout << "Choice 14: create random generated List graph" << endl;
        cout << "Choice 15: is List graph connectivity" << endl;
        cout << "Choice 16: crawl deep by number" << endl;
        cout << "Choice 17: crawl deep by weight" << endl;
        cout << "Choice 18: get distance from requested vertex to every vertex" << endl;
        cout << endl;
        cout << "Choice 21: convert from Matrix graph to List graph" << endl;
        cout << "Choice 22: convert from List graph to Matrix graph" << endl;
        cout << "Your choice: ";
        int n;
        cin >> n;
        int nVertices;
        int nEdge;
        bool isDirected;
        int vertex1;
        int vertex2;
        int weight;
        vector<int> list;
        switch (n) {
            case 1:
                cout << "Enter nVertices: ";
                cin >> nVertices;
                cout << "isDirected (\'0\' or letters - not directed, other - directed): ";
                cin >> isDirected;
                graphMatrix = new GraphMatrix(nVertices, isDirected);
                cout << "Created!" << endl;
                break;
            case 2:
                cout << graphMatrix->toString();
                break;
            case 3:
                cout << "Enter vertex 1: ";
                cin >> vertex1;
                cout << "Enter vertex 2: ";
                cin >> vertex2;
                cout << "Enter weight (enter 1 for unweight graph): ";
                cin >> weight;
                graphMatrix->addEdge(vertex1, vertex2, weight);
                cout << "Added!" << endl;
                break;
            case 4:
                cout << "Enter number of vertex: ";
                cin >> nVertices;
                cout << "Enter number of edge: ";
                cin >> nEdge;
                graphMatrix = GraphMatrix::createRandomNotDirectedNoWeighted(nVertices, nEdge);
                cout << "Created!" << endl;
                break;
            case 5:
                if (graphMatrix->isConnectivity())
                    cout << "YES!!" << endl;
                else
                    cout << "NO :(" << endl;
                break;
            case 6:
                cout << "Enter vertex: ";
                cin >> vertex1;
                list = graphMatrix->crawlDeepByNumber(vertex1);
                for (int i = 0; i < graphMatrix->getMatrix().size(); ++i) {
                    cout << list[i] << " ";
                }
                cout << endl;
                break;
            case 7:
                cout << "Enter vertex: ";
                cin >> vertex1;
                list = graphMatrix->crawlDeepByWeights(vertex1);
                for (int i = 0; i < graphMatrix->getMatrix().size(); ++i) {
                    cout << list[i] << " ";
                }
                cout << endl;
                break;
            case 8:
                cout << "Enter vertex: ";
                cin >> vertex1;
                list = graphMatrix->distanceFromToEvery(vertex1);
                for (int i = 0; i < graphMatrix->getMatrix().size(); ++i) {
                    cout << i + 1 << "\t-\t" << list[i] << endl;
                }
                break;

            case 11:
                cout << "Enter nVertices: ";
                cin >> nVertices;
                cout << "isDirected (\'0\' or letters - not directed, other - directed): ";
                cin >> isDirected;
                graphList = new GraphList(nVertices, isDirected);
                cout << "Created!" << endl;
                break;
            case 12:
                cout << graphList->toString();
                break;
            case 13:
                cout << "Enter vertex 1: ";
                cin >> vertex1;
                cout << "Enter vertex 2: ";
                cin >> vertex2;
                cout << "Enter weight (enter 1 for unweight graph): ";
                cin >> weight;
                graphList->addEdge(vertex1, vertex2, weight);
                cout << "Added!" << endl;
                break;
            case 14:
                cout << "Enter number of vertex: ";
                cin >> nVertices;
                cout << "Enter number of edge: ";
                cin >> nEdge;
                graphList = GraphList::createRandomNotDirectedNoWeighted(nVertices, nEdge);
                cout << "Created!" << endl;
                break;
            case 15:
                if (graphList->isConnectivity())
                    cout << "YES!!" << endl;
                else
                    cout << "NO :(" << endl;
                break;
            case 16:
                cout << "Enter vertex: ";
                cin >> vertex1;
                list = graphList->crawlDeepByNumber(vertex1);
                for (int i = 0; i < graphList->getMatrix().size(); ++i) {
                    cout << list[i] << " ";
                }
                cout << endl;
                break;
            case 17:
                cout << "Enter vertex: ";
                cin >> vertex1;
                list = graphList->crawlDeepByWeights(vertex1);
                for (int i = 0; i < graphList->getMatrix().size(); ++i) {
                    cout << list[i] << " ";
                }
                cout << endl;
                break;
            case 18:
                cout << "Enter vertex: ";
                cin >> vertex1;
                list = graphList->distanceFromToEvery(vertex1);
                for (int i = 0; i < graphList->getMatrix().size(); ++i) {
                    cout << i + 1 << "\t-\t" << list[i] << endl;
                }
                break;

            case 21:
                graphList = Converter::toGraphList(graphMatrix);
                break;
            case 22:
                graphMatrix = Converter::toGraphMatrix(graphList);
                break;

            default:
                cout << "Error case" << endl;
                break;
        }
    }

    string demon() {
        const string BlueInConsole = "\u001B[34m";
        const string YellowInConsole = "\u001B[33m";
        const string StandardConsole = "\u001B[30m";

        GraphMatrix *graphMatrixDemo;
        GraphList *graphListDemo;
        vector<int> list;
        string demoResult;
/// -------------------------------------------------------------------------------------
        demoResult += BlueInConsole + "MATRIX graph" + StandardConsole + "\n";

        demoResult += "Creating new directed graph, with number of vertices = 5\n";
        graphMatrixDemo = new GraphMatrix(5, true);
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Output the graph:\n";
        demoResult += graphMatrixDemo->toString();
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Adding new edges:\n"
                      "(1 -> 2)\n"
                      "(1 -> 3)\n"
                      "(2 -> 3)\n"
                      "(4 -> 5)\n";
        graphMatrixDemo->addEdge(1, 2);
        graphMatrixDemo->addEdge(1, 3);
        graphMatrixDemo->addEdge(2, 3);
        graphMatrixDemo->addEdge(4, 5);
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Output the graph:\n";
        demoResult += graphMatrixDemo->toString();
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Is graph connectivity? - ";
        if (graphMatrixDemo->isConnectivity()) {
            demoResult += YellowInConsole + "YES" + StandardConsole + "\n";
        } else {
            demoResult += YellowInConsole + "NO" + StandardConsole + "\n";
        }

        demoResult += "Crawl deep by number from vertex 1\n";
        list = graphMatrixDemo->crawlDeepByNumber(1);
        for (int i = 0; i < graphMatrixDemo->getMatrix().size(); ++i) {
            demoResult += to_string(list[i]) + " ";
        }
        demoResult += "\n" + YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Crawl deep by weight from vertex 1\n";
        list = graphMatrixDemo->crawlDeepByWeights(1);
        for (int i = 0; i < graphMatrixDemo->getMatrix().size(); ++i) {
            demoResult += to_string(list[i]) + " ";
        }
        demoResult += "\n" + YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Get distance from vertex 1 to every vertex\n";
        list = graphMatrixDemo->distanceFromToEvery(1);
        for (int i = 0; i < graphMatrixDemo->getMatrix().size(); ++i) {
            demoResult += to_string(i + 1) + "\t-\t" + to_string(list[i]) + "\n";
        }
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult +=
                "Creating new random not-directed graph, with number of vertices = 5, number of vertices = 12\n";
        graphMatrixDemo = GraphMatrix::createRandomNotDirectedNoWeighted(5, 12);
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Output the graph:\n";
        demoResult += graphMatrixDemo->toString();
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Is graph connectivity? - ";
        if (graphMatrixDemo->isConnectivity()) {
            demoResult += YellowInConsole + "YES" + StandardConsole + "\n";
        } else {
            demoResult += YellowInConsole + "NO" + StandardConsole + "\n";
        }

        demoResult += "Crawl deep by number from vertex 1\n";
        list = graphMatrixDemo->crawlDeepByNumber(1);
        for (int i = 0; i < graphMatrixDemo->getMatrix().size(); ++i) {
            demoResult += to_string(list[i]) + " ";
        }
        demoResult += "\n" + YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Crawl deep by weight from vertex 1\n";
        list = graphMatrixDemo->crawlDeepByWeights(1);
        for (int i = 0; i < graphMatrixDemo->getMatrix().size(); ++i) {
            demoResult += to_string(list[i]) + " ";
        }
        demoResult += "\n" + YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Get distance from vertex 1 to every vertex\n";
        list = graphMatrixDemo->distanceFromToEvery(1);
        for (int i = 0; i < graphMatrixDemo->getMatrix().size(); ++i) {
            demoResult += to_string(i + 1) + "\t-\t" + to_string(list[i]) + "\n";
        }
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

/// -------------------------------------------------------------------------------------
        demoResult += BlueInConsole + "LIST graph" + StandardConsole + "\n";

        demoResult += "Creating new directed graph, with number of vertices = 5\n";
        graphListDemo = new GraphList(5, true);
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Output the graph:\n";
        demoResult += graphListDemo->toString();
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Adding new edges:\n"
                      "(1 -> 2)\n"
                      "(1 -> 3)\n"
                      "(2 -> 3)\n"
                      "(4 -> 5)\n";
        graphListDemo->addEdge(1, 2);
        graphListDemo->addEdge(1, 3);
        graphListDemo->addEdge(2, 3);
        graphListDemo->addEdge(4, 5);
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Output the graph:\n";
        demoResult += graphListDemo->toString();
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Is graph connectivity? - ";
        if (graphListDemo->isConnectivity()) {
            demoResult += YellowInConsole + "YES" + StandardConsole + "\n";
        } else {
            demoResult += YellowInConsole + "NO" + StandardConsole + "\n";
        }

        demoResult += "Crawl deep by number from vertex 1\n";
        list = graphListDemo->crawlDeepByNumber(1);
        for (int i = 0; i < graphListDemo->getMatrix().size(); ++i) {
            demoResult += to_string(list[i]) + " ";
        }
        demoResult += "\n" + YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Crawl deep by weight from vertex 1\n";
        list = graphListDemo->crawlDeepByWeights(1);
        for (int i = 0; i < graphListDemo->getMatrix().size(); ++i) {
            demoResult += to_string(list[i]) + " ";
        }
        demoResult += "\n" + YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Get distance from vertex 1 to every vertex\n";
        list = graphListDemo->distanceFromToEvery(1);
        for (int i = 0; i < graphListDemo->getMatrix().size(); ++i) {
            demoResult += to_string(i + 1) + "\t-\t" + to_string(list[i]) + "\n";
        }
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult +=
                "Creating new random not-directed graph, with number of vertices = 5, number of vertices = 12\n";
        graphListDemo = GraphList::createRandomNotDirectedNoWeighted(5, 12);
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Output the graph:\n";
        demoResult += graphListDemo->toString();
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Is graph connectivity? - ";
        if (graphListDemo->isConnectivity()) {
            demoResult += YellowInConsole + "YES" + StandardConsole + "\n";
        } else {
            demoResult += YellowInConsole + "NO" + StandardConsole + "\n";
        }

        demoResult += "Crawl deep by number from vertex 1\n";
        list = graphListDemo->crawlDeepByNumber(1);
        for (int i = 0; i < graphListDemo->getMatrix().size(); ++i) {
            demoResult += to_string(list[i]) + " ";
        }
        demoResult += "\n" + YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Crawl deep by weight from vertex 1\n";
        list = graphListDemo->crawlDeepByWeights(1);
        for (int i = 0; i < graphListDemo->getMatrix().size(); ++i) {
            demoResult += to_string(list[i]) + " ";
        }
        demoResult += "\n" + YellowInConsole + "Done" + StandardConsole + "\n";

        demoResult += "Get distance from vertex 1 to every vertex\n";
        list = graphListDemo->distanceFromToEvery(1);
        for (int i = 0; i < graphListDemo->getMatrix().size(); ++i) {
            demoResult += to_string(i + 1) + "\t-\t" + to_string(list[i]) + "\n";
        }
        demoResult += YellowInConsole + "Done" + StandardConsole + "\n";

/// -------------------------------------------------------------------------------------
        demoResult += BlueInConsole + "CONVERTER" + StandardConsole + "\n";

        demoResult += "Output the LIST graph:\n";
        demoResult += graphListDemo->toString();

        demoResult += "Convert LIST graph in MATRIX graph\n";
        graphMatrixDemo = Converter::toGraphMatrix(graphListDemo);

        demoResult += "Output the MATRIX graph:\n";
        demoResult += graphMatrixDemo->toString();

        demoResult += "Convert MATRIX graph in LIST graph\n";
        graphListDemo = Converter::toGraphList(graphMatrixDemo);

        demoResult += "Output the LIST graph:\n";
        demoResult += graphListDemo->toString();

        demoResult += "Convert LIST graph in MATRIX graph\n";
        graphMatrixDemo = Converter::toGraphMatrix(graphListDemo);

        demoResult += "Output the MATRIX graph:\n";
        demoResult += graphMatrixDemo->toString();

        demoResult += "\n";
        return demoResult;
    }

    void benchmark() {
        cout << "Enter the time in milliseconds"
                " that you want to increase the planingDuration of the demonstration iterations (without display) - ";
        long planingDuration;
        cin >> planingDuration;
        long numberOfIterations = 1;

        auto fullStart = high_resolution_clock::now();

        auto start = high_resolution_clock::now();
        auto stop = high_resolution_clock::now();
        auto realDuration = duration_cast<milliseconds>(stop - start);
        while (realDuration.count() < planingDuration) {
            start = high_resolution_clock::now();
            for (long i = 0; i < numberOfIterations; ++i) {
                demon();
            }
            stop = high_resolution_clock::now();
            realDuration = duration_cast<milliseconds>(stop - start);
            cout << numberOfIterations << " iterations - " << realDuration.count() << " milliseconds" << endl;
            numberOfIterations *= 2;
        }

        auto fullStop = high_resolution_clock::now();
        cout << "Full time is "
             << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " milliseconds" << endl;

    }
};

#endif
