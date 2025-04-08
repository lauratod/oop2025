#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Car.h"
#include "BMW.h"
#include "Weather.h"
#include "Volvo.h"
#include "Circuit.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"

using namespace std;

int main()
{
	Circuit c;
	c.SetLength(800);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel
	return 0;
}