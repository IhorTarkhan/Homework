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

    bool getDirected() {
        return isDirected;
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

        for (int j = 0; j < matrix[v1 - 1].size(); ++j) {
            if (matrix[v1 - 1][j].first == v2 - 1) {
                return;
            }
        }

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

private:
    bool isConnectivity(vector<int> &checkedVertices) {
        bool isLeftUnchecked = false;
        for (int i = 0; i < checkedVertices.size(); ++i) {
            if (checkedVertices[i] == 1) {
                isLeftUnchecked = true;
                for (int j = 0; j < matrix[i].size(); ++j) {
                    if (checkedVertices[matrix[i][j].first] != 2) {
                        checkedVertices[matrix[i][j].first] = 1;
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
        for (int i = 0; i < matrix[vertex - 1].size(); ++i) {
            if (checkedVertices[i] == 0) {
                connectedVerticesWithResponsibleWeights.push_back(pair<int, int>(i + 1, matrix[vertex - 1][i].second));
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
        for (int i = 0; i < matrix[vertex - 1].size(); ++i) {
            if (checkedVertices[i] == 0) {
                connectedVerticesWithResponsibleWeights.push_back(pair<int, int>(i + 1, matrix[vertex - 1][i].second));
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

private:
    void distanceFromToEvery(int vertex, vector<int> &checkedVertices, vector<int> &distances) {
        checkedVertices[vertex - 1] = 1;

        vector<int> neighboring;
        for (int i = 0; i < matrix[vertex - 1].size(); ++i) {
            if (checkedVertices[matrix[vertex - 1][i].first] == 0) {
                neighboring.push_back(matrix[vertex - 1][i].first);
            }
            if (distances[matrix[vertex - 1][i].first] == -1) {
                distances[matrix[vertex - 1][i].first] = distances[vertex - 1] + matrix[vertex - 1][i].second;
            } else {
                if (distances[matrix[vertex - 1][i].first] > distances[vertex - 1] + matrix[vertex - 1][i].second) {
                    distances[matrix[vertex - 1][i].first] = distances[vertex - 1] + matrix[vertex - 1][i].second;
                }
            }
        }
        for (int i = 0; i < neighboring.size(); ++i) {
            distanceFromToEvery(neighboring[i] + 1, checkedVertices, distances);
        }

    }

public:
    vector<int> distanceFromToEvery(int vertex) {
        vector<int> checkedVertices(matrix.size());
        checkedVertices[vertex - 1] = 1;

        vector<int> distances(matrix.size(), -1);
        distances[vertex - 1] = 0;

        distanceFromToEvery(vertex, checkedVertices, distances);
        return distances;
    }
};

#endif
