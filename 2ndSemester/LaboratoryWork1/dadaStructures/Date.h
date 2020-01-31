#ifndef HOMEWORK_DATE_H
#define HOMEWORK_DATE_H

#include<sstream>

using namespace std;

struct Date {
    int hour;
    int minute;
    int day;
    int month;
    int yar;

    Date(int minute, int hour, int day, int month, int yar) {
        if (minute < 0 || minute >= 60)
            throw invalid_argument("incorrect minutes");

        if (minute < 0 || hour >= 24)
            throw invalid_argument("incorrect hours");

        if (minute < 0 || day >= 32)
            throw invalid_argument("incorrect days");

        if (minute < 0 || month >= 12)
            throw invalid_argument("incorrect months");

        if (yar < 1804)
            throw invalid_argument("trains don't exist yet");

        this->minute = minute;
        this->hour = hour;
        this->day = day;
        this->month = month;
        this->yar = yar;
    }

    string toString() {
        return to_string(hour) + ":" + to_string(minute) + " "
               + to_string(day) + "/" + to_string(month) + "/" + to_string(yar);
    }
};

#endif