#ifndef HOMEWORK_FIGURE_H
#define HOMEWORK_FIGURE_H


#include <regex>
#include <cmath>


class Point {
private:
    double x, y;
public:
    Point() = default;

    Point(double x, double y) : x(x), y(y) {}

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
};


class Figure {
private:
    Point *coordinates;
    int numberOfVertex;
public:
    Figure(Point *coordinates, int numberOfVertex) : coordinates(coordinates), numberOfVertex(numberOfVertex) {}

    Point *getCoordinates() const {
        return coordinates;
    }

    int getNumberOfVertex() const {
        return numberOfVertex;
    }
};


Figure initializeFigure() {
    Point *points = new Point[3];
    points[0] = Point(1, 2);
    points[1] = Point(4, 5);
    points[2] = Point(7, 8);

    Figure figure(points, 3);
    return figure;
}

/**
 * <h1>First of all initialize your figure like this</h1>
 */
Figure figure = initializeFigure();

/**
 * Function to check figure condition, using as element comparator
 * {@code isCondition()}
 * @param element is int which checked
 * @return bool if figure corresponds to the value
 * in this case is figure vertex equal 5
 */
bool isCondition(Figure element) {
    return element.getNumberOfVertex() == 5;
}

/**
 * Function to convert Figure in text format
 * {@code toStringInt()}
 * @param element is Figure which converted to string
 * @return Figure in text format
 */
std::string toString(Figure element) {
    std::string result = "[";
    Point *vertexes = element.getCoordinates();
    for (int i = 0; i < element.getNumberOfVertex(); ++i) {
        result += "(" +
                  std::to_string(vertexes[i].getX()) + ", " +
                  std::to_string(vertexes[i].getY()) + ") ,";
    }
    if (element.getNumberOfVertex() != 0) {
        result = result.substr(0, result.size() - 2);
    }
    result += "]";
    return result;
}

/**
 * additional function to realise other compare functions
 * @return length between two points
 */
double getLength(Point p1, Point p2) {
    return pow(pow(p1.getX() - p2.getX(), 2) +
               pow(p1.getY() - p2.getY(), 2), 0.5);
}

/**
 * implement functions to check Square
 */
bool isEqualSquare(Figure element) {
    double elementSquare = 0;
    Point *vertexes = element.getCoordinates();
    for (int i = 0; i < element.getNumberOfVertex() - 1; ++i) {
        elementSquare +=
                (vertexes[i].getX() - vertexes[i + 1].getX()) * (vertexes[i].getY() + vertexes[i + 1].getY()) / 2;
    }
    elementSquare +=
            (vertexes[element.getNumberOfVertex() - 1].getX() - vertexes[0].getX()) *
            (vertexes[element.getNumberOfVertex() - 1].getY() + vertexes[0].getY()) / 2;
    return elementSquare - 6.5 < 0.1;
}

/**
 * implement functions to check right figure
 */
bool isRight(Figure element) {
    Point *vertexes = element.getCoordinates();
    double edgeLength = getLength(vertexes[element.getNumberOfVertex() - 1], vertexes[0]);
    for (int i = 0; i < element.getNumberOfVertex() - 1; ++i) {
        double edgeIterableLength = getLength(vertexes[i], vertexes[i + 1]);
        if (edgeLength - edgeIterableLength > 0.01)
            return false;
    }
    return true;
}

/**
 * implement functions to check Rectangular figure
 */
bool isContainRightAngle(Figure element) {
    Point *vertexes = element.getCoordinates();
    int vertexNumber = element.getNumberOfVertex();
    for (int i = 0; i < vertexNumber + 3; ++i) {
        if (
                pow(getLength(vertexes[i], vertexes[(i + 1) % vertexNumber]), 2) +
                pow(getLength(vertexes[i + 1], vertexes[(i + 2) % vertexNumber]), 2) -
                pow(getLength(vertexes[i], vertexes[(i + 2) % vertexNumber]), 2)
                > 0.01
                ) {
            return true;
        }
    }
    return false;
}

#endif
