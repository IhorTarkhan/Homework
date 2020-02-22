#ifndef HOMEWORK_AUTONOMOUS_H
#define HOMEWORK_AUTONOMOUS_H

#include <cstdlib>
#include <iostream>
#include <math.h>
#include "../Data/Position.h"

using namespace std;

class Autonomous {
private:
    const string _1ST_LEVEL_PRINTING = "\u001B[34m";    /// BLUE
    const string _2ND_LEVEL_PRINTING = "\u001B[33m";    /// YELLOW
    const string _3RG_LEVEL_PRINTING = "\u001B[35m";    /// VIOLET

    Position createRandomPosition() {
        const double max = 30;
        const double min = -30;
        const int accuracy = 6;

        Position position;
        position.x = (rand() % (int) ((max - min) * pow(10, accuracy))) / pow(10, accuracy) + min;
        position.y = (rand() % (int) ((max - min) * pow(10, accuracy))) / pow(10, accuracy) + min;
        position.z = (rand() % (int) ((max - min) * pow(10, accuracy))) / pow(10, accuracy) + min;
        return position;
    }

public:
    void demon() {
        Position position = createRandomPosition();
        cout << to_string(position.x) << " " << to_string(position.y) << " " << to_string(position.z) << endl;
    }

    void bench() {
        Position position = createRandomPosition();
        cout << to_string(position.x) << " " << to_string(position.y) << " " << to_string(position.z) << endl;
    }
};


#endif
