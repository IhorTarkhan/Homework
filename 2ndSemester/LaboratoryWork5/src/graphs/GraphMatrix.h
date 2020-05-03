#ifndef HOMEWORK_GRAPHMATRIX_H
#define HOMEWORK_GRAPHMATRIX_H

class GraphMatrix {
private:
    const string WHITE = "\u001B[30m";
    const string READ = "\u001B[31m";
    const string YELLOW = "\u001B[33m";

    vector<vector<int>> matrix;
    bool isDirected;

public:
    vector<vector<int>> getMatrix() {
        return matrix;
    }

    bool getDirected() {
        return isDirected;
    }

    GraphMatrix(int nVertices, bool isDirected) {
        if (nVertices < 0) throw invalid_argument("Incorrect number of vertex");
        matrix = vector<vector<int>>(nVertices, vector<int>(nVertices));
        this->isDirected = isDirected;
    }

    void addEdge(int v1, int v2, int value = 1) {
        if (v1 < 0) throw invalid_argument("Incorrect number of v1");
        if (v2 < 0) throw invalid_argument("Incorrect number of v1");
        if (value < 0) throw invalid_argument("Incorrect number of value");

        matrix[v1 - 1][v2 - 1] = value;
        if (v1 == v2) {
            return;
        }
        if (!isDirected) {
            matrix[v2 - 1][v1 - 1] = value;
        }
    }

    string toString() {
        string toReturn = YELLOW + "\t\t\t\tTo vertices:\n";
        toReturn += "\t\t\t\t" + READ;
        for (int j = 0; j < matrix.size(); ++j) {
            toReturn += to_string(j + 1) + "\t";
        }
        toReturn += "\n";

        for (int i = 0; i < matrix.size(); ++i) {
            toReturn += YELLOW + "From vertex " + READ + to_string(i + 1) + YELLOW + ":\t" + WHITE;
            for (int j = 0; j < matrix.size(); ++j) {
                toReturn += to_string(matrix[i][j]) + "\t";
            }
            toReturn += "\n";
        }
        return toReturn;
    }

    static GraphMatrix createRandomNotDirectedNoWeighted(int nVertices, int nEdge) {
        if (nEdge > (nVertices * (nVertices - 1)) / 2 + nVertices) throw invalid_argument("Incorrect number of edge");
        if (nEdge < 0) throw invalid_argument("Incorrect number of edge");
        if (nVertices < 0) throw invalid_argument("Incorrect number of vertex");

        GraphMatrix m(nVertices, false);
        for (int i = 0; i < nEdge; ++i) {
            int v1 = rand() % nVertices + 1;
            int v2 = rand() % nVertices + 1;
            bool endAdding = false;
            while (!endAdding) {
                if (m.getMatrix()[v1 - 1][v2 - 1] == 0) {
                    m.addEdge(v1, v2);
                    endAdding = true;
                } else {
                    v1 = rand() % nVertices + 1;
                    v2 = rand() % nVertices + 1;
                }
            }
        }
        return m;
    }

private:
    bool isConnectivity(vector<int> &checkedVertices) {
        bool isLeftUnchecked = false;
        for (int i = 0; i < checkedVertices.size(); ++i) {
            if (checkedVertices[i] == 1) {
                isLeftUnchecked = true;
                for (int j = 0; j < checkedVertices.size(); ++j) {
                    if (matrix[i][j] != 0 && checkedVertices[j] != 2) {
                        checkedVertices[j] = 1;
                    }
                }
                checkedVertices[i] = 2;
            }
        }

        if (isLeftUnchecked) {
            return isConnectivity(checkedVertices);
        } else {
            for (int i = 0; i < checkedVertices.size(); ++i) {
                if (checkedVertices[i] == 0) {
                    return false;
                }
            }
            return true;
        }
    }

public:
    bool isConnectivity() {
        vector<int> checkedVertices(matrix.size());
        checkedVertices[0] = 1;
        return isConnectivity(checkedVertices);
    }

private:
    vector<int> crawlDeepByNumber(int vertex, vector<int> &checkedVertices, vector<int> &deepList) {
        checkedVertices[vertex - 1] = 1;
        deepList.push_back(vertex);
        vector<pair<int, int>> connectedVerticesWithResponsibleWeights;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[vertex - 1][i] != 0) {
                if (checkedVertices[i] == 0) {
                    connectedVerticesWithResponsibleWeights.push_back(pair<int, int>(i + 1, matrix[vertex - 1][i]));
                }
            }
        }
        for (int i = 0; i < connectedVerticesWithResponsibleWeights.size(); ++i) {
            if (checkedVertices[i] == 1) {
                continue;
            }
            crawlDeepByNumber(connectedVerticesWithResponsibleWeights[i].first, checkedVertices, deepList);
        }
        return deepList;
    }

public:
    vector<int> crawlDeepByNumber(int vertex) {
        vector<int> checkedVertices(matrix.size());
        vector<int> deepList;
        return crawlDeepByNumber(vertex, checkedVertices, deepList);
    }

private:
    static bool compareByWeights(pair<int, int> i1, pair<int, int> i2) {
        return (i1.second < i2.second);
    }

    vector<int> crawlDeepByWeights(int vertex, vector<int> &checkedVertices, vector<int> &deepList) {
        checkedVertices[vertex - 1] = 1;
        deepList.push_back(vertex);
        vector<pair<int, int>> connectedVerticesWithResponsibleWeights;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[vertex - 1][i] != 0) {
                if (checkedVertices[i] == 0) {
                    connectedVerticesWithResponsibleWeights.push_back(pair<int, int>(i + 1, matrix[vertex - 1][i]));
                }
            }
        }
        sort(connectedVerticesWithResponsibleWeights.begin(), connectedVerticesWithResponsibleWeights.end(),
             compareByWeights);
        for (int i = 0; i < connectedVerticesWithResponsibleWeights.size(); ++i) {
            if (checkedVertices[i] == 1) {
                continue;
            }
            crawlDeepByNumber(connectedVerticesWithResponsibleWeights[i].first, checkedVertices, deepList);
        }
        return deepList;
    }

public:
    vector<int> crawlDeepByWeights(int vertex) {
        vector<int> checkedVertices(matrix.size());
        vector<int> deepList;
        return crawlDeepByNumber(vertex, checkedVertices, deepList);
    }
};

#endif
