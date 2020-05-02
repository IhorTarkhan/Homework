#ifndef HOMEWORK_GRAPHLIST_H
#define HOMEWORK_GRAPHLIST_H

class GraphList {
private:
    const string WHITE = "\u001B[30m";
    const string READ = "\u001B[31m";
    const string YELLOW = "\u001B[33m";

    vector<vector<pair<int, int>>> matrix;
    bool isDirected;

public:
    vector<vector<pair<int, int>>> getMatrix() {
        return matrix;
    }

    GraphList(int nVertices, bool isDirected) {
        if (nVertices < 0) throw invalid_argument("Incorrect number of vertex");
        matrix = vector<vector<pair<int, int>>>(nVertices);
        this->isDirected = isDirected;
    }

    void addEdge(int v1, int v2, int value = 1) {
        if (v1 < 0) throw invalid_argument("Incorrect number of v1");
        if (v2 < 0) throw invalid_argument("Incorrect number of v1");
        if (value < 0) throw invalid_argument("Incorrect number of value");

        matrix[v1 - 1].push_back(pair<int, int>(v2 - 1, value));
        if (v1 == v2) {
            return;
        }
        if (!isDirected) {
            matrix[v2 - 1].push_back(pair<int, int>(v1 - 1, value));
        }
    }

    string toString() {
        string toReturn = "";

        for (int i = 0; i < matrix.size(); ++i) {
            toReturn += READ + to_string(i + 1) + WHITE + ": ";
            for (int j = 0; j < matrix[i].size(); ++j) {
                toReturn +=
                        to_string(matrix[i][j].first + 1) + "(" + YELLOW + to_string(matrix[i][j].second) + WHITE +
                        ") ";
            }
            toReturn += "\n";
        }
        return toReturn;
    }

    static GraphList createRandomNotDirectedNoWeighted(int nVertices, int nEdge) {
        if (nEdge > (nVertices * (nVertices - 1)) / 2 + nVertices) throw invalid_argument("Incorrect number of edge");
        if (nEdge < 0) throw invalid_argument("Incorrect number of edge");
        if (nVertices < 0) throw invalid_argument("Incorrect number of vertex");

        GraphList m(nVertices, false);
        for (int i = 0; i < nEdge; ++i) {
            int v1 = rand() % nVertices + 1;
            int v2 = rand() % nVertices + 1;
            bool endAdding = false;
            while (!endAdding) {
                bool isEdgeExisted = false;
                for (int j = 0; j < m.getMatrix()[v1 - 1].size(); ++j) {
                    if (m.getMatrix()[v1 - 1][j].first == v2 - 1) {
                        isEdgeExisted = true;
                    }
                }
                if (isEdgeExisted) {
                    v1 = rand() % nVertices + 1;
                    v2 = rand() % nVertices + 1;
                } else {
                    m.addEdge(v1, v2);
                    endAdding = true;
                }
            }

        }
        return m;
    }
};

#endif
