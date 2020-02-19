#ifndef HOMEWORK_POSITION_H
#define HOMEWORK_POSITION_H

class Position {
public:
    double x;
    double y;
    double z;

    Position() = default;

    Position(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

#endif
