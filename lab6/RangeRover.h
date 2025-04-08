#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
    RangeRover();
    const char* GetName() const override;//override suprascrie corect metoda din clasa de baza
};

