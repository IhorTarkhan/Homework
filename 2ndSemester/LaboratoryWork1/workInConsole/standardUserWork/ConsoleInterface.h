#pragma once

#include "DatabaseConsole.h"

//class ConsoleInterface {
//public:
template<typename Database>
static void saveTrain() {
    DatabaseConsole::save__(Database::saveTrain);
}

template<typename Database>
static void printTrains() {
    DatabaseConsole::print__(Database::getTrains);
}

template<typename Database>
static void clearTrains() {
    DatabaseConsole::clear__(Database::clearTrains);
}

template<typename Database>
static void changeTrain() {
    DatabaseConsole::change__(Database::getTrainsWithID, Database::changeTrain);
}

template<typename Database>
static void deleteTrain() {
    DatabaseConsole::delete__(Database::getTrainsWithID, Database::deleteTrain);
}

template<typename Database>
static void task1() {
    DatabaseConsole::task1__(Database::task1);
}

template<typename Database>
static void task2() {
    DatabaseConsole::task2__(Database::task2);
}

template<typename Database>
static void task3() {
    DatabaseConsole::task3__(Database::task3);
}
//};
