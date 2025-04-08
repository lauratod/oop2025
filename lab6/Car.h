#pragma once
#include "Weather.h"

class Car {
protected://poate fi accesat doar din clasa respectiva sau din cea derivata
    float fuelCapacity;
    float fuelConsumption;
    float averageSpeed[3]; // index 0: Rain, 1: Sunny, 2: Snow

public:
    virtual const char* GetName() const = 0;//permite polimorfismul
    float GetFuelCapacity() const;
    float GetFuelConsumption() const;
    float GetAverageSpeed(Weather w) const;
};
