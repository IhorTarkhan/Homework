#pragma once

#include "ConsoleInterface.h"

class DatabaseConsole {
public:
    template <typename Database>
    static void saveTrain() {
        ConsoleInterface::save__(Database::saveTrain);
    }

    template <typename Database>
    static void printTrains() {
        ConsoleInterface::print__(Database::getTrains);
    }

    template <typename Database>
    static void clearTrains() {
        ConsoleInterface::clear__(Database::clearTrains);
    }

    template <typename Database>
    static void changeTrain() {
        ConsoleInterface::change__(Database::getTrainsWithID, Database::changeTrain);
    }

    template <typename Database>
    static void deleteTrain() {
        ConsoleInterface::delete__(Database::getTrainsWithID, Database::deleteTrain);
    }

    template <typename Database>
    static void task1() {
        ConsoleInterface::task1__(Database::task1);
    }

    template <typename Database>
    static void task2() {
        ConsoleInterface::task2__(Database::task2);
    }

    template <typename Database>
    static void task3() {
        ConsoleInterface::task3__(Database::task3);
    }
};
