#pragma once
#include "Car.h"
class BMW : public Car
{
public:
    BMW();
    const char* GetName() const override;//override suprascrie corect metoda din clasa de baza
};

