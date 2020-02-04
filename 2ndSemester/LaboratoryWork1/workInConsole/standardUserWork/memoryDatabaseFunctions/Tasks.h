#pragma once

#include "../generalFunctions/Tasks.h"
#include "../../../databases/MemoryDatabase.h"

void task1InMemory() {
    task1In__(MemoryDatabase::task1InMemory);
}

void task2InMemory() {
    task2In__(MemoryDatabase::task2InMemory);
}

void task3InMemory() {
    task3In__(MemoryDatabase::task3InMemory);
}
