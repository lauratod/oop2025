#pragma once
#include "Car.h"
class Fiat : public Car
{
public:
    Fiat();
    const char* GetName() const override;//override suprascrie corect metoda din clasa de baza
};

