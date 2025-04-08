#include "Circuit.h"
#include "Car.h"
#include "Weather.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

void Circuit::SetLength(int n)
{
	length = n;
	}


void Circuit::SetWeather(Weather w)
{
	weather = w;

	}
void Circuit::AddCar(Car* car)
{
	cars.push_back(car);
	}


void Circuit::Race()
{
	for (Car* car : cars)
	{
		float distance = length;
		float maxDistance = (car->GetFuelCapacity() / car->GetFuelConsumption()) * 100;
		if (maxDistance < distance)
		{
			DNF.push_back(car);
		}
		else
		{

			float time=distance/ car->GetAverageSpeed(weather);
			finished.push_back({ car,time });
		}
	}
	}

void Circuit::ShowFinalRanks()
{
	int n = finished.size();
	int ok;
	do
	{
		ok = 0;
		for (int i = 0; i <= n - 2; i++)
		{
			if (finished[i].second > finished[i + 1].second)
			{
				swap(finished[i], finished[i + 1]); ok = 1;

			}
		}
	} while (ok == 1);
	for (int i = 0; i <= n - 1; i++)
	{
		printf("%s %.2f \n", finished[i].first->GetName(), finished[i].second);
	}
	}

void Circuit::ShowWhoDidNotFinish()
{
	int n = DNF.size();
	for (int i = 0; i <= n - 1; i++)
	{
		printf("%s -DNF \n", DNF[i]->GetName());
	}
	}


Circuit::~Circuit() {
		for (Car* car : cars) {
			delete car;
		}
	}


