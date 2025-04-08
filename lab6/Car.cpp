#include "Car.h"
#include "Circuit.h"
#include "Weather.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

float Car:: GetFuelCapacity() const { return fuelCapacity; }
float Car::GetFuelConsumption() const { return fuelConsumption; }
float Car::GetAverageSpeed(Weather w) const { return averageSpeed[(int)w]; }