#pragma once

#include <iostream>

using namespace std;

struct Date {
    int hour;
    int minute;
    int day;
    int month;
    int year;

    Date() = default;

    Date(int hour, int minute, int day, int month, int year) {
        if (hour < 0 || hour >= 24)
            throw invalid_argument("incorrect hours");

        if (minute < 0 || minute >= 60) {
            throw invalid_argument("incorrect minutes");
        }

        if (day < 0 || day >= 32)
            throw invalid_argument("incorrect days");

        if (month < 0 || month > 12)
            throw invalid_argument("incorrect months");

        if (year < 0)
            throw invalid_argument("incorrect year");

        this->minute = minute;
        this->hour = hour;
        this->day = day;
        this->month = month;
        this->year = year;
    }

    string getInText() const {
        return ((hour >= 10) ? "" : "0") + to_string(hour) +
               ":" +
               ((minute >= 10) ? "" : "0") + to_string(minute) +
               " " +
               ((day >= 10) ? "" : "0") + to_string(day) +
               "/" +
               ((month >= 10) ? "" : "0") + to_string(month) +
               "/" +
               to_string(year);
    }
};
