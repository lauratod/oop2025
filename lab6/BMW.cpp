#include "BMW.h"

BMW::BMW() {
    fuelCapacity = 60;
    fuelConsumption = 8.5f;
    averageSpeed[(int)Weather::Rain] = 80;
    averageSpeed[(int)Weather::Sunny] = 140;
    averageSpeed[(int)Weather::Snow] = 70;
}

const char* BMW::GetName() const {
    return "BMW";
}
