#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
    Volvo();
    const char* GetName() const override;//override suprascrie corect metoda din clasa de baza
};

