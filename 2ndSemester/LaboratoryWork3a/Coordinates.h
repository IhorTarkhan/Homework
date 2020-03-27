#ifndef HOMEWORK_COORDINATES_H
#define HOMEWORK_COORDINATES_H

class Coordinates {
private:
    double x;
    double y;
    double z;
    double distance;
public:
    Coordinates() = default;

    Coordinates(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
        distance = sqrt(x * x + y * y + z * z);
    }

    double getSortValue() {
        return distance;
    }

    string toString() {
        return "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ") distance = " + to_string(distance);
    }
};

#endif
