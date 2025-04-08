#include "Fiat.h"

Fiat::Fiat() {
    fuelCapacity = 55;
    fuelConsumption = 6.7f;
    averageSpeed[(int)Weather::Rain] = 85;
    averageSpeed[(int)Weather::Sunny] = 100;
    averageSpeed[(int)Weather::Snow] = 65;
}

const char* Fiat::GetName() const {
    return "Fiat";
}
