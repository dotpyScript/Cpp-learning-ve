// sensor.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sensor.h"

int readGasSensor() {
    std::srand(std::time(0));  // Seed random generator
    int gasLevel = rand() % 100;  // Simulated gas level between 0–99
    return gasLevel;
}
