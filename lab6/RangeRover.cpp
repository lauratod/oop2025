#include "RangeRover.h"

RangeRover::RangeRover()
{
    fuelCapacity = 80;
    fuelConsumption = 9.5f;
    averageSpeed[(int)Weather::Rain] = 90;
    averageSpeed[(int)Weather::Sunny] = 120;
    averageSpeed[(int)Weather::Snow] = 70;
}

const char* RangeRover::GetName() const {
    return "RangeRover";
}
