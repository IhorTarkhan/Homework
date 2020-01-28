#ifndef HOMEWORK_DATE_H
#define HOMEWORK_DATE_H


struct Date {
    int minute;
    int hour;
    int day;
    int month;
    int yar;

    Date(int minute, int hour, int day, int month, int yar) {
        this->minute = minute;
        this->hour = hour;
        this->day = day;
        this->month = month;
        this->yar = yar;
    }
};


#endif