#pragma once
#include "Car.h"
class Seat : public Car
{
public:
    Seat();
    const char* GetName() const override;//override suprascrie corect metoda din clasa de baza
};

