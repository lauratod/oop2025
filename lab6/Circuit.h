#pragma once
#include "Car.h"
#include "Weather.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Circuit
{
	int length;
	Weather weather;
	vector<Car*> cars;
	vector<Car*> DNF;
	vector<pair<Car*,float>> finished;
public:
	void SetLength(int n);
	void SetWeather(Weather w);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	~Circuit();

};

