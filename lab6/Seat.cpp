#include "Seat.h"

Seat::Seat() {
    fuelCapacity = 45;
    fuelConsumption = 5.8f;
    averageSpeed[(int)Weather::Rain] = 50;
    averageSpeed[(int)Weather::Sunny] = 150;
    averageSpeed[(int)Weather::Snow] = 40;
}

const char* Seat::GetName() const {
    return "Seat";
}
