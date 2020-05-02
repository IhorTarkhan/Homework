#ifndef HOMEWORK_CONVERTER_H
#define HOMEWORK_CONVERTER_H

#include "GraphMatrix.h"
#include "GraphList.h"

class Converter {
public:
    static GraphList toGraphList(GraphMatrix graphMatrix) {
        vector<vector<int>> matrix = graphMatrix.getMatrix();
        GraphList graphList(matrix.size(), graphMatrix.getDirected());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j <= ((graphMatrix.getDirected()) ? matrix.size() - 1 : i); ++j) {
                if (matrix[i][j] != 0) {
                    graphList.addEdge(i + 1, j + 1, matrix[i][j]);
                }
            }
        }
        return graphList;
    }

    static GraphMatrix toGraphMatrix(GraphList graphList) {
        vector<vector<pair<int, int>>> list = graphList.getMatrix();
        GraphMatrix graphMatrix(list.size(), graphList.getDirected());
        for (int i = 0; i < list.size(); ++i) {
            for (int j = 0; j < list[i].size(); ++j) {
                graphMatrix.addEdge(i + 1, list[i][j].first + 1, list[i][j].second);
            }
        }
        return graphMatrix;
    }
};

#endif
