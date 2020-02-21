#ifndef HOMEWORK_DEMO_H
#define HOMEWORK_DEMO_H

Position createRandomPosition() {
    int max = 30;
    int min = -30;
    int accuracy = 6;

    Position position;
    position.x = (rand() % ((max - min) * (int) pow(10, accuracy))) / pow(10, accuracy) + min;
    position.y = (rand() % ((max - min) * (int) pow(10, accuracy))) / pow(10, accuracy) + min;
    position.z = (rand() % ((max - min) * (int) pow(10, accuracy))) / pow(10, accuracy) + min;
    return position;
}

void demon() {
    Position position = createRandomPosition();
    cout << to_string(position.x) << " " << to_string(position.y) << " " << to_string(position.z) << endl;
}

#endif
