#include "Volvo.h"

Volvo::Volvo() {
    fuelCapacity = 80;
    fuelConsumption = 6.5f;
    averageSpeed[(int)Weather::Rain] = 70;
    averageSpeed[(int)Weather::Sunny] = 110;
    averageSpeed[(int)Weather::Snow] = 70;
}

const char* Volvo::GetName() const {
    return "Volvo";
}
